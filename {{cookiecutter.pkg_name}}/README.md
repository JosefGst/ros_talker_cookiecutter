# {{cookiecutter.pkg_name}}

## Contents

- [Run](#run)
- [Published Topics](#published-topics)
- [Subscribed Topics](#subscribed-topics)
- [Parameters](#parameters)
- [Development](#development)
  - [Debugging C++](#debugging-c)
  - [Linting](#linting)
  - [Create Documentation](#create-documentation)
- [TODO](#todo)

I kept copying code from the official documentation or from my previous works every time I created a new ROS package. With this {{cookiecutter.pkg_name}} I hope the repetitive setup task can be reduced and I can jump directly into the development. For now it includes a simple publisher and subscriber, dynamic reconfigurable parameters, documentation generation with rosdoc_lite and c++ debug setup.

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

![graph](doc/assets/rosgraph.svg)

## Development

### Debugging C++

1. Move the .vscode folder into the workspace directory. 
2. Edit the launch.json file as necessary.
3. Run the "make_debug" task
4. Click the Debug button on the left side in vscode. Select "ROS:Launch" and click the the green arrow.

#### Alternatively attach to single node

In addition to the previous steps 
1. Run the "ROS:Start" task
2. rosrun the node
3. Click the green debug button with ROS:attach selected

#### References
[Polyhobbyist Youtube](https://www.youtube.com/watch?v=uqqHgYsskJI)
[vscode-ros github](https://github.com/ms-iot/vscode-ros/blob/master/doc/debug-support.mdA)

### Linting

In root of workspace

    catkin_make roslint_{{cookiecutter.pkg_name}}

### create documentation

In root of package

    rosdoc_lite .

To see the generated [documentation website](https://josefgst.github.io/{{cookiecutter.pkg_name}}/doc/html/index.html).

## TODO

- [x] make params reconfigurable
- [x] debugging c++
- [ ] add tests
- [ ] github actions
- [ ] ros2 branch
- [x] automatic documentation generation
- [ ] dockerization should be in separate docker_ws repo 
