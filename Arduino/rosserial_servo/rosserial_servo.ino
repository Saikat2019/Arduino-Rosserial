#include <ros.h>
#include <std_msgs/Int32.h>
#include <Servo.h>
#include<AFMotor.h>

Servo DriverServo;
int servo_position=0;

ros::NodeHandle nh;

int mod(int val)
{
  if(val>0)return val;
  else return -val;
}

void messageCb(const std_msgs::Int32 &AngleOfBot)
{
  if(mod(servo_position-AngleOfBot.data)>10)
      {
        servo_position=AngleOfBot.data;
        DriverServo.write(servo_position);
      }
}

ros::Subscriber<std_msgs::Int32> sub("AngleOfBot",&messageCb);

void setup()
{
  
  DriverServo.attach(10);
  nh.initNode();
  nh.subscribe(sub);
}
void loop()
{
  nh.spinOnce();
  delay(1);
}

