#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "std_msgs/Bool.h"
#include <iostream>
#include <math.h>
#include <ncurses.h>

double pos_x=0;
double pos_y=0;
double b_pos_x=0;
double b_pos_y=-4;
double c_pos_x=0;
double c_pos_y=-8;
double d_pos_x=0;
double d_pos_y=-12;
int suma=0;
int suma2=0;

int distance_a_b (double pos_x,double pos_y,double b_pos_x,double b_pos_y)
{
if(sqrt( ((pos_x - b_pos_x)*(pos_x - b_pos_x)) + ((pos_y - b_pos_y)*(pos_y - b_pos_y)))< 2.0 ) return 3;
/*
else
{ 
if(sqrt( ((pos_x - b_pos_x)*(pos_x - b_pos_x)) + ((pos_y - b_pos_y)*(pos_y - b_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_a_b_2 (double pos_x,double pos_y,double b_pos_x,double b_pos_y)
{
if(sqrt( ((pos_x - b_pos_x)*(pos_x - b_pos_x)) + ((pos_y - b_pos_y)*(pos_y - b_pos_y)))> 6.0 ) return 3;
/*
else
{ 
if(sqrt( ((pos_x - b_pos_x)*(pos_x - b_pos_x)) + ((pos_y - b_pos_y)*(pos_y - b_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_a_c (double pos_x,double pos_y,double c_pos_x,double c_pos_y)
{
if(sqrt( ((pos_x - c_pos_x)*(pos_x - c_pos_x)) + ((pos_y - c_pos_y)*(pos_y - c_pos_y)))< 2.0 ) return 3;
/*
else 
{
if(sqrt( ((pos_x - c_pos_x)*(pos_x - c_pos_x)) + ((pos_y - c_pos_y)*(pos_y - c_pos_y)))> 12.0) return 2;
else return 0;
}
*/
return 0;
}

int distance_a_c_2 (double pos_x,double pos_y,double c_pos_x,double c_pos_y)
{
if(sqrt( ((pos_x - c_pos_x)*(pos_x - c_pos_x)) + ((pos_y - c_pos_y)*(pos_y - c_pos_y)))> 6.0 ) return 3;
/*
else 
{
if(sqrt( ((pos_x - c_pos_x)*(pos_x - c_pos_x)) + ((pos_y - c_pos_y)*(pos_y - c_pos_y)))> 12.0) return 2;
else return 0;
}
*/
return 0;
}

