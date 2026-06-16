from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    bridge_config = PathJoinSubstitution([FindPackageShare("telemetry_bridge"), "config", "bridge_params.yaml"])
    clock_config = PathJoinSubstitution([FindPackageShare("sim_clock"), "config", "clock_params.yaml"])
    tf_config = PathJoinSubstitution([FindPackageShare("spacecraft_tf"), "config", "tf_params.yaml"])
    thruster_config = PathJoinSubstitution([FindPackageShare("thruster_control"), "config", "thruster_mix.yaml"])
    cv_config = PathJoinSubstitution([FindPackageShare("cv_pipeline"), "config", "cv_params.yaml"])

    return LaunchDescription([

        # Armstrong telemetry bridge
        Node(
            package="telemetry_bridge",
            executable="udp_bridge",
            namespace="armstrong",
            name="udp_bridge_node",
            parameters=[bridge_config, {"udp_port": 8091, "use_sim_time": True}], 
        ),

        # Edison telemetry bridge
        Node(
            package="telemetry_bridge",
            executable="udp_bridge",
            namespace="edison",
            name="udp_bridge_node",
            parameters=[bridge_config, {"udp_port": 8092, "use_sim_time": True}],
        ),

        # Simulation clock
        Node(
            package="sim_clock",
            executable="sim_clock_node",
            name="sim_clock_node",
            parameters=[clock_config],
            # NOTE: sim_clock itself must NOT have use_sim_time=True
            # it runs on wall clock to drive everyone else
        ),

        # TF2 frame broadcaster
        Node(
            package="spacecraft_tf",
            executable="spacecraft_tf_node",
            name="spacecraft_tf_node",
            parameters=[tf_config, {"use_sim_time": True}],
        ),

        # Thruster controller
        Node(
            package="thruster_control",
            executable="thruster_control_node",
            name="thruster_control_node",
            parameters=[thruster_config, {"use_sim_time": True}],
        ),

        # Basilisk camera bridge
        Node(
            package="cv_pipeline",
            executable="basilisk_camera_node",
            name="basilisk_camera_node",
            parameters=[cv_config, {"use_sim_time": True}],
        ),

        # CV inference pipeline
        Node(
            package="cv_pipeline",
            executable="cv_pipeline_node",
            name="cv_pipeline_node",
            parameters=[cv_config, {"use_sim_time": True}],
        ),
    ])