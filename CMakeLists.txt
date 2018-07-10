cmake_minimum_required(VERSION 2.8.3)
project(access_pointcloud)

####################
# Find dependecies #
####################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
  message_generation
)


add_message_files(
  FILES
  PointXyzi.msg
)

generate_messages(
 DEPENDENCIES
 std_msgs
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  CATKIN_DEPENDS message_runtime
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

add_dependencies(access_pointcloud
                 ${catkin_EXPORTED_TARGETS}
                )
 
