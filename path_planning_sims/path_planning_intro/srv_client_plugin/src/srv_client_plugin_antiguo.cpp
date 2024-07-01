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


void	  rio_tinto_2d_world(int x1,int y1,int oz1)
{
		fprintf(fp5,"<sdf version='1.6'>\n");
		fprintf(fp5,"<world name='default'> \n");
		fprintf(fp5,"<scene>\n");  
		fprintf(fp5,"<shadows> false </shadows>\n");
		fprintf(fp5,"<ambient>0.4 0.4 0.4 1.0</ambient>\n");
		fprintf(fp5,"<background>0.290 0.337 0.560 0.7</background>\n");
		fprintf(fp5,"<grid>false</grid>\n");
		fprintf(fp5,"<sky>\n");
		fprintf(fp5,"<time>17</time>\n");
		fprintf(fp5,"<sunrise>15</sunrise>\n");
		fprintf(fp5,"<sunset>18</sunset>\n");
		fprintf(fp5,"<clouds>\n");
		fprintf(fp5,"<humidity>0.01</humidity>\n");
		fprintf(fp5,"</clouds>\n");
		fprintf(fp5,"</sky>\n");
		fprintf(fp5,"</scene>\n");  
		fprintf(fp5,"<physics type='ode'>\n");
		fprintf(fp5,"<gravity>0 0 -9.8</gravity>\n");
		fprintf(fp5,"<scene>\n");
		fprintf(fp5,"<shadows> false </shadows>\n");
		fprintf(fp5,"<ambient>0.4 0.4 0.4 1.0</ambient>\n");
		fprintf(fp5,"<background>0.290 0.337 0.560 0.7</background>\n");
		fprintf(fp5,"<grid>false</grid>\n");
		fprintf(fp5,"<sky>\n");
		fprintf(fp5,"<time>17</time>\n");
		fprintf(fp5,"<sunrise>15</sunrise>\n");
		fprintf(fp5,"<sunset>18</sunset>\n");
		fprintf(fp5,"<clouds>\n");
		fprintf(fp5,"<humidity>0.01</humidity>\n");
		fprintf(fp5,"</clouds>\n");
		fprintf(fp5,"</sky>\n");
		fprintf(fp5,"</scene>\n");
		fprintf(fp5,"<ode>\n");
		fprintf(fp5,"<solver>\n");
		fprintf(fp5,"<!--type>quick</type>\n");
		fprintf(fp5,"<dt>0.001</dt>\n");
		fprintf(fp5,"<iters>40</iters>\n");
		fprintf(fp5,"<sor>1.0</sor -->\n");
		fprintf(fp5,"<!-- type>quick</type>\n");
   		fprintf(fp5,"<dt>0.01</dt>\n");
	        fprintf(fp5,"<iters>20</iters>\n");
   		fprintf(fp5,"<sor>1.0</sor -->\n");
   		fprintf(fp5,"<type>quick</type>\n");
		fprintf(fp5,"<!--dt>0.001</dt-->\n");
		fprintf(fp5,"<iters>20</iters>\n");
		fprintf(fp5,"<sor>1.0</sor>\n");
		fprintf(fp5,"</solver>\n");
		fprintf(fp5,"<constraints>\n");
		fprintf(fp5,"<cfm>0.0</cfm>\n");
		fprintf(fp5,"<erp>0.2</erp>\n");
		fprintf(fp5,"<contact_max_correcting_vel>100.0</contact_max_correcting_vel>\n");
		fprintf(fp5,"<contact_surface_layer>0.0</contact_surface_layer>\n");
		fprintf(fp5,"</constraints>\n");
	        fprintf(fp5,"</ode>\n");
		fprintf(fp5,"<max_step_size>0.001</max_step_size>\n");
		fprintf(fp5,"</physics>\n");
		fprintf(fp5,"<include>\n");
		fprintf(fp5,"<uri>model://sun</uri>\n");
		fprintf(fp5,"</include>\n");
		fprintf(fp5,"<include>\n");
		fprintf(fp5,"<uri>model://map_satellite_rio_tinto</uri>\n");
		fprintf(fp5,"<pose>  %f %f %f 0 0 0</pose>\n",float((1361)-(2*x1)),float((787)-(2*y1)),0.0);
		fprintf(fp5,"</include>\n");
		fprintf(fp5,"</world>\n");
		fprintf(fp5,"</sdf>\n");
}

