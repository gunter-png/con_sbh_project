cmake_minimum_required(VERSION 3.8)
project(con_sbh_project)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
  turtlesim
)

add_executable(cylinder_draw src/cylinder_draw.cpp)
ament_target_dependencies(cylinder_draw ${ament_dependencies} )
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
install(TARGETS
cylinder_draw
DESTINATION lib/${PROJECT_NAME})

add_executable(staircase_draw src/staircase_draw.cpp)
ament_target_dependencies(staircase_draw ${ament_dependencies} )
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})
install(TARGETS
staircase_draw
DESTINATION lib/${PROJECT_NAME})

ament_package()