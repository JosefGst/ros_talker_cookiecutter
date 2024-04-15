cmake_minimum_required(VERSION 3.0.2)
project({{cookiecutter.pkg_name}})

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
  LIBRARIES {{cookiecutter.pkg_name}}
  CATKIN_DEPENDS roscpp rospy std_msgs

  # DEPENDS system_lib
)

add_library({{cookiecutter.pkg_name}}_lib
  src/{{cookiecutter.pkg_name}}_ros.cpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable({{cookiecutter.pkg_name}}_node src/{{cookiecutter.pkg_name}}_node.cpp)
add_dependencies({{cookiecutter.pkg_name}}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries({{cookiecutter.pkg_name}}_node {{cookiecutter.pkg_name}}_lib ${catkin_LIBRARIES})

add_dependencies({{cookiecutter.pkg_name}}_node ${PROJECT_NAME}_gencfg)
