#include "ros/ros.h"
#include "template_sub_pub/template_ros.h"

Template::Template() : nh_("~")
{
  init_chatter();

  timer_1hz_cb_timer = nh_.createTimer(ros::Duration(1), &Template::timer_1hz_cb, this, false);
}

void Template::init_chatter()
{
  chatter_pub = nh_.advertise<std_msgs::String>("/chatter", 1);       
  ROS_INFO_STREAM("advertise to chatter topic on [" << chatter_pub.getTopic() << "]");

  cmd_vel_sub = nh_.subscribe("/cmd_vel", 1, &Template::cmd_vel_cb, this);
  ROS_INFO_STREAM("subscribe to the cmd topic on [" << cmd_vel_sub.getTopic() << "]");
}

void Template::timer_1hz_cb(const ros::TimerEvent& event)
{
  string_msg.data = "Hello World";
  chatter_pub.publish(string_msg);
}

void Template::cmd_vel_cb(const geometry_msgs::Twist& msg){
  ROS_INFO_STREAM("cmd_vel: [" << msg << "]");
}