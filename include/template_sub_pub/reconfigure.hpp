#ifndef RECONFIGURE_H
#define RECONFIGURE_H

#include <dynamic_reconfigure/server.h>
#include <template_sub_pub/ReconfigureConfig.h>

template_sub_pub::ReconfigureConfig global_config;

void reconfigure_cb(template_sub_pub::ReconfigureConfig &config, uint32_t level)
{
  ROS_INFO("Reconfigure Request: %s",
           config.pub_string.c_str());
  global_config = config;
}

#endif