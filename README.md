Este repositorio contiene tres paquetes para la planificación de trayectorias en navegación en exteriores de una flota de cuatro robots de la compañía Robotnik.

En primer lugar, el paquete cv_gdal permite elaborar un mapa binarion de ocupación. Para ello, se debe ejecutar el comando:
`roslaunch cv_gdal cv_gdal.launch`

Una vez elaborado el mapa se procede a la planificación de trayectorias sobre el mismo. En este caso, se hace uso del paquete path_planning_sims, elaborado a partir del código de Roberto Zegers R.
Este paquete permite calcular la trayectoria utilizando distintos algoritmos de planificación. 

Para usar el A*: `roslaunch path_planning_sims unit3_astar_solution.launch`

Para usar el D*: `roslaunch path_planning_sims unit3_dijkstra.launch`

Para usar el GBFS: `roslaunch path_planning_sims unit3_gbfs_solution.launch`

Para usar el RRT: `roslaunch path_planning_sims unit4_solution.launch`

El último paquete manda esta trayectoria a la flota de robots para su navegación autónoma, que se controlará mediante los dos siguientes comandos:

`rosrun simple_navigation_goals simple_navigation_goals`

`rosrun simple_navigation_goals odom_listener`

Adicionalmente se debe hacer uso de los paquetes del summit xl que proporciona la compañía:

https://github.com/RobotnikAutomation/summit_xl_sim

Estos paquetes han sido modificados para los propósitos de este proyecto y se pueden encontrar en:

https://github.com/JUAN-j1/summit_xl_sim

https://github.com/JUAN-j1/summit_xl_common

