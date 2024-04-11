cmake_minimum_required(VERSION 3.0.2)
project(#{PKG_NAME})

find_package(catkin REQUIRED COMPONENTS
  roslint
  roscpp
  rospy
  std_msgs
  dynamic_reconfigure
)

roslint_cpp()

generate_dynamic_reconfigure_options(
  config/reconf.cfg
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES #{PKG_NAME}
  CATKIN_DEPENDS roscpp rospy std_msgs

  # DEPENDS system_lib
)

add_library(#{PKG_NAME}_lib
  src/#{PKG_NAME}_ros.cpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(#{PKG_NAME}_node src/#{PKG_NAME}_node.cpp)
add_dependencies(#{PKG_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(#{PKG_NAME}_node #{PKG_NAME}_lib ${catkin_LIBRARIES})

add_dependencies(#{PKG_NAME}_node ${PROJECT_NAME}_gencfg)
