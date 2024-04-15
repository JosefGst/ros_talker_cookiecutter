{{cookiecutter.pkg_name}}
===================

[TOC]

## Run

    rosrun {{cookiecutter.pkg_name}} {{cookiecutter.pkg_name}}_node
    rosrun {{cookiecutter.pkg_name}} {{cookiecutter.pkg_name}}_node _pub_string:="hello" _rate:=1
    roslaunch {{cookiecutter.pkg_name}} {{cookiecutter.pkg_name}}.launch pub_string:="hello" rate:=1

## Published Topics
- chatter [std_msgs/String](https://docs.ros.org/en/melodic/api/std_msgs/html/msg/String.html)

## Subscribed Topics
- cmd_vel [(geometry_msgs/Twist)](https://docs.ros.org/en/melodic/api/geometry_msgs/html/msg/Twist.html)

## Parameters
- rate (int,default:1)
    - publish rate of chatter" topic in [Hz]
    
- pub_string (string,default:"Hello World")
    - published string on chatter topic

![graph](assets/rosgraph.svg)