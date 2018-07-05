cmake_minimum_required(VERSION 2.8.3)
project(access_pointcloud)

####################
# Find dependecies #
####################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)


###################################
## catkin specific configuration ##
###################################

catkin_package(
              )

###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS} 
                   )

 add_executable(access_pointcloud 
                src/access_pointcloud.cpp
               )

 target_link_libraries(access_pointcloud
                       ${catkin_LIBRARIES}
                      )


