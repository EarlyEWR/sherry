#include "rclcpp/rclcpp.hpp"
#include "include/telemetry_bridge/UdpBridgeNode.hpp"
#include "include/telemetry_bridge/StateMonitorNode.hpp"


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto udp_node = std::make_shared<telemetry_bridge::UdpBridgeNode>();
    auto monitor_node = std::make_shared<telemetry_bridge::StateMonitorNode>();

    rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 8);

    executor.add_node(udp_node);
    executor.add_node(monitor_node);
    
    executor.spin();

    rclcpp::shutdown();
    return 0;
}

