#include "rclcpp/rclcpp.hpp"
#include "telemetry_bridge/StateMonitorNode.hpp"
#include "telemetry_bridge/UdpBridgeNode.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto udp_node = std::make_shared<telemetry_bridge::UdpBridgeNode>();

    rclcpp::NodeOptions monitor_opts;
    monitor_opts.parameter_overrides({
        rclcpp::Parameter("use_sim_time",
            udp_node->get_parameter("use_sim_time").as_bool())
    });
    auto monitor_node = std::make_shared<telemetry_bridge::StateMonitorNode>(monitor_opts);

    rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 8);
    executor.add_node(udp_node);
    executor.add_node(monitor_node);

    executor.spin();

    rclcpp::shutdown();
    return 0;
}

