#! /usr/bin/env python

import rospy
from nav_msgs.msg import Odometry

def callback(msg);
print msg.pose.pose.position;

rospy.init_node('check_odometry');
odom_sub=rospy.Subscriber('/robot/robotnik_base_control/odom', Odometry);

rospy.spin();
