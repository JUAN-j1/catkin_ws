Este repositorio contiene tres paquetes para la planificación de trayectorias en navegación de una flota de cuatro robots summitde la compañía Robotnik.

En primer lugar, el paquete cv_gdal permite elaborar un mapa binarion de ocupación. Para ello, se debe ejecutar el comando:
`roslaunch cv_gdal cv_gdal.launch`

Una vez elaborado el mapa se procede a la planificación de trayectorias. En este caso, se hace uso del paquete path_planning_sims, elaborado por Roberto Zegers R.
Este paquete permite calcular la trayectoria utilizando distintos algoritmos de planificación. 

Para usar el A*: `unit3_astar_solution.launch`

Para usar el D*: `unit3_dijkstra.launch`

Para usar el GBFS: `unit3_gbfs_solution.launch`

Para usar el RRT: `unit4_solution.launch`

El último paquete manda esta trayectoria a la flota de robots para su navegación autónoma. Una vez iniciada la simulación en gazebo a través del comando:
`mega_gpps.launch`, se controlará la navegación autónoma mediante los siguientes comandos:

`rosrun simple_navigation_goals simple_navigation_goals`
`rosrun simple_navigation_goals odom_listener`

Este repositorio se debe ejectuar de forma conjunta con los paquetes para el control del robot summit.




