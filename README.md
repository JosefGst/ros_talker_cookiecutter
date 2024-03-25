# Template ROS sub pub pkg cpp

## Run

    rosrun template_sub_pub template_node
    rosrun template_sub_pub template_node _pub_string:="hello" _rate:=1
    roslaunch template_sub_pub template.launch 

## Published Topics
- chatter [std_msgs/String](https://docs.ros.org/en/melodic/api/std_msgs/html/msg/String.html)

## Subscribed Topics
- cmd_vel [(geometry_msgs/Twist)](https://docs.ros.org/en/melodic/api/geometry_msgs/html/msg/Twist.html)

## Parameters
- rate (int,default:1)
publish rate of chatter" topic
- pub_string (string,default:"Hello World")
published string on chatter topic

![graph](assets/rosgraph.svg)

## TODO

- [ ] add parameter
- [ ] add tests
- [ ] github actions
- [ ] ros2 branch