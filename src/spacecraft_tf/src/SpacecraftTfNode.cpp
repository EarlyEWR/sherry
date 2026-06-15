#include "spacecraft_tf/SpacecraftTfNode.hpp"

namespace spacecraft_tf {

SpacecraftTfNode::SpacecraftTfNode()
: Node("spacecraft_tf_node")
{
    this->declare_parameter("armstrong_docking_hatch_offset", std::vector<double>{0.0, 0.0, 1.8});
    this->declare_parameter("docking_port_offset", std::vector<double>{-3.0, 0.0, 0.0});

    armstrong_docking_hatch_offset_ = this->get_parameter("armstrong_docking_hatch_offset").as_double_array();
    docking_port_offset_ = this->get_parameter("docking_port_offset").as_double_array();

    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
    static_tf_broadcaster_ = std::make_unique<tf2_ros::StaticTransformBroadcaster>(*this);

    armstrong_sub_ = this->create_subscription<telemetry_bridge::msg::TelemetryState>(
        "armstrong/telemetry/incoming", 10,
        std::bind(&SpacecraftTfNode::on_armstrong_state, this, std::placeholders::_1));
    
    edison_sub_ = this->create_subscription<telemetry_bridge::msg::TelemetryState>(
        "edison/telemetry/incoming", 10,
        std::bind(&SpacecraftTfNode::on_edison_state, this, std::placeholders::_1));

    publish_static_transforms();
}

void SpacecraftTfNode::on_armstrong_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg)
{
    broadcast_vehicle("armstrong/body", *msg);
}

void SpacecraftTfNode::on_edison_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg)
{
    broadcast_vehicle("edison/body", *msg);
}

void SpacecraftTfNode::broadcast_vehicle(
    const std::string & child_frame,
    const telemetry_bridge::msg::TelemetryState & state)
{
    geometry_msgs::msg::TransformStamped t;
    t.header.stamp = state.header.stamp;
    t.header.frame_id = "world";
    t.child_frame_id = child_frame;

    // Position from Pose field
    t.transform.translation.x = state.pose.position.x;
    t.transform.translation.y = state.pose.position.y;
    t.transform.translation.z = state.pose.position.z;

    // Orientation from Pose quaternion
    t.transform.rotation.x = state.pose.orientation.x;
    t.transform.rotation.y = state.pose.orientation.y;
    t.transform.rotation.z = state.pose.orientation.z;
    t.transform.rotation.w = state.pose.orientation.w;

    tf_broadcaster_->sendTransform(t);
}

void SpacecraftTfNode::publish_static_transforms()
{
    std::vector<geometry_msgs::msg::TransformStamped> statics;

    // armstrong/body -> armstrong/nose
    {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "armstrong/body";
        t.child_frame_id  = "armstrong/docking_hatch";
        t.transform.translation.x = armstrong_docking_hatch_offset_[0];
        t.transform.translation.y = armstrong_docking_hatch_offset_[1];
        t.transform.translation.z = armstrong_docking_hatch_offset_[2];
        t.transform.rotation.w = 1.0; // identity rotation
        statics.push_back(t);
    }

    // edison/body -> edison/docking_port
    {
        geometry_msgs::msg::TransformStamped t;
        t.header.stamp = this->get_clock()->now();
        t.header.frame_id = "edison/body";
        t.child_frame_id = "edison/docking_port";
        t.transform.translation.x = docking_port_offset_[0];
        t.transform.translation.y = docking_port_offset_[1];
        t.transform.translation.z = docking_port_offset_[2];
        t.transform.rotation.w = 1.0;
        statics.push_back(t);
    }

    static_tf_broadcaster_->sendTransform(statics);
}
} // namespace spacecraft_tf