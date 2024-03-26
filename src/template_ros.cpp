#include "ros/ros.h"
#include "template_sub_pub/template_ros.h"
#include "template_sub_pub/reconfigure.h"

namespace ros_package_template
{

  Template::Template() : nh_("~")
  {
    init_params();
    init_chatter();

    timer = nh_.createTimer(ros::Duration(1.0 / rate), &Template::timer_cb, this, false);
  }

  void Template::init_chatter()
  {
    chatter_pub = nh_.advertise<std_msgs::String>("/chatter", 1);
    ROS_INFO_STREAM("advertise to chatter topic on [" << chatter_pub.getTopic() << "]");

    cmd_vel_sub = nh_.subscribe("/cmd_vel", 1, &Template::cmd_vel_cb, this);
    ROS_INFO_STREAM("subscribe to the cmd topic on [" << cmd_vel_sub.getTopic() << "]");
  }

  void Template::init_params()
  {
    nh_.param("rate", rate, 10);
    nh_.param("pub_string", pub_string, std::string("Hello World"));
  }

  void Template::timer_cb(const ros::TimerEvent &event)
  {
    string_msg.data = pub_string;
    chatter_pub.publish(string_msg);
  }

  void Template::cmd_vel_cb(const geometry_msgs::Twist &msg)
  {
    ROS_INFO_STREAM("cmd_vel: [" << msg << "]");
  }

} // namespace ros_package_template
