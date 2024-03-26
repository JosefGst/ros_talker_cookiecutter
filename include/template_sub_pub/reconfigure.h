#ifndef RECONFIGURE_H
#define RECONFIGURE_H

#include <dynamic_reconfigure/server.h>
#include <template_sub_pub/ReconfigureConfig.h>

template_sub_pub::ReconfigureConfig global_config;

void reconfigure_cb(template_sub_pub::ReconfigureConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %s", 
            config.pub_string.c_str() 
          );
  global_config = config;
}
// #include <template_sub_pub/reconfigure.h>

// template_sub_pub::ReconfigureConfig global_config; // Declare a global variable to store the configuration

// void reconfigureCallback(template_sub_pub::ReconfigureConfig &config, uint32_t level) {
//   global_config = config; // Update the global configuration variable
// }

// int main() {
//   // ...

//   // Set up the dynamic reconfigure server
//   dynamic_reconfigure::Server<template_sub_pub::ReconfigureConfig> server;
//   dynamic_reconfigure::Server<template_sub_pub::ReconfigureConfig>::CallbackType f;
//   f = boost::bind(&reconfigureCallback, _1, _2);
//   server.setCallback(f);

//   // ...

//   // Access config.rate
//   int rate = global_config.rate;
//   // Use the rate variable as needed

//   // ...

//   return 0;
// }

#endif