int distance_a_d (double pos_x,double pos_y,double d_pos_x,double d_pos_y)
{
if(sqrt( ((pos_x - d_pos_x)*(pos_x - d_pos_x)) + ((pos_y - d_pos_y)*(pos_y - d_pos_y)))< 2.0 ) return 3;
/*
else
{
if(sqrt( ((pos_x - d_pos_x)*(pos_x - d_pos_x)) + ((pos_y - d_pos_y)*(pos_y - d_pos_y)))> 16.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_a_d_2 (double pos_x,double pos_y,double d_pos_x,double d_pos_y)
{
if(sqrt( ((pos_x - d_pos_x)*(pos_x - d_pos_x)) + ((pos_y - d_pos_y)*(pos_y - d_pos_y)))> 6.0 ) return 3;
/*
else
{
if(sqrt( ((pos_x - d_pos_x)*(pos_x - d_pos_x)) + ((pos_y - d_pos_y)*(pos_y - d_pos_y)))> 16.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_b_c (double b_pos_x,double b_pos_y,double c_pos_x,double c_pos_y)
{
if(sqrt( ((c_pos_x - b_pos_x)*(c_pos_x - b_pos_x)) + ((c_pos_y - b_pos_y)*(c_pos_y - b_pos_y)))< 2.0 ) return 3;
/*
else
{
if(sqrt( ((c_pos_x - b_pos_x)*(c_pos_x - b_pos_x)) + ((c_pos_y - b_pos_y)*(c_pos_y - b_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_b_c_2 (double b_pos_x,double b_pos_y,double c_pos_x,double c_pos_y)
{
if(sqrt( ((c_pos_x - b_pos_x)*(c_pos_x - b_pos_x)) + ((c_pos_y - b_pos_y)*(c_pos_y - b_pos_y)))> 6.0 ) return 3;
/*
else
{
if(sqrt( ((c_pos_x - b_pos_x)*(c_pos_x - b_pos_x)) + ((c_pos_y - b_pos_y)*(c_pos_y - b_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_b_d (double b_pos_x,double b_pos_y,double d_pos_x,double d_pos_y)
{
if(sqrt( ((d_pos_x - b_pos_x)*(d_pos_x - b_pos_x)) + ((d_pos_y - b_pos_y)*(d_pos_y - b_pos_y)))< 2.0 ) return 3;
/*
else
{
if(sqrt( ((d_pos_x - b_pos_x)*(d_pos_x - b_pos_x)) + ((d_pos_y - b_pos_y)*(d_pos_y - b_pos_y)))> 12.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_b_d_2 (double b_pos_x,double b_pos_y,double d_pos_x,double d_pos_y)
{
if(sqrt( ((d_pos_x - b_pos_x)*(d_pos_x - b_pos_x)) + ((d_pos_y - b_pos_y)*(d_pos_y - b_pos_y)))> 6.0 ) return 3;
/*
else
{
if(sqrt( ((d_pos_x - b_pos_x)*(d_pos_x - b_pos_x)) + ((d_pos_y - b_pos_y)*(d_pos_y - b_pos_y)))> 12.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_c_d (double c_pos_x,double c_pos_y,double d_pos_x,double d_pos_y)
{

if(sqrt( ((c_pos_x - d_pos_x)*(c_pos_x - d_pos_x)) + ((c_pos_y - d_pos_y)*(c_pos_y - d_pos_y)))< 2.0 ) return 3;
/*
else
{
if(sqrt( ((c_pos_x - d_pos_x)*(c_pos_x - d_pos_x)) + ((c_pos_y - d_pos_y)*(c_pos_y - d_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

int distance_c_d_2 (double c_pos_x,double c_pos_y,double d_pos_x,double d_pos_y)
{

if(sqrt( ((c_pos_x - d_pos_x)*(c_pos_x - d_pos_x)) + ((c_pos_y - d_pos_y)*(c_pos_y - d_pos_y)))> 6.0 ) return 3;
/*
else
{
if(sqrt( ((c_pos_x - d_pos_x)*(c_pos_x - d_pos_x)) + ((c_pos_y - d_pos_y)*(c_pos_y - d_pos_y)))> 8.0 ) return 2;
else return 0;
}
*/
return 0;
}

void chatterCallback_a(const nav_msgs::Odometry::ConstPtr& msg)
{
pos_x=msg->pose.pose.position.x;
pos_y=msg->pose.pose.position.y;

}

void chatterCallback_b(const nav_msgs::Odometry::ConstPtr& msg)
{
b_pos_x=msg->pose.pose.position.x;
b_pos_y=msg->pose.pose.position.y;


}

