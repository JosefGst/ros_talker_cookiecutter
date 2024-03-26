#ifndef TEMPLATE_ROS_H
#define TEMPLATE_ROS_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

namespace ros_package_template
{

    class Template
    {
    public:
        Template();
        void init_chatter();

    private:
        ros::NodeHandle nh_;

        void init_params();
        void cmd_vel_cb(const geometry_msgs::Twist &msg);
        void timer_cb(const ros::TimerEvent &event);
        ros::Timer timer;

        std_msgs::String string_msg;
        ros::Publisher chatter_pub;

        ros::Subscriber cmd_vel_sub;

        // PARAMS
        int rate = 1;
        std::string pub_string;
        
    };
}

#endif