void	  rio_tinto_3d_world_blender(int x1,int y1,int oz1)
{
//715,722: la cabrera 1361,787: rio tinto
	  
	  fprintf(fp3,"<sdf version='1.6'>\n");
    	  fprintf(fp3,"<world name='default'>\n");
    	  fprintf(fp3," <gravity>0 0 0</gravity>\n"); 
	  fprintf(fp3,"<scene>\n");
	  fprintf(fp3,"<shadows> false </shadows>\n");
	  fprintf(fp3,"<ambient>0.4 0.4 0.4 1.0</ambient>\n");
	  fprintf(fp3,"<background>0.290 0.337 0.560 0.7</background>\n");
	  fprintf(fp3,"<grid>false</grid>\n");
	  fprintf(fp3,"<sky>\n");
	  fprintf(fp3,"<time>17</time>\n");
	  fprintf(fp3,"<sunrise>15</sunrise>\n");
	  fprintf(fp3,"<sunset>18</sunset>\n");
	  fprintf(fp3,"<clouds>\n");
	  fprintf(fp3,"<humidity>0.01</humidity>\n");
	  fprintf(fp3,"</clouds>\n");
	  fprintf(fp3,"</sky>\n");
	  fprintf(fp3,"</scene>\n");
      	  fprintf(fp3,"<include>\n");
	  fprintf(fp3,"<uri>model://sun</uri>\n");
	  fprintf(fp3,"</include>\n");
      	  fprintf(fp3,"<include>\n");
    	  fprintf(fp3,"<name>terrain_1</name>\n");
      	  fprintf(fp3,"<uri>model://terrain_1</uri>\n");
	  fprintf(fp3,"<pose> %f %f %f 0 0 0</pose>\n",float((1361)-(2*x1)),float((787)-(2*y1)),float(-oz1)); //715,722: la cabrera 1361,787: rio tinto
	  fprintf(fp3,"</include>\n");
	  fprintf(fp3,"<gui fullscreen='0'>\n");
    	  fprintf(fp3,"<camera name='user_camera'>\n");
      	  fprintf(fp3,"<pose frame=''>9.0 -12.0 6.0 0.0 0.3 2.2</pose>\n");
	  fprintf(fp3,"<view_controller>orbit</view_controller>\n");
	  fprintf(fp3,"<projection_type>perspective</projection_type>\n");
	  fprintf(fp3,"</camera>\n");
	  fprintf(fp3,"</gui>\n");
	  fprintf(fp3,"</world>\n");
	  fprintf(fp3,"</sdf>\n");    
}

