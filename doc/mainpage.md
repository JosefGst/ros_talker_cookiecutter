#{PKG_NAME} {#mainpage}
===================

[TOC]

## Run

    rosrun #{PKG_NAME} #{PKG_NAME}_node
    rosrun #{PKG_NAME} #{PKG_NAME}_node _pub_string:="hello" _rate:=1
    roslaunch #{PKG_NAME} #{PKG_NAME}.launch pub_string:="hello" rate:=1

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