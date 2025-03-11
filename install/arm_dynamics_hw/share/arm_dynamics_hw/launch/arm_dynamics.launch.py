import os
import yaml
import logging
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.actions import ExecuteProcess, IncludeLaunchDescription, RegisterEventHandler,SetEnvironmentVariable
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import xml.etree.ElementTree as ET
from pathlib import Path
from launch.actions import DeclareLaunchArgument
from launch.substitutions import PythonExpression
from uaclient.api.u.security.package_manifest.v1 import package_manifest

def check_file_exists(file_path, file_type):
    """检查文件是否存在"""
    if not os.path.exists(file_path):
        raise FileNotFoundError(f"{file_type}文件不存在: {file_path}")
    return file_path

# 1. 获取并验证文件路径
gazebo_tuner_package_path = get_package_share_directory('arm_dynamics_hw')

config_file = check_file_exists(
    # os.path.join(gazebo_tuner_package_path, 'config', 'RC_config.yaml'),
    os.path.join(gazebo_tuner_package_path, 'config', 'RC_config.yaml'),
    "Configuration"
)



def validate_config(config_data):
    """验证配置文件的完整性"""
    required_fields = ['coral_config']
    for field in required_fields:
        if field not in config_data:
            raise ValueError(f"配置文件缺少必要字段: {field}")

    required_coral_fields = ['robot_name', 'base_pos', 'base_rpy', 'paused']
    for field in required_coral_fields:
        if field not in config_data['coral_config']:
            raise ValueError(f"coral_config 缺少必要字段: {field}")


def generate_launch_description():
    try:
        urdf_file = os.path.join(get_package_share_directory("arm_dynamics_hw"), "urdf", "FinalARM/urdf/FinalARM.urdf")
        world_file = os.path.join(get_package_share_directory("arm_dynamics_hw"), "worlds", "empty_world.world")
        # 2. 加载和验证配置
        try:
            with open(config_file, 'r') as f:
                config_data = yaml.safe_load(f)
            validate_config(config_data)
        except yaml.YAMLError as e:
            raise ValueError(f"配置文件格式错误: {e}")

        # 3. 提取配置数据
        robot_name = config_data['coral_config']['robot_name']
        default_base_pos = config_data['coral_config']['base_pos']
        default_base_rpy = config_data['coral_config']['base_rpy']
        paused = config_data['coral_config']['paused']

        # 4. 创建Gazebo启动配置
        gazebo = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
            ]),
            launch_arguments={
                '-world': world_file,
                'pause': paused,
                'physics': 'true',
            }.items()
        )

        # 5. 解析URDF并创建robot state publisher
        try:
            tree = ET.parse(urdf_file)
            root = tree.getroot()
            urdf_string = ET.tostring(root, encoding='unicode')
        except ET.ParseError as e:
            raise ValueError(f"URDF文件解析错误: {e}")

        params = {'robot_description': urdf_string}
        robot_description_publisher = Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[params]
        )

        # 6. 创建其他节点
        node_effort_command_publisher = Node(
            package='arm_dynamics_hw',
            executable='arm_dynamics_hw',
            output='screen'
        )

        # 6. 创建其他节点
        node_human_rl_controller = Node(
            package='human_rl_controller',
            executable='human_rl_controller',
            output='screen'
        )

        spawn_entity = Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=[
                '-topic', '/robot_description',  # 修正topic参数
                '-entity', robot_name
                # '-x', str(default_base_pos[0]),
                # '-y', str(default_base_pos[1]),
                # '-z', str(default_base_pos[2]),
                # '-R', str(default_base_rpy[0]),
                # '-P', str(default_base_rpy[1]),
                # '-Y', str(default_base_rpy[2]),
                # *cmd_args  # 添加关节初始位置参数
            ],
            output='screen'
        )

        load_joint_state_broadcaster = ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'active',
                 'joint_state_broadcaster'],
            output='screen'
        )

        load_joint_effort_controller = ExecuteProcess(
            cmd=['ros2', 'control', 'load_controller', '--set-state', 'active',
                 'effort_controller'],
            output='screen'
        )

        # 7. 返回启动描述
        return LaunchDescription([
            # urdf_file_arg,
            # world_file_arg,
            robot_description_publisher,
            load_joint_state_broadcaster,
            load_joint_effort_controller,
            gazebo,
            spawn_entity,
            node_effort_command_publisher,
            # node_human_rl_controller
        ])

    except Exception as e:
        logging.error(f"启动文件生成错误: {str(e)}")
        raise

