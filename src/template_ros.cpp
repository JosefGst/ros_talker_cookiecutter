#include "ros/ros.h"
#include "template_sub_pub/template_ros.h"

Template::Template() : nh_("~")
{
  init_chatter();

  timer_1hz_cb_timer = nh_.createTimer(ros::Duration(1), &Template::Timer1HzCallbackCallback, this, false);
}

void Template::init_chatter()
{
  chatter_pub = nh_.advertise<std_msgs::String>("/chatter", 1);       

}

void Template::Timer1HzCallbackCallback(const ros::TimerEvent& event)
{
  string_msg.data = "Hello World";
  chatter_pub.publish(string_msg);
}