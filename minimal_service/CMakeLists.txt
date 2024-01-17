cmake_minimum_required(VERSION 3.8)
project(minimal_service)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_service REQUIRED)
find_package(custom_service REQUIRED)
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()


# Add the service client executable
ament_auto_add_executable(minimal_service_client 
  src/minimal_service_client_node.cpp
  src/minimal_service_client_class.cpp) # dependencies
# Install the executable
install(TARGETS minimal_service_client
  DESTINATION lib/${PROJECT_NAME}
)

# Add the service server executable
ament_auto_add_executable(minimal_service_server
  src/minimal_service_server_node.cpp
  src/minimal_service_server_class.cpp) # dependencies
# Install the executable
install(TARGETS minimal_service_server
  DESTINATION lib/${PROJECT_NAME}
)

# Install launchfile
install(
  DIRECTORY
    launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
