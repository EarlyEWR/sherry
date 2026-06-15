#include "rclcpp/rclcpp.hpp"
#include "../../include/sim_clock/SimClockNode.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<sim_clock::SimClockNode>());
    rclcpp::shutdown();
    return 0;
}