void chatterCallback_c(const nav_msgs::Odometry::ConstPtr& msg)
{
c_pos_x=msg->pose.pose.position.x;
c_pos_y=msg->pose.pose.position.y;


}
void chatterCallback_d(const nav_msgs::Odometry::ConstPtr& msg)
{
d_pos_x=msg->pose.pose.position.x;
d_pos_y=msg->pose.pose.position.y;



}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "odom_listener");
  ros::NodeHandle n;
  
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
 

	ros::Subscriber sub = n.subscribe("/robot/robotnik_base_control/odom", 1000, chatterCallback_a);
	ros::Subscriber sub1 = n.subscribe("/robot_b/robotnik_base_control/odom", 1000, chatterCallback_b);
	ros::Subscriber sub2 = n.subscribe("/robot_c/robotnik_base_control/odom", 1000, chatterCallback_c);
	ros::Subscriber sub3 = n.subscribe("/robot_d/robotnik_base_control/odom", 1000, chatterCallback_d);
	
	ros::Publisher pub =  n.advertise<std_msgs::Bool>("/robot/robotnik_base_hw/emergency_stop", 1000);
	ros::Publisher pub1 = n.advertise<std_msgs::Bool>("/robot_b/robotnik_base_hw/emergency_stop", 1000);
	ros::Publisher pub2 = n.advertise<std_msgs::Bool>("/robot_c/robotnik_base_hw/emergency_stop", 1000);
	ros::Publisher pub3 = n.advertise<std_msgs::Bool>("/robot_d/robotnik_base_hw/emergency_stop", 1000);
	
	ros::Publisher pub_ =  n.advertise<geometry_msgs::Twist>("/robot/robotnik_base_control/cmd_vel", 1000);
	ros::Publisher pub_1 = n.advertise<geometry_msgs::Twist>("/robot_b/robotnik_base_control/cmd_vel", 1000);
	ros::Publisher pub_2 = n.advertise<geometry_msgs::Twist>("/robot_c/robotnik_base_control/cmd_vel", 1000);
	ros::Publisher pub_3 = n.advertise<geometry_msgs::Twist>("/robot_d/robotnik_base_control/cmd_vel", 1000);
	
	
	
	std_msgs::Bool emergency_stop_msg;
	geometry_msgs::Twist cmd_vel_msg;
	
	cmd_vel_msg.linear.x = 0;
	cmd_vel_msg.linear.y = 0;
	cmd_vel_msg.linear.z = 0;
	cmd_vel_msg.angular.x = 0;
	cmd_vel_msg.angular.y = 0;
	cmd_vel_msg.angular.z = 0;
	
	emergency_stop_msg.data=false;
	
	ros::Rate loop_rate(10);
	
	//std::cout << "Hello, world!\n";

	if(distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,B");
	if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,C");
	if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,D");
	if(distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,C");
	if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,D");
	if(distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN C,D");
	
	if(distance_a_b_2(pos_x,pos_y,b_pos_x,b_pos_y))  ROS_INFO("TOO FAR AWAY  A,B");
	//if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,C");
	//if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,D");
	if(distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)) ROS_INFO("TOO FAR AWAY  B,C");
	//if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,D");
	if(distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)) ROS_INFO("TOO FAR AWAY C,D");



	//ros::spin();
	
	  
while (ros::ok()) 
{




        // Spin once to process callbacks
        ros::spinOnce();
        
        
        
        
suma= distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)+distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y)+distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y)+ distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)+distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)+distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y);

suma2= distance_a_b_2(pos_x,pos_y,b_pos_x,b_pos_y) + distance_b_c_2(b_pos_x,b_pos_y,c_pos_x,c_pos_y) +  distance_c_d_2(c_pos_x,c_pos_y,d_pos_x,d_pos_y);

