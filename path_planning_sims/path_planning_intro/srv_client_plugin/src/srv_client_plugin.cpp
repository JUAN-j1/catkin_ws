#include <pluginlib/class_list_macros.h>
#include <srv_client_plugin.h>
#include <ros/console.h>
#include <nav_msgs/Path.h>
#include <math.h>

//int x1,y1,oz1,x2,y2,oz2,oz3;
FILE *fp;
FILE *fp2;
FILE *fp3;
FILE *fp4;
FILE *fp5;
FILE *fp6;
FILE *fp7;

// register this planner as a BaseGlobalPlanner plugin
PLUGINLIB_EXPORT_CLASS(srv_client_plugin::SrvClientPlugin, nav_core::BaseGlobalPlanner)

namespace srv_client_plugin
{

  SrvClientPlugin::SrvClientPlugin()
  {
    initialized_ = false;
  }

  SrvClientPlugin::SrvClientPlugin(std::string name, costmap_2d::Costmap2DROS *costmap_ros)
  {
    initialized_ = false;
    initialize(name, costmap_ros);
  }

  void SrvClientPlugin::initialize(std::string name, costmap_2d::Costmap2DROS *costmap_ros)
  {
    if (!initialized_)
    {
      ros::NodeHandle private_nh("~/" + name);
      costmap_ros_ = costmap_ros;
      costmap_ = costmap_ros->getCostmap();
      origin_x_ = costmap_->getOriginX();
      origin_y_ = costmap_->getOriginY();

      width_ = costmap_->getSizeInCellsX();
      height_ = costmap_->getSizeInCellsY();
      resolution_ = costmap_->getResolution();
      map_size_ = width_ * height_;

      // create a client for the path planning service
      makeplan_service_ = private_nh.serviceClient<pp_msgs::PathPlanningPlugin>("make_plan");
      // wait for the service to be advertised and available, blocks until it is.
      makeplan_service_.waitForExistence();
      // create publisher to display the complete trajectory path in RVIZ
      plan_pub_ = private_nh.advertise<nav_msgs::Path>("plan", 1);

      // place path waypoints at the center of each grid cell (vs. at the corners of grid cells)
      path_at_node_center = true;
      if (path_at_node_center)
      {
        // shift all of the coordinates by half a grid cell
        node_center_offset_ = resolution_ / 2;
      }

      initialized_ = true;
    }
  }


void	  mega_timanfaya_world(int x1,int y1,int oz1)
{
//715:la cabrera // 787:rio tinto // 785: timanfaya	
fprintf(fp7,"<?xml version='1.0'?> \n");
fprintf(fp7,"<launch> \n");
fprintf(fp7,"<include file='$(find summit_xl_sim_bringup)/launch/summit_xl_gps_complete.launch'> \n");
fprintf(fp7,"<arg name='gazebo_world' value='$(find summit_xl_gazebo)/worlds/timanfaya_3D.world'/> \n");
fprintf(fp7,"\n");
fprintf(fp7,"<arg name='x_init_pose_a' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp7,"<arg name='y_init_pose_a' value='%f ' /> \n",float((785)-(2*y1)) );
fprintf(fp7,"<arg name='z_init_pose_a' value='%f ' /> \n",0.0);
fprintf(fp7,"\n");
fprintf(fp7,"<arg name='x_init_pose_b' value='%f ' /> \n",float((785)-(2*x1)) -4 );
fprintf(fp7,"<arg name='y_init_pose_b' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp7,"<arg name='z_init_pose_b' value='%f ' /> \n",0.0);
fprintf(fp7,"\n");
fprintf(fp7,"<arg name='x_init_pose_c' value='%f ' /> \n",float((785)-(2*x1))-8 );
fprintf(fp7,"<arg name='y_init_pose_c' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp7,"<arg name='z_init_pose_c' value='%f ' /> \n",0.0);
fprintf(fp7,"\n");
fprintf(fp7,"<arg name='x_init_pose_d' value='%f ' /> \n",float((785)-(2*x1)) -12);
fprintf(fp7,"<arg name='y_init_pose_d' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp7,"<arg name='z_init_pose_d' value='%f ' /> \n",0.0);
fprintf(fp7,"\n");
fprintf(fp7,"</include> \n");
fprintf(fp7,"<include file='$(find summit_xl_localization)/launch/map_server.launch'> \n");
fprintf(fp7,"<arg name='map_file' value='real/unitX_map.yaml'/> \n");
fprintf(fp7,"</include> \n");
fprintf(fp7,"<include file='$(find summit_xl_localization)/launch/navsat_transform_node.launch'> \n");
fprintf(fp7,"</include> \n");
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster'  args='%f %f %f 0 0 0  robot_map robot_odom 100' /> \n",-float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster1'  args='%f %f %f 0 0 0  robot_b_map robot_b_odom 100' /> \n",-float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster2'  args='%f %f %f 0 0 0  robot_c_map robot_c_odom 100' /> \n",-float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster3'  args='%f %f %f 0 0 0  robot_d_map robot_d_odom 100' /> \n",-float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp7,"\n");
fprintf(fp7," <node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster4' args='0 0 0 0 0 0 robot_map robot_b_map 100' /> \n");
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster5' args='0 0 0 0 0 0 robot_map robot_c_map 100' /> \n");
fprintf(fp7,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster6' args='0 0 0 0 0 0 robot_map robot_d_map 100' /> \n");
fprintf(fp7,"\n");
fprintf(fp7,"	</launch> \n");

}

void	  mega_rio_tinto_world(int x1,int y1,int oz1)
{
//715:la cabrera // 787:rio tinto // 785: timanfaya	
fprintf(fp5,"<?xml version='1.0'?> \n");
fprintf(fp5,"<launch> \n");
fprintf(fp5,"<include file='$(find summit_xl_sim_bringup)/launch/summit_xl_gps_complete.launch'> \n");
fprintf(fp5,"<arg name='gazebo_world' value='$(find summit_xl_gazebo)/worlds/timanfaya_3D.world'/> \n");

fprintf(fp5,"<arg name='x_init_pose_a' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp5,"<arg name='y_init_pose_a' value='%f ' /> \n",float((785)-(2*y1)) );
fprintf(fp5,"<arg name='z_init_pose_a' value='%f ' /> \n",0.0);

fprintf(fp5,"<arg name='x_init_pose_b' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp5,"<arg name='y_init_pose_b' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp5,"<arg name='z_init_pose_b' value='%f ' /> \n",0.0);

fprintf(fp5,"<arg name='x_init_pose_c' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp5,"<arg name='y_init_pose_c' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp5,"<arg name='z_init_pose_c' value='%f ' /> \n",0.0);

fprintf(fp5,"<arg name='x_init_pose_d' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp5,"<arg name='y_init_pose_d' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp5,"<arg name='z_init_pose_d' value='%f ' /> \n",0.0);

fprintf(fp5,"</include> \n");
fprintf(fp5,"<include file='$(find summit_xl_localization)/launch/map_server.launch'> \n");
fprintf(fp5,"<arg name='map_file' value='real/unitX_map.yaml'/> \n");
fprintf(fp5,"</include> \n");
fprintf(fp5,"<include file='$(find summit_xl_localization)/launch/navsat_transform_node.launch'> \n");
fprintf(fp5,"</include> \n");
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster'  args='%f %f %f 0 0 0  robot_map robot_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster1'  args='%f %f %f 0 0 0  robot_b_map robot_b_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster2'  args='%f %f %f 0 0 0  robot_c_map robot_c_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster3'  args='%f %f %f 0 0 0  robot_d_map robot_d_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);

fprintf(fp5," <node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster4' args='0 0 0 0 0 0 robot_map robot_b_map 100' /> \n");
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster5' args='0 0 0 0 0 0 robot_map robot_c_map 100' /> \n");
fprintf(fp5,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster6' args='0 0 0 0 0 0 robot_map robot_d_map 100' /> \n");

fprintf(fp5,"	</launch> \n");

}

void	  mega_lacabrera_world(int x1,int y1,int oz1)
{
//715:la cabrera // 787:rio tinto // 785: timanfaya	
fprintf(fp6,"<?xml version='1.0'?> \n");
fprintf(fp6,"<launch> \n");
fprintf(fp6,"<include file='$(find summit_xl_sim_bringup)/launch/summit_xl_gps_complete.launch'> \n");
fprintf(fp6,"<arg name='gazebo_world' value='$(find summit_xl_gazebo)/worlds/timanfaya_3D.world'/> \n");

fprintf(fp6,"<arg name='x_init_pose_a' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp6,"<arg name='y_init_pose_a' value='%f ' /> \n",float((785)-(2*y1)) );
fprintf(fp6,"<arg name='z_init_pose_a' value='%f ' /> \n",0.0);

fprintf(fp6,"<arg name='x_init_pose_b' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp6,"<arg name='y_init_pose_b' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp6,"<arg name='z_init_pose_b' value='%f ' /> \n",0.0);

fprintf(fp6,"<arg name='x_init_pose_c' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp6,"<arg name='y_init_pose_c' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp6,"<arg name='z_init_pose_c' value='%f ' /> \n",0.0);

fprintf(fp6,"<arg name='x_init_pose_d' value='%f ' /> \n",float((785)-(2*x1)) );
fprintf(fp6,"<arg name='y_init_pose_d' value='%f ' /> \n",float((785)-(2*y1)));
fprintf(fp6,"<arg name='z_init_pose_d' value='%f ' /> \n",0.0);

fprintf(fp6,"</include> \n");
fprintf(fp6,"<include file='$(find summit_xl_localization)/launch/map_server.launch'> \n");
fprintf(fp6,"<arg name='map_file' value='real/unitX_map.yaml'/> \n");
fprintf(fp6,"</include> \n");
fprintf(fp6,"<include file='$(find summit_xl_localization)/launch/navsat_transform_node.launch'> \n");
fprintf(fp6,"</include> \n");
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster'  args='%f %f %f 0 0 0  robot_map robot_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster1'  args='%f %f %f 0 0 0  robot_b_map robot_b_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster2'  args='%f %f %f 0 0 0  robot_c_map robot_c_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster3'  args='%f %f %f 0 0 0  robot_d_map robot_d_odom 100' /> \n",float((785)-(2*x1)),float((785)-(2*y1)),0.0);

fprintf(fp6," <node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster4' args='0 0 0 0 0 0 robot_map robot_b_map 100' /> \n");
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster5' args='0 0 0 0 0 0 robot_map robot_c_map 100' /> \n");
fprintf(fp6,"<node pkg='tf' type='static_transform_publisher' name='static_map_broadcaster6' args='0 0 0 0 0 0 robot_map robot_d_map 100' /> \n");

fprintf(fp6,"	</launch> \n");

}


    // fill plan request, call plan service, process plan response
    bool SrvClientPlugin::makePlan(const geometry_msgs::PoseStamped &start, const geometry_msgs::PoseStamped &goal, std::vector<geometry_msgs::PoseStamped> &plan)
    {
      plan.clear();

      // Fill costmap (costmap is a 1-D array map representation)
      std::vector<int> costmap(map_size_);

      for (size_t idx = 0; idx < map_size_; ++idx)
      {
        int x, y;
        x = idx % width_;
        y = std::floor(idx / width_);
        costmap.at(idx) = static_cast<int>(costmap_->getCost(x, y));
      }

      float start_x = start.pose.position.x;
      float start_y = start.pose.position.y;
      float goal_x = goal.pose.position.x;
      float goal_y = goal.pose.position.y;

      size_t start_index = 0;
      size_t goal_index = 0;

      // check if start/goal world coordinates are inside  grid map bounds
      if (InGridMapBounds(start_x, start_y) && InGridMapBounds(goal_x, goal_y))
      {
        // convert x,y in world coordinates/meters) to x,y in grid map cell coordinates
        FromWorldToGrid(start_x, start_y);
        FromWorldToGrid(goal_x, goal_y);

        // convert 2d representation into flat array index representation
        start_index = ToIndex(start_x, start_y);
        goal_index = ToIndex(goal_x, goal_y);
      }
      else
      {
        ROS_WARN("Start or goal position outside of the map's boundaries");
        return false;
      }

      // To-Do: check that a start and goal are not obstacles

      pp_msgs::PathPlanningPlugin makeplan;
      makeplan.request.costmap_ros = costmap;
      makeplan.request.start = start_index;
      makeplan.request.goal = goal_index;
      makeplan.request.width = width_;
      makeplan.request.height = height_;

      // call path planning service
      makeplan_service_.call(makeplan);

      std::vector<int> index_plan = makeplan.response.plan;

      ROS_DEBUG("Number of points: %d", unsigned(index_plan.size()));

      /* Process plan response */
      if (index_plan.size())
      {
        // insert start node into plan response
        
        index_plan.insert(index_plan.begin(), start_index);
        // insert goal node into plan response
        // index_plan.push_back(goal_index);
        //FILE *fp;
        //FILE *fp2;
        //FILE *fp3;
        //FILE *fp4;
        
        fp = fopen( "/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_path.txt","w");
        fp2 = fopen("/home/juanmat/catkin_summit_xl/src/summit_xl_common/summit_xl_localization/maps/real/unitX_map.yaml","w");
        fp3 = fopen( "/home/juanmat/catkin_ws/src/gazebo_terrain_tutorial/worlds/terrain_1.world","w");
        fp4 = fopen( "/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_coords.txt","r");
        
        fp5 = fopen( "/home/juanmat/catkin_summit_xl/src/summit_xl_sim/summit_xl_sim_bringup/launch/mega_gps_rio_tinto.launch","w");
        fp6 = fopen( "/home/juanmat/catkin_summit_xl/src/summit_xl_sim/summit_xl_sim_bringup/launch/mega_gps_lacabrera.launch","w");
        fp7 = fopen( "/home/juanmat/catkin_summit_xl/src/summit_xl_sim/summit_xl_sim_bringup/launch/mega_gps_timanfaya.launch","w");
        
        fprintf(fp,"INDEX\tGRID\tWORLD\n");
       
     int cont =0;
        
        for (int p : index_plan)
        {
          cont++;
          int x, y;
          fprintf(fp,"%d\t",p);
          FromIndex(p, x, y);
          float x_path = static_cast<float>(x);
          float y_path = static_cast<float>(y);
	  fprintf(fp,"%f,%f\t",2*x_path,2*y_path);
	  if(cont==2)
	  {
	  fprintf(fp2,"image: unitX_map.pgm\n");
  	  fprintf(fp2,"resolution: 2\n");
  	  fprintf(fp2,"origin: [-%f, -%f, 0.0] \n",2*x_path,2*y_path);
  	  fprintf(fp2,"negate: 0\n");
  	  fprintf(fp2,"occupied_thresh: 0.65\n");
    	  fprintf(fp2,"free_thresh: 0.196\n");
    	  
    	  int x1,y1,oz1,x2,y2,oz2,oz3;
	  fscanf(fp4,"%d,%d,%d,",&x1,&y1,&oz1); 
	  fscanf(fp4,"%d,%d,%d,%d",&x2,&y2,&oz2,&oz3); 

	  mega_timanfaya_world(x1,y1,oz1);
  	  mega_rio_tinto_world(x1,y1,oz1);
  	  mega_lacabrera_world(x1,y1,oz1);
	 
	  }
          FromGridToWorld(x_path, y_path);
          fprintf(fp,"%f,%f\n",x_path,y_path);
          geometry_msgs::PoseStamped position;
          position.header.frame_id = start.header.frame_id;
          position.pose.position.x = x_path;
          position.pose.position.y = y_path;
          position.pose.orientation.x = 0;
          position.pose.orientation.y = 0;
          position.pose.orientation.z = 0;
          position.pose.orientation.w = 1;

          plan.push_back(position);
        }
        
        fclose(fp);
        fclose(fp2);
         fclose(fp3);
          fclose(fp4);
             fclose(fp5);
              fclose(fp6);
               fclose(fp7);



        plan.push_back(goal);

        // Publish the path for visualisation
        publishPlan(plan);

        return true;
      }
    else
      {
        // no plan found
        return false;
      }
    }

    void SrvClientPlugin::publishPlan(const std::vector<geometry_msgs::PoseStamped> &path)
    {

      // create a message
      nav_msgs::Path gui_path;
      gui_path.poses.resize(path.size());

      gui_path.header.frame_id = "map";
      gui_path.header.stamp = ros::Time::now();

      // Extract the plan in world coordinates
      for (unsigned int i = 0; i < (path.size()); i++)
      {
        gui_path.poses[i] = path[i];
        
       if(i==0)  gui_path.poses[i]  = path[i+1];
       


      }

      plan_pub_.publish(gui_path);
    }
    
    

    size_t SrvClientPlugin::ToIndex(float x, float y)
    {
      return y * width_ + x;
    }

    void SrvClientPlugin::FromIndex(size_t index, int &x, int &y)
    {
      x = index % width_;
      y = std::floor(index / width_);
    }

    void SrvClientPlugin::FromWorldToGrid(float &x, float &y)
    {
      x = static_cast<size_t>((x - origin_x_) / resolution_);
      y = static_cast<size_t>((y - origin_y_) / resolution_);
    }

    void SrvClientPlugin::FromGridToWorld(float &x, float &y)
    {
      x = x * resolution_ + origin_x_ + node_center_offset_;
      y = y * resolution_ + origin_y_ + node_center_offset_;
    }

    bool SrvClientPlugin::InGridMapBounds(float &x, float &y)
    {
      if (x < origin_x_ || y < origin_y_ || x > origin_x_ + (width_ * resolution_) || y > origin_y_ + (height_ * resolution_))
        return false;
      return true;
    }

  }; // namespace srv_client_plugin
