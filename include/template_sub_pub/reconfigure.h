#ifndef RECONFIGURE_H
#define RECONFIGURE_H

#include <dynamic_reconfigure/server.h>
#include <template_sub_pub/ReconfigureConfig.h>

void callback(template_sub_pub::ReconfigureConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %d %s", 
            config.rate, 
            config.pub_string.c_str() 
          );
}

#endif