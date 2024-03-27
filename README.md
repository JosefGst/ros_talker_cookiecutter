# Template ROS sub pub pkg cpp

I kept copying code from the official documentation or from my previous works every time I created a new ROS package. With this template I hope the repetitive setup task can be reduced and jump directly into the development. For now it includes a simple publisher and subscriber, dynamic reconfigurable parameters and documentation generation with rosdoc_lite. 

## Run

    rosrun template_sub_pub template_node
    rosrun template_sub_pub template_node _pub_string:="hello" _rate:=1
    roslaunch template_sub_pub template.launch pub_string:="hello" rate:=1

## Published Topics
- chatter [std_msgs/String](https://docs.ros.org/en/melodic/api/std_msgs/html/msg/String.html)

## Subscribed Topics
- cmd_vel [(geometry_msgs/Twist)](https://docs.ros.org/en/melodic/api/geometry_msgs/html/msg/Twist.html)

## Parameters
- rate (int,default:1)
    - publish rate of chatter" topic in [Hz]
    
- pub_string (string,default:"Hello World")
    - published string on chatter topic

![graph](doc/assets/rosgraph.svg)

## Development
### create documentation

    rosdoc_lite .

To see the generated [documentation website](https://josefgst.github.io/template_sub_pub/doc/html/index.html).

### Linting

    catkin_make roslint_template_sub_pub


## TODO

- [x] make params reconfigurable
- [ ] add tests
- [ ] github actions
- [ ] ros2 branch
- [x] automatic documentation generation
- [ ] dockerize