cmake_minimum_required(VERSION 3.5)
project(sim_clock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosgraph_msgs REQUIRED)

set(dependencies rclcpp rosgraph_msgs)

include_directories(include)

add_library(${PROJECT_NAME}_nodes src/SimClockNode.cpp)
ament_target_dependencies(${PROJECT_NAME}_nodes ${dependencies})

add_executable(sim_clock_node src/main.cpp)
target_link_libraries(sim_clock_node ${PROJECT_NAME}_nodes)
ament_target_dependencies(sim_clock_node ${dependencies})

install(TARGETS sim_clock_node DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_package()