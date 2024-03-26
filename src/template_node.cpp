#include "template_sub_pub/template_ros.h"
#include "template_sub_pub/reconfigure.h"

int main(int argc, char** argv )
{
    ros::init(argc, argv, "sub_pub");

    // DYNAMIC RECONFIGURE
    dynamic_reconfigure::Server<template_sub_pub::ReconfigureConfig> server;
    dynamic_reconfigure::Server<template_sub_pub::ReconfigureConfig>::CallbackType f;
    f = boost::bind(&reconfigure_cb, _1, _2);
    server.setCallback(f);

    ros_package_template::Template chatter;

    ros::spin();
    return 0;
}