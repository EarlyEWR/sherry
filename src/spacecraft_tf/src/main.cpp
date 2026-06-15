#include "rclcpp/rclcpp.hpp"
#include "spacecraft_tf/SpacecraftTfNode.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<spacecraft_tf::SpacecraftTfNode>());
    rclcpp::shutdown();
    return 0;
}