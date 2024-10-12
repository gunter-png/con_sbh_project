from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from launch.substitutions import FindExecutable


def generate_launch_description():
    ld = LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='sim'
        ),
        Node(
            package='con_sbh_project',
            executable='cylinder_draw',
            output='screen',
        ),
        Node(
            package='con_sbh_project',
            executable='staircase_draw',
            output='screen',
        ),
    ])
    ld.add_action(
        ExecuteProcess(
            cmd=[[
                FindExecutable(name='ros2'),
                " service call ",
                "/spawn ",
                "turtlesim/srv/Spawn ",
                "\"{x: 5.794445, y: 5.444445, theta: 0.0, name: 'turtle2'}\""
            ]],
            shell=True,
        )
    )
    ld.add_action(
        ExecuteProcess(
            cmd=[[
                FindExecutable(name='ros2'),
                " service call ",
                "/spawn ",
                "turtlesim/srv/Spawn ",
                "\"{x: 5.544555, y: 6.854445, theta: 0.0, name: 'turtle3'}\""
            ]],
            shell=True,
        )
    )
    ld.add_action(
        ExecuteProcess(
            cmd=[[
                FindExecutable(name='ros2'),
                " service call ",
                "/spawn ",
                "turtlesim/srv/Spawn ",
                "\"{x: 5.544555, y: 8.354445, theta: 0.0, name: 'turtle4'}\""
            ]],
            shell=True,
        )
    )
    return ld