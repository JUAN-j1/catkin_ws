#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <math.h>
#include <tf2/LinearMath/Quaternion.h>
#include <iostream>
//#include <conio.h>
#define PI 3.14159

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


int main(int argc, char** argv){

ros::init(argc, argv, "simple_navigation_goals");
ros::init(argc, argv, "map_publisher");
ros::NodeHandle nh;

//tell the action client that we want to spin a thread by default
MoveBaseClient ac("robot/move_base", true);
MoveBaseClient ac_b("robot_b/move_base", true);
MoveBaseClient ac_c("robot_c/move_base", true);
MoveBaseClient ac_d("robot_d/move_base", true);

//wait for the action server to come up
while(!ac.waitForServer(ros::Duration(5.0))){
ROS_INFO("Waiting for the move_base action server to come up");
}

move_base_msgs::MoveBaseGoal goal;
move_base_msgs::MoveBaseGoal goal_b;
move_base_msgs::MoveBaseGoal goal_c;
move_base_msgs::MoveBaseGoal goal_d;
FILE *fp;
FILE *fp2;

int j=0;
int index;
float xant,yant;
float x1,y1,x2,y2;
float x3,y3,x4,y4;
float x1_coord,y1_coord,oz1_coord;
float x2_coord,y2_coord,oz2_coord,oz3_coord;
float ox1=0,oy1=0,ox2=0,oy2=0;
int conta_aux=5;
int conta_aux_2=5;
tf2::Quaternion myQuaternion;

fp2 = fopen("/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_coords.txt","r");
fscanf(fp2,"%f,%f,%f,",&x1_coord,&y1_coord,&oz1_coord); 
fscanf(fp2,"%f,%f,%f,%f",&x2_coord,&y2_coord,&oz2_coord,&oz3_coord); 
fclose(fp2);

x1_coord=787-2*x1_coord;
y1_coord=787-2*y1_coord;

fp = fopen("/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_path.txt","r");
fscanf(fp, "%*[^\n]\n");
fscanf(fp, "%*[^\n]\n");

while(conta_aux==5 && conta_aux_2==5)
{

if(j==0) 
{
conta_aux=fscanf(fp,"%d\t%f,%f\t%f,%f",&index,&x1,&y1,&x2,&y2);
ox1=x1;
oy1=y1;
ox2=x2;
oy2=y2;
}
else
{
xant=x1; yant=y1;
x1=x3; y1=y3; x2=x4; y2=y4;
}

conta_aux_2=fscanf(fp,"%d\t%f,%f\t%f,%f",&index,&x3,&y3,&x4,&y4);
//////////////////////////////////////////////////////////////////////
//robot 

goal.target_pose.header.frame_id = "robot_map";
goal.target_pose.header.stamp = ros::Time::now();


if(j==0)
{
goal.target_pose.pose.position.x =(x1-ox1);
goal.target_pose.pose.position.y =(y1-oy1);
}
else
{
//float ans= sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
goal.target_pose.pose.position.x =(x1-ox1) ;
goal.target_pose.pose.position.y =(y1-oy1) ;
}
myQuaternion.setRPY( 0, 0, atan2((y3-y1),(x3-x1)) );

goal.target_pose.pose.orientation.x=  myQuaternion.getX();
goal.target_pose.pose.orientation.y=  myQuaternion.getY();
goal.target_pose.pose.orientation.z=  myQuaternion.getZ(); 
goal.target_pose.pose.orientation.w = myQuaternion.getW();

// end robot

//robot_b

goal_b.target_pose.header.frame_id = "robot_b_map";
goal_b.target_pose.header.stamp = ros::Time::now();

float ans1= sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
goal_b.target_pose.pose.position.x =(x1-ox1)- (x3-x1)*(4/ans1) ;
goal_b.target_pose.pose.position.y =(y1-oy1)- (y3-y1)*(4/ans1) ;

myQuaternion.setRPY( 0, 0, atan2((y3-y1),(x3-x1)) );

goal_b.target_pose.pose.orientation.x=  myQuaternion.getX();
goal_b.target_pose.pose.orientation.y=  myQuaternion.getY();
goal_b.target_pose.pose.orientation.z=  myQuaternion.getZ(); 
goal_b.target_pose.pose.orientation.w = myQuaternion.getW();

// end robot_b

//robot_c 

goal_c.target_pose.header.frame_id = "robot_c_map";
goal_c.target_pose.header.stamp = ros::Time::now();

float ans2= sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
goal_c.target_pose.pose.position.x =(x1-ox1)- (x3-x1)*(8/ans2) ;
goal_c.target_pose.pose.position.y =(y1-oy1)- (y3-y1)*(8/ans2) ;

myQuaternion.setRPY( 0, 0, atan2((y3-y1),(x3-x1)) );

goal_c.target_pose.pose.orientation.x=  myQuaternion.getX();
goal_c.target_pose.pose.orientation.y=  myQuaternion.getY();
goal_c.target_pose.pose.orientation.z=  myQuaternion.getZ(); 
goal_c.target_pose.pose.orientation.w = myQuaternion.getW();

// end robot_c

//robot_d

goal_d.target_pose.header.frame_id = "robot_c_map";
goal_d.target_pose.header.stamp = ros::Time::now();

float ans3= sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
goal_d.target_pose.pose.position.x =(x1-ox1)- (x3-x1)*(12/ans3) ;
goal_d.target_pose.pose.position.y =(y1-oy1)- (y3-y1)*(12/ans3) ;

myQuaternion.setRPY( 0, 0, atan2((y3-y1),(x3-x1)) );

goal_d.target_pose.pose.orientation.x=  myQuaternion.getX();
goal_d.target_pose.pose.orientation.y=  myQuaternion.getY();
goal_d.target_pose.pose.orientation.z=  myQuaternion.getZ(); 
goal_d.target_pose.pose.orientation.w = myQuaternion.getW();

// end robot_d
////////////////////////////////////////////////////////////////////////

if(j==0)
{
ROS_INFO("Sending goal: %f,%f,%f,%f %f . ALso: %d",x1,y1,x3,y3, 360*(atan((y3-y1+oy1)/(x3-x1+ox1)))/(2*PI) ,conta_aux);

std::string myString0 = "gnome-terminal -- rosrun gazebo_ros spawn_model -file /home/juanmat/catkin_ws/src/simple_navigation_goals/src/prueba.urdf -urdf -x" + std::to_string(x3-ox1-x1_coord)
+ " -y " + std::to_string(y3-oy1-y1_coord)
+ " -z 1.0 -model my_object_"
+std::to_string(j);
std::cout << myString0 << std::endl;

const char* checkpoint0 = myString0.c_str();
std::system(checkpoint0);
}


j++;

ac.sendGoal(goal);
ac_b.sendGoal(goal_b);
ac_c.sendGoal(goal_c);
ac_d.sendGoal(goal_d);


ac.waitForResult();
ac_b.waitForResult();
ac_c.waitForResult();
ac_d.waitForResult();



/*
if (kbhit()) 
{ // Verifica si se ha presionado una tecla
            ch = getch(); // Lee la tecla presionada
            if (ch == 27) { // Si se presiona 'q' o 'Q', salimos del bucle
                return 0;
            }
}
*/


if(j!=0 && ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
{
ROS_INFO("Sending goal: %f,%f,%f,%f %f . ALso: %d",x1,y1,x3,y3, 360*(atan((y3-y1+oy1)/(x3-x1+ox1)))/(2*PI) ,conta_aux);

std::string myString0 = "gnome-terminal -- rosrun gazebo_ros spawn_model -file /home/juanmat/catkin_ws/src/simple_navigation_goals/src/prueba.urdf -urdf -x" + std::to_string(x3-ox1-x1_coord)
+ " -y " + std::to_string(y3-oy1+y1_coord) 
+ " -z 1.0 -model my_object_"
+std::to_string(j);
std::cout << myString0 << std::endl;

const char* checkpoint0 = myString0.c_str();
std::system(checkpoint0);
}


}

fclose(fp);

return 0;
}



