/*
 * MIT License
 *
 * Copyright (c) 2024 Josef Gstoettner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ros/ros.h"
#include "#{PKG_NAME}/#{PKG_NAME}_ros.h"
#include "#{PKG_NAME}/reconfigure.h"
#include <string>

namespace ros_#{PKG_NAME}
{

  #{CLASS_NAME}::#{CLASS_NAME}() : nh_("~")
  {
    init_params();
    init_chatter();

    timer = nh_.createTimer(ros::Duration(1.0 / rate), &#{CLASS_NAME}::timer_cb, this, false);
  }

  void #{CLASS_NAME}::init_chatter()
  {
    chatter_pub = nh_.advertise<std_msgs::String>("/chatter", 1);
    ROS_INFO_STREAM("advertise to chatter topic on [" << chatter_pub.getTopic() << "]");

    cmd_vel_sub = nh_.subscribe("/cmd_vel", 1, &#{CLASS_NAME}::cmd_vel_cb, this);
    ROS_INFO_STREAM("subscribe to the cmd topic on [" << cmd_vel_sub.getTopic() << "]");
  }

  void #{CLASS_NAME}::init_params()
  {
    if (!nh_.param("rate", rate, 10))
    {
      ROS_WARN("No rate set. Default is 10");
    }
    if (!nh_.param("pub_string", global_config.pub_string, std::string("Hello World!")))
    {
      ROS_WARN("No pub_string set. Default is 'Hello World!'");
    }
  }

  void #{CLASS_NAME}::timer_cb(const ros::TimerEvent &event)
  {
    string_msg.data = global_config.pub_string;
    chatter_pub.publish(string_msg);
  }

  void #{CLASS_NAME}::cmd_vel_cb(const geometry_msgs::Twist &msg)
  {
    ROS_INFO_STREAM("cmd_vel: [" << msg << "]");
  }

}  // namespace ros_#{PKG_NAME}
