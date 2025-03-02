import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
import yaml

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('armForwardkinematics'),
        'config',
        'config.yaml'
    )

    if not os.path.exists(config_path):
        raise FileNotFoundError(f"Config file not found: {config_path}")

    with open(config_path, 'r') as f:
        config = yaml.safe_load(f)

    return LaunchDescription([
        # node加入写法
        Node(
            package='armForwardkinematics',
            executable='pino_armkine_node', 
            parameters=[
                config['pino_armkine_node']['ros__parameters']
            ],
            # output='screen',
            # arguments=['--ros-args', '--log-level', 'DEBUG']
        )
    ])