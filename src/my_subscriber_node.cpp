#include "ros/ros.h"

#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

void chatterCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  ROS_INFO("I heard: [%lf]",msg->linear.x);
  ROS_INFO("I heard: [%lf]",msg->linear.y);
  ROS_INFO("I heard: [%lf]",msg->linear.z);
  ROS_INFO("I heard: [%lf]",msg->angular.x);
  ROS_INFO("I heard: [%lf]",msg->angular.y);
  ROS_INFO("I heard: [%lf]",msg->angular.z);
}

int main(int argc, char **argv)
{
   
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("my_topic", 1000, chatterCallback);

  ros::spin();

  return 0;
}
