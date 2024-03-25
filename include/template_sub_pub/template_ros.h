#ifndef TEMPLATE_ROS_H
#define TEMPLATE_ROS_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

class Template
{
public:
    Template();
    void init_chatter();

private:
    ros::NodeHandle nh_;

    void cmd_vel_cb(const geometry_msgs::Twist& msg);

    void timer_1hz_cb(const ros::TimerEvent& event);
    ros::Timer timer_1hz_cb_timer;

    std_msgs::String string_msg;
    ros::Publisher chatter_pub;

    ros::Subscriber cmd_vel_sub;
};


#endif