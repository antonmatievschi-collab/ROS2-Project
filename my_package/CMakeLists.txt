cmake_minimum_required(VERSION 3.5)
project(my_package)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# -----------------------------------------------------------------------------
# 1. Dependencies
# -----------------------------------------------------------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pluginlib REQUIRED)

# -----------------------------------------------------------------------------
# 2. Include Directories
# -----------------------------------------------------------------------------
# This allows the compiler to find "Geometry/point.hpp"
include_directories(include)

# -----------------------------------------------------------------------------
# 3. Library Definition (Plugins)
# -----------------------------------------------------------------------------
# Fixed: Matching your exact filenames from 'ls' output
add_library(point_plugins_lib SHARED
  src/Point2D.cpp
  src/Point3D.cpp
)

ament_target_dependencies(point_plugins_lib
  pluginlib
  rclcpp
)

# -----------------------------------------------------------------------------
# 4. Executable Definition (The Node)
# -----------------------------------------------------------------------------
# Fixed: Removed the duplicate add_executable and matched 'Points_node.cpp'
add_executable(points_node src/Points_node.cpp)

ament_target_dependencies(points_node
  pluginlib
  rclcpp
)

# -----------------------------------------------------------------------------
# 5. Install Instructions
# -----------------------------------------------------------------------------
# Install the binaries
install(TARGETS points_node point_plugins_lib
  DESTINATION lib/${PROJECT_NAME}
)

# Install the headers
install(DIRECTORY include/
  DESTINATION include
)

# Install the plugin description file (Crucial for pluginlib)
install(FILES plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

# -----------------------------------------------------------------------------
# 6. Exporting
# -----------------------------------------------------------------------------
ament_export_libraries(point_plugins_lib)
ament_export_dependencies(pluginlib rclcpp)
pluginlib_export_plugin_description_file(my_package plugins.xml)

ament_package()
