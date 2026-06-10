cmake_minimum_required(VERSION 3.5)
project(telemetry_bridge)

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# dependencies variable to manage packages
set(dependencies
    rclcpp
    std_msgs
)

include_directories(include)

add_executable(udp_bridge ../main.cpp)

ament_target_dependencies(udp_bridge ${dependencies})

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
    find_package(gtest REQUIRED)
    ament_add_gtest(latency_test ../tests/latency_test.cpp)
    target_link_libraries(latency_test ${PROJECT_NAME})
endif()

ament_package()