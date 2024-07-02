#include <ros/ros.h>
#include <gazebo_msgs/SetPhysicsProperties.h>
#include <gazebo_msgs/GetPhysicsProperties.h>
#include <geometry_msgs/Vector3.h>
#include <stdio.h>
#include <math.h>



int main(int argc, char **argv)
{
    ros::init(argc, argv, "change_gravity");
    ros::NodeHandle nh;

    // Cliente para obtener las propiedades físicas actuales
    ros::ServiceClient get_physics_client = nh.serviceClient<gazebo_msgs::GetPhysicsProperties>("/gazebo/get_physics_properties");
    gazebo_msgs::GetPhysicsProperties get_physics_srv;

    if (get_physics_client.call(get_physics_srv))
    {
        ROS_INFO("Current gravity: x=%.2f, y=%.2f, z=%.2f",
                 get_physics_srv.response.gravity.x,
                 get_physics_srv.response.gravity.y,
                 get_physics_srv.response.gravity.z);
    }
    else
    {
        ROS_ERROR("Failed to call service get_physics_properties");
        return 1;
    }

    // Cliente para establecer nuevas propiedades físicas
    ros::ServiceClient set_physics_client = nh.serviceClient<gazebo_msgs::SetPhysicsProperties>("/gazebo/set_physics_properties");
    gazebo_msgs::SetPhysicsProperties set_physics_srv;
    
    int flag=0;
    double angle_radians=0;
    ros::Rate rate(10);
    
     while (ros::ok())
    {
    
    
    double sine_value = -fabs(sin(angle_radians)*200);
     /*
     if(flag<9)
     {
    
         // Configurar nuevas propiedades físicas (copiamos las actuales y modificamos la gravedad)
    set_physics_srv.request.time_step = get_physics_srv.response.time_step;
    set_physics_srv.request.max_update_rate = get_physics_srv.response.max_update_rate;
    set_physics_srv.request.gravity.x = 0.0;
    set_physics_srv.request.gravity.y = 0.0;
    set_physics_srv.request.gravity.z = -200; // Gravedad de la luna
    set_physics_srv.request.ode_config = get_physics_srv.response.ode_config;
    }
    
    else
    {
    flag=0;
        // Configurar nuevas propiedades físicas (copiamos las actuales y modificamos la gravedad)
    set_physics_srv.request.time_step = get_physics_srv.response.time_step;
    set_physics_srv.request.max_update_rate = get_physics_srv.response.max_update_rate;
    set_physics_srv.request.gravity.x = 0.0;
    set_physics_srv.request.gravity.y = 0.0;
    set_physics_srv.request.gravity.z = 0.0; // Gravedad de la luna
    set_physics_srv.request.ode_config = get_physics_srv.response.ode_config;
    }
    */
    
      set_physics_srv.request.time_step = get_physics_srv.response.time_step;
    set_physics_srv.request.max_update_rate = get_physics_srv.response.max_update_rate;
    set_physics_srv.request.gravity.x = 0.0;
    set_physics_srv.request.gravity.y = 0.0;
    set_physics_srv.request.gravity.z = sine_value; 
    set_physics_srv.request.ode_config = get_physics_srv.response.ode_config;
    
    
     if (set_physics_client.call(set_physics_srv))
    {
        ROS_INFO("Gravity changed successfully to x=%.2f, y=%.2f, z=%.2f",
                 set_physics_srv.request.gravity.x,
                 set_physics_srv.request.gravity.y,
                 set_physics_srv.request.gravity.z);
    }
    
    if(angle_radians>360) angle_radians=0;
    angle_radians++;
   
 
       // Sleep for the remaining time to let us hit our 1 Hz rate
        rate.sleep();
        //flag++;
        
    }	


   
    
 

  
    return 0;
}
