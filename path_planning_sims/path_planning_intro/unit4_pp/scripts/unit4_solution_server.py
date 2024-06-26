#!/usr/bin/env python

"""
ROS service server node for Rapidly-Exploring Random Trees (RRT's)
Author: Roberto Zegers R.
Copyright: Copyright (c) 2021, Roberto Zegers R.
License: BSD-3-Clause
Date: March 2021
"""
import sys
import rospy
import numpy as np
from pp_msgs.srv import PathPlanningPlugin, PathPlanningPluginResponse
from geometry_msgs.msg import Twist
from treeviz import TreeViz
from unit4_exercise_solution import rrt

 
def make_plan(req):
  ''' 
  Callback function used by the service server to process requests.
  It returns a PathPlanningPluginResponse
  '''
  # Convert costmap from a 1-D tuple flat map representation
  map = list(req.costmap_ros)
  # Change values on the map from unknown to free space
  map[map==255] = 1
  width = req.width
  height = req.height
  x1,y1,z1,x2,y2,z2,z3= np.loadtxt("/home/juanmat/catkin_ws/src/path_planning_sims/path_planning_intro/unit4_pp/maps/map_coords.txt", dtype=int, delimiter =',',unpack=True) 
  
  start_index = y1*width +x1;
  goal_index =  y2*width +x2;
  # side of each grid map square in meters
  map_resolution = 2.0
  # origin of grid map (bottom left pixel) w.r.t. world coordinates (Rviz's origin)
  map_origin = [0.0, 0.0]
  #map_origin = [-20.0, -20.0]

  #initial_position = indexToGridCell(start_index, width)
  #target_position = indexToGridCell(goal_index, width)
  
  #y1=abs(y1-height)
  #y2=abs(y2-height)
  initial_position = [x1,y1] 
  target_position =  [x2,y2]
  viz = TreeViz(map_resolution, map_origin, id=1, frame="map")

  # time statistics
  print("\n")
  #rospy.logwarn("Start:[%d,%d] Goal:[%d,%d] ",x1,y1,x2,y2)
  #rospy.logwarn("width: %d height: %d",width,height)
  #rospy.logwarn("REALstart: %s REALgoal: %s",initial_position,target_position)
  #rospy.logwarn("REALstart: %d REALgoal: %d",req.start,req.goal)
  #rospy.logwarn("initial_position: %d target_position: %d",initial_position,target_position)
  print("\n")	
  
    # time statistics
  start_time = rospy.Time.now()
  
  # Calculate a path using RRT
  path = rrt(initial_position, target_position, width, height, map, map_resolution, map_origin, viz)

  if not path:
    rospy.logwarn("No path returned by RRT")
    return_path = []
  else:
    # print time statistics
    execution_time = rospy.Time.now() - start_time
    print("\n")
    rospy.loginfo('+++++++++++ RRT execution metrics ++++++++++')
    rospy.loginfo('Total execution time: %s seconds', str(execution_time.to_sec()))
    rospy.loginfo('++++++++++++++++++++++++++++++++++++++++++++')
    print("\n")
    rospy.loginfo('RRT: Path sent to navigation stack')
    
    return_path = []
    for cell in path:
        return_path.append(cell[0]+width*cell[1])

  resp = PathPlanningPluginResponse()
  resp.plan = return_path
  #sys.exit() 
  return resp

def clean_shutdown():
  cmd_vel.publish(Twist())
  rospy.sleep(1)

def indexToGridCell(flat_map_index, map_width):
  """
  Converts a linear index of a flat map to grid cell coordinate values
  flat_map_index: a linear index value, specifying a cell/pixel in an 1-D array
  map_width: the map's width 
  returns: list with [x,y] grid cell coordinates
  """
  grid_cell_map_x = flat_map_index % map_width
  grid_cell_map_y = flat_map_index // map_width
  return [grid_cell_map_x, grid_cell_map_y]

if __name__ == '__main__':
  rospy.init_node('rrt_path_planning_service_server', log_level=rospy.INFO, anonymous=False)
  make_plan_service = rospy.Service("/move_base/SrvClientPlugin/make_plan", PathPlanningPlugin, make_plan)
  cmd_vel = rospy.Publisher('/cmd_vel', Twist, queue_size=5)
  rospy.on_shutdown(clean_shutdown)
  
  while not rospy.core.is_shutdown():
    rospy.rostime.wallsleep(0.5)
  rospy.Timer(rospy.Duration(2), rospy.signal_shutdown('Shutting down'), oneshot=True)
