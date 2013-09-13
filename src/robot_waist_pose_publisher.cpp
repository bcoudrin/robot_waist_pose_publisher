#include "ros/ros.h"
#include <geometry_msgs/TransformStamped.h>
#include <tf/transform_broadcaster.h>

#include <sstream>

tf::TransformBroadcaster *br;

void tfCallback(const geometry_msgs::TransformStampedConstPtr& vec)
{
  tf::StampedTransform st;
  tf::transformStampedMsgToTF(*vec,st);
  br->sendTransform(st);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "waist_pose_publisher");
  ros::NodeHandle n;

  tf::Transform transform;
  br = new tf::TransformBroadcaster();

  ros::Subscriber sub = n.subscribe("waist_pose", 1000, tfCallback);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
    transform.setRotation( tf::Quaternion(0.0, 0.0, 0.0) );
    br->sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "odom"));
    ros::spinOnce();
    loop_rate.sleep();
  }

  delete br;

  return 0;
}
