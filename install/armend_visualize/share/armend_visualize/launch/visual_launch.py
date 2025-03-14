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
    # 配置、参数等设置
    
    return LaunchDescription([
        Node(
            package='armend_visualize',
            executable='main', 
            )
        # 节点、其他 launch 文件等
    ])