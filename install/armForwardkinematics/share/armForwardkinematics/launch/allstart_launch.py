from launch_ros.substitutions import FindPackageShare
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
import os
from ament_index_python.packages import get_package_share_directory
import yaml
from launch import LaunchDescription

def generate_launch_description():
    # 配置、参数等设置
    
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([FindPackageShare('armForwardkinematics'), 'launch', 'armInv.py'])
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([FindPackageShare('arm_dynamics_hw'), 'launch', 'arm_dynamics.launch.py'])
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([FindPackageShare('armend_visualize'), 'launch', 'visual_launch.py'])
            )
        ),    
        # 节点、其他 launch 文件等
    ])