# Path Planning Exercises Repository

Author: Roberto Zegers R.  
Date: November 2020  
License: BSD-3-Clause  


## Important note: 

After the course update from 'Kinetic' to 'Noetic' we remove these two packages from the course docker image:  

- osm_cartography
- route_network  

This is because they are using Python 2 and this conflicts with ROS Noetic which uses Python 3.  
These two packages are only used on the final project.  

The new project instructions state to clone this repository from The Construct's bitbucket account into  `~/catkin_ws/src`:  

```
git clone https://bitbucket.org/theconstructcore/open_street_map.git
```

This repository contains the package `osm_cartography`` and `route_network` ported to Python3.   