void	  rio_tinto_3d_world_gazebo(int x1,int y1,int oz1)
{
//715,722: la cabrera 1361,787: rio tinto
	  
fprintf(fp6,"<?xml version='1.0' ?>\n");
fprintf(fp6,"<sdf version='1.4'>\n");
fprintf(fp6,"<world name='default'>\n");
fprintf(fp6,"<gravity>0 0 0</gravity>\n");

fprintf(fp6,"<scene>\n");
fprintf(fp6,"<shadows> false </shadows>\n");
fprintf(fp6,"<ambient>0.4 0.4 0.4 1.0</ambient>\n");
fprintf(fp6,"<background>0.290 0.337 0.560 0.7</background>\n");
fprintf(fp6,"<grid>false</grid>\n");
fprintf(fp6,"<sky>\n");
fprintf(fp6,"<time>17</time>\n");
fprintf(fp6,"<sunrise>15</sunrise>\n");
fprintf(fp6,"<sunset>18</sunset>\n");
fprintf(fp6,"<clouds>\n");
fprintf(fp6,"<humidity>0.01</humidity>\n");
fprintf(fp6,"</clouds>\n");
fprintf(fp6,"</sky>\n");
fprintf(fp6,"</scene>\n");


fprintf(fp6,"<include>\n");
fprintf(fp6,"<uri>model://sun</uri>\n");
fprintf(fp6,"</include>\n");

fprintf(fp6,"<model name='heightmap'>\n");
fprintf(fp6,"<static>true</static>\n");
fprintf(fp6,"<link name='link'>\n");
fprintf(fp6,"<collision name='collision'>\n");
fprintf(fp6,"<geometry>\n");
fprintf(fp6,"<heightmap>\n");
fprintf(fp6,"<uri>file://rio_tinto/output_dem3.tif</uri>\n");
fprintf(fp6,"<size>1574 1574 242</size>\n");
//fprintf(fp6,"<pos> %f %f %f 0 0 0</pos>\n",float((787)-(2*x1)),float((787)-(2*y1)),float(-oz1)); //715,722: la cabrera 1361,787: rio tinto
fprintf(fp6,"<pos> 0 0 0 0 0 0</pos>\n");
fprintf(fp6,"</heightmap>\n");
fprintf(fp6,"</geometry>\n");
fprintf(fp6,"</collision>\n");

fprintf(fp6,"<visual name='visual_abcedf'>\n");
fprintf(fp6," <geometry>\n");
fprintf(fp6,"<heightmap> \n");
fprintf(fp6,"  <texture> \n");
fprintf(fp6,"   <diffuse>file://rio_tinto/output_image2.png</diffuse>\n");
fprintf(fp6,"   <normal>file://rio_tinto/output_image2.png </normal> \n");
fprintf(fp6,"  <size>1574 </size>\n");
fprintf(fp6," </texture>\n");

fprintf(fp6,"<texture>\n");
fprintf(fp6,"<diffuse>file://rio_tinto/output_image2.png</diffuse>\n");
fprintf(fp6,"<normal>file://rio_tinto/output_image2.png</normal>\n");
fprintf(fp6,"<size>1574 </size>\n");
fprintf(fp6,"</texture>\n");

fprintf(fp6,"<texture>\n");
fprintf(fp6,"<diffuse>file://rio_tinto/output_image2.png</diffuse> \n");
fprintf(fp6,"<normal>file://rio_tinto/output_image2.png</normal>\n");
fprintf(fp6,"<size>1574  </size>\n");
fprintf(fp6,"</texture>\n");

fprintf(fp6,"<blend>\n");
fprintf(fp6,"<min_height>2</min_height>\n");
fprintf(fp6,"<fade_dist>0.1</fade_dist>\n");
fprintf(fp6,"</blend>\n");
fprintf(fp6,"<blend>\n");
fprintf(fp6,"<min_height>2</min_height>\n");
fprintf(fp6,"<fade_dist>0.1</fade_dist>\n");
fprintf(fp6,"</blend>\n");

fprintf(fp6,"<uri>file://rio_tinto/output_dem3.tif</uri>\n");
fprintf(fp6,"<size>1574 1574 242</size>\n");
//fprintf(fp6,"<pos> %f %f %f 0 0 0</pos>\n",float((787)-(2*x1)),float((787)-(2*y1)),float(-oz1)); //715,722: la cabrera 1361,787: rio tinto
fprintf(fp6,"<pos> 0 0 0 0 0 0</pos>\n"); 
fprintf(fp6,"</heightmap>\n");
fprintf(fp6,"</geometry>\n");
fprintf(fp6,"</visual>\n");
fprintf(fp6,"</link>\n");
fprintf(fp6,"</model>\n");
fprintf(fp6,"</world>\n");
fprintf(fp6,"</sdf>\n");

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
        fp5 = fopen( "/home/juanmat/catkin_summit_xl/src/summit_xl_sim/summit_xl_gazebo/worlds/rio_tinto_2D.world","w");
        fp6 = fopen( "/home/juanmat/catkin_summit_xl/src/summit_xl_sim/summit_xl_gazebo/worlds/rio_tinto_3D.world","w");
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

	  rio_tinto_2d_world(x1,y1,oz1);
  	  rio_tinto_3d_world_blender(x1,y1,oz1);
  	  rio_tinto_3d_world_gazebo(x1,y1,oz1);
	  /*
    	  fprintf(fp3,"<sdf version='1.6'>\n");
    	  fprintf(fp3,"<world name='default'>\n");
    	  fprintf(fp3," <gravity>0 0 0</gravity>\n");
      	  fprintf(fp3,"<include>\n");
	  fprintf(fp3,"<uri>model://sun</uri>\n");
	  fprintf(fp3,"</include>\n");
	  
      	  fprintf(fp3,"<include>\n");
    	  fprintf(fp3,"<name>terrain_1</name>\n");
      	  fprintf(fp3,"<uri>model://terrain_1</uri>\n");
	  fprintf(fp3,"<pose> %f %f %f 0 0 0</pose>\n",float((1361/2)-(x1/2)),float((787/2)-(y1/2)),float(-oz1)); //715,722: la cabrera 1361,787: rio tinto
	  fprintf(fp3,"</include>\n");
  
	  fprintf(fp3,"<gui fullscreen='0'>\n");
    	  fprintf(fp3,"<camera name='user_camera'>\n");
      	  fprintf(fp3,"<pose frame=''>9.0 -12.0 6.0 0.0 0.3 2.2</pose>\n");
	  fprintf(fp3,"<view_controller>orbit</view_controller>\n");
	  fprintf(fp3,"<projection_type>perspective</projection_type>\n");
	  fprintf(fp3,"</camera>\n");
	  fprintf(fp3,"</gui>\n");
	  fprintf(fp3,"</world>\n");
	  fprintf(fp3,"</sdf>\n");    
	  */
    	 
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
