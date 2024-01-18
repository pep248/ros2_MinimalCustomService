# Import the necessary launch libraries
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Launch the service server node
        Node(
            package='minimal_service',
            executable='minimal_service_server',
            output='screen'
        ),

        # Launch the service client node
        Node(
            package='minimal_service',
            executable='minimal_service_client',
            output='screen'
        ),
    ])
