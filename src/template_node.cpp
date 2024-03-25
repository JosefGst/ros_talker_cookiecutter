#include "template_sub_pub/template_ros.h"

int main(int argc, char** argv )
{
    ros::init(argc, argv, "chatter");

    Template chatter;

    ros::spin();
    return 0;
}