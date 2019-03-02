#include <ros.h>

#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msgs;
ros::Publisher Arduino_Rosserial_HelloWorld("Arduino_Rosserial_HelloWorld",&str_msgs);

char hello[]="hello Rosserial";

void setup()
{
  nh.initNode();
  nh.advertise(Arduino_Rosserial_HelloWorld);
}

void loop()
{
  str_msgs.data=hello;
  Arduino_Rosserial_HelloWorld.publish(&str_msgs);
  nh.spinOnce();
  delay(500);
}

