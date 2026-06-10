# Pillar Project 1

## Build & Run Commands
- cd /scripts
- ./start.sh bridge for bridge mode
- ./start.sh host for host mode

## Current Bugs
- Critical: Docker build currently fails in CMake test dependency resolution
Build command run: build.sh
Failure observed: CMake cannot find gtestConfig.cmake during colcon build.
References: CMakeLists.txt:34, Dockerfile:8, package.xml:15

- Critical: Main node does not compile even when tests are disabled
Verification command run: colcon build with BUILD_TESTING=OFF in ros:foxy container.
Failure observed: telemetry_bridge namespace types used in main are unresolved at compile time.
References: main.cpp:10, main.cpp:11, UdpBridgeNode.hpp, StateMonitorNode.hpp

- High: Core node files are empty stubs (no implementation exists)
These files currently contain no code, so there is no bridge/monitor behavior implemented.
References: UdpBridgeNode.cpp, StateMonitorNode.cpp, UdpBridgeNode.hpp, StateMonitorNode.hpp, ThreadSafeQueue.hpp

- High: Test target linkage is misconfigured
CMake links latency_test against ${PROJECT_NAME}, but no telemetry_bridge library target is defined.
This is likely the next failure after gtest is fixed.
References: CMakeLists.txt:36, CMakeLists.txt:18

- Medium: Include directory setup is inconsistent with actual layout
CMake adds include directory include relative to src/telemetry_bridge, but actual headers are under src/include.
Current build only works around this via relative include paths in sources.
References: CMakeLists.txt:16, main.cpp:2

- Medium: Image tag mismatch between compose and run script
Host profile uses telemetry-bridge:sfoxy while script default uses telemetry-bridge:foxy.
This can cause running wrong/nonexistent image tags depending on entrypoint used.
References: docker-compose.yaml:17, run.sh:5

- Low: start.sh invalid mode path does not return nonzero exit
In the default case it prints usage but does not exit with failure.
References: start.sh:16
