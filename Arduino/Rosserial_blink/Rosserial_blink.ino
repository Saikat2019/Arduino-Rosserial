#include <ros.h>
#include <std_msgs/Int32.h>
#include<AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor3(3);

ros::NodeHandle nh;

void messageCb(const std_msgs::Int32 &AngleOfBot)
{
  if(AngleOfBot.data%4==0)
  {
   /*digitalWrite(13,HIGH-digitalRead(13));
   delay(500);
   digitalWrite(13,LOW-digitalRead(13));
   delay(500);
   digitalWrite(13,HIGH-digitalRead(13));
   delay(500);*/
   motor1.run(FORWARD);
   motor3.run(FORWARD);
  }
  if(AngleOfBot.data%4==1)
  {
   /*digitalWrite(13,HIGH-digitalRead(13));
   delay(500);
   digitalWrite(13,LOW-digitalRead(13));
   delay(500);
   digitalWrite(13,HIGH-digitalRead(13));
   delay(500);*/
   motor1.run(FORWARD);
   motor3.run(BACKWARD);
  }
  if(AngleOfBot.data%4==2)
  {
   /*digitalWrite(13,HIGH-digitalRead(13));
   delay(500);
   digitalWrite(13,LOW-digitalRead(13));
   delay(500);
   digitalWrite(13,HIGH-digitalRead(13));
   delay(500);*/
   motor1.run(BACKWARD);
   motor3.run(FORWARD);
  }
  if(AngleOfBot.data%4==3)
  {
   /*digitalWrite(13,HIGH-digitalRead(13));
   delay(500);
   digitalWrite(13,LOW-digitalRead(13));
   delay(500);
   digitalWrite(13,HIGH-digitalRead(13));
   delay(500);*/
   motor1.run(RELEASE);
   motor3.run(RELEASE);
  }
}

ros::Subscriber<std_msgs::Int32> sub("AngleOfBot",&messageCb);

void setup()
{
  pinMode(13,OUTPUT);
  motor1.setSpeed(255);
  motor3.setSpeed(255);
  nh.initNode();
  nh.subscribe(sub);
}
void loop()
{
  nh.spinOnce();
  delay(1);
}

