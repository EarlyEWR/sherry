#ifndef SPACECRAFT_TF__SPACECRAFT_TF_NODE_HPP_
#define SPACECRAFT_TF__SPACECRAFT_TF_NODE_HPP_

#include <memory>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "telemetry_bridge/msg/telemetry_state.hpp"

namespace spacecraft_tf {

class SpacecraftTfNode : public rclcpp::Node {
public:
    SpacecraftTfNode();

private:
    void on_armstrong_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg);
    void on_edison_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg);

    void broadcast_vehicle(const std::string & child_frame, const telemetry_bridge::msg::TelemetryState & state);

    void publish_static_transforms();

    rclcpp::Subscription<telemetry_bridge::msg::TelemetryState>::SharedPtr armstrong_sub_;
    rclcpp::Subscription<telemetry_bridge::msg::TelemetryState>::SharedPtr edison_sub_;

    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    std::unique_ptr<tf2_ros::StaticTransformBroadcaster> static_tf_broadcaster_;

    std::vector<double> armstrong_docking_hatch_offset_;
    std::vector<double> docking_port_offset_;
};

} // namespace spacecraft_tf

#endif