if(suma==0 && suma2==0)  ROS_INFO("EVERYTHING FINE");
if(distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,B %d ",suma);
if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,C %d ",suma);
if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,D %d ",suma);
if(distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,C %d ",suma);
if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,D %d ",suma);
if(distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN C,D %d ",suma);

if(distance_a_b_2(pos_x,pos_y,b_pos_x,b_pos_y))  ROS_INFO("TOO FAR AWAY  A,B %d",suma2);
//if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,C");
//if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y))  ROS_INFO("RISK OF COLLISION BETWEEN A,D");
if(distance_b_c_2(b_pos_x,b_pos_y,c_pos_x,c_pos_y)) ROS_INFO("TOO FAR AWAY  B,C,%d",suma2);
//if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)) ROS_INFO("RISK OF COLLISION BETWEEN B,D");
if(distance_c_d_2(c_pos_x,c_pos_y,d_pos_x,d_pos_y)) ROS_INFO("TOO FAR AWAY C,D%d",suma2);

///////////////////////////////////////////////////

	if((suma==0)&&(suma2==0) || (getch()==32) )  //|| (getch()==32)
	{
	emergency_stop_msg.data = false; 
	pub.publish(emergency_stop_msg);
	pub1.publish(emergency_stop_msg);
	pub2.publish(emergency_stop_msg);
	pub3.publish(emergency_stop_msg);
	//if((getch()==32)) ROS_INFO("\nSWITCH TO MANUAL: %d \n",suma);
	}
	
        else
	{
	/*
	if(distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)==3)  ROS_INFO("RISK OF COLLISION BETWEEN A,B: %d",suma);
	if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y)==3)  ROS_INFO("RISK OF COLLISION BETWEEN A,C %d",suma);
	if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y)==3)  ROS_INFO("RISK OF COLLISION BETWEEN A,D %d",suma);
	if(distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)==3) ROS_INFO("RISK OF COLLISION BETWEEN B,C %d",suma);
	if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)==3) ROS_INFO("RISK OF COLLISION BETWEEN B,D %d",suma);
	if(distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)==3) ROS_INFO("RISK OF COLLISION BETWEEN C,D %d",suma);
	*/
	//if(distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)==2)  ROS_INFO("TOO FAR AWAY RISK A,B %d",suma);
	//if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y)==2)  ROS_INFO("TOO FAR AWAY RISK A,C %d",suma);
	//if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y)==2)  ROS_INFO("TOO FAR AWAY RISK A,D %d",suma);

	if(suma>=3||suma2>=3)
	{
		///////////////////////////////////////////////////
		if(distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_1.publish(cmd_vel_msg);
		pub1.publish(emergency_stop_msg);
		}
		/*
		if(distance_a_b_2(pos_x,pos_y,b_pos_x,b_pos_y)==3)
		{ 
		//emergency_stop_msg.data = true;
		//pub_.publish(cmd_vel_msg);
		//pub.publish(emergency_stop_msg);
		}
		*/
		//////////////////////////////////////////////////
		/*
		if(distance_a_c(pos_x,pos_y,c_pos_x,c_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_2.publish(cmd_vel_msg);
		pub2.publish(emergency_stop_msg);
		}
		*/
		//////////////////////////////////////////////////
		/*
		if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_3.publish(cmd_vel_msg);
		pub3.publish(emergency_stop_msg);
		}
		*/
		/*
		else
		{
		if(distance_a_d(pos_x,pos_y,d_pos_x,d_pos_y)==2)
		{
		emergency_stop_msg.data = true;
		pub_.publish(cmd_vel_msg);
		pub.publish(emergency_stop_msg);
		}
		}
		*/
		//////////////////////////////////////////////////
		if(distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_2.publish(cmd_vel_msg);
		pub2.publish(emergency_stop_msg);
		}
		if(distance_b_c_2(b_pos_x,b_pos_y,c_pos_x,c_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_1.publish(cmd_vel_msg);
		pub1.publish(emergency_stop_msg);
		}
		
		/////////////////////////////////////////////////
		/*
		if(distance_b_d(b_pos_x,b_pos_y,d_pos_x,d_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_3.publish(cmd_vel_msg);
		pub3.publish(emergency_stop_msg);
		}
		*/
		/////////////////////////////////////////////////
		if(distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_3.publish(cmd_vel_msg);
		pub3.publish(emergency_stop_msg);
		}
		if(distance_c_d_2(c_pos_x,c_pos_y,d_pos_x,d_pos_y)==3)
		{ 
		emergency_stop_msg.data = true;
		pub_2.publish(cmd_vel_msg);
		pub2.publish(emergency_stop_msg);
		}
		
	}

/*
		if(suma==6 )
	{
	if((distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)==3) && (distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)==3) )
	{
	emergency_stop_msg.data = false;
	pub_1.publish(cmd_vel_msg);
	pub1.publish(emergency_stop_msg);
	
	emergency_stop_msg.data = true;
	pub_2.publish(cmd_vel_msg);
	pub2.publish(emergency_stop_msg);
	
	emergency_stop_msg.data = true;
	pub_3.publish(cmd_vel_msg);
	pub3.publish(emergency_stop_msg);
	}
	if( (distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)==3) && (distance_b_c(b_pos_x,b_pos_y,c_pos_x,c_pos_y)==3) )
	{
	
	emergency_stop_msg.data = true;
	pub_1.publish(cmd_vel_msg);
	pub1.publish(emergency_stop_msg);
	
	emergency_stop_msg.data = true;
	pub_2.publish(cmd_vel_msg);
	pub2.publish(emergency_stop_msg);
	}
		if( (distance_a_b(pos_x,pos_y,b_pos_x,b_pos_y)==3) && (distance_c_d(c_pos_x,c_pos_y,d_pos_x,d_pos_y)==3) )
	{
	emergency_stop_msg.data = true;
	pub_1.publish(cmd_vel_msg);
	pub1.publish(emergency_stop_msg);
	
	emergency_stop_msg.data = false;
	pub_2.publish(cmd_vel_msg);
	pub2.publish(emergency_stop_msg);
	
	emergency_stop_msg.data = true;
	pub_3.publish(cmd_vel_msg);
	pub3.publish(emergency_stop_msg);
	}
	
	}
		if(suma>6)
	{
 	//ROS_INFO("ABORT MISSION: %d",suma);
	}
*/
	}
        // Sleep to maintain the loop rate
        loop_rate.sleep();

}

  return 0;
}
