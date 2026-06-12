cmake_minimum_required(VERSION 3.5)
project(telemetry_bridge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

# dependencies variable to manage packages
set(dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

rosidl_generate_interfaces(${PROJECT_NAME}
    "../msg/TelemetryState.msg"
    "../msg/LatencyStats.msg"
    DEPENDENCIES std_msgs
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(${PROJECT_NAME}_nodes
  ../StateMonitorNode.cpp
  ../UdpBridgeNode.cpp
)

ament_target_dependencies(${PROJECT_NAME}_nodes ${dependencies})
rosidl_target_interfaces(${PROJECT_NAME}_nodes
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(udp_bridge
  ../main.cpp
)

target_link_libraries(udp_bridge ${PROJECT_NAME}_nodes)
ament_target_dependencies(udp_bridge ${dependencies})
rosidl_target_interfaces(udp_bridge
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Install the executable to the package-specific lib directory
install(TARGETS udp_bridge
    DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/../launch
    ${CMAKE_CURRENT_SOURCE_DIR}/../config
    DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  ament_add_gtest(latency_test ../tests/latency_test.cpp)
  target_include_directories(latency_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

  ament_add_gtest(monitor_test ../tests/monitor_test.cpp)
  target_link_libraries(monitor_test ${PROJECT_NAME}_nodes)
  ament_target_dependencies(monitor_test ${dependencies})
  rosidl_target_interfaces(monitor_test
    ${PROJECT_NAME} "rosidl_typesupport_cpp")
  target_include_directories(monitor_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
endif()

ament_export_dependencies(rosidl_default_runtime)
ament_package()