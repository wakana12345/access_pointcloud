#include <ros/ros.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Float32.h>
#include <access_pointcloud/PointXyzi.h>

class access_cloud
{
  private:
  ros::Subscriber sub_cloud;
  ros::Publisher pub_point;

  access_pointcloud::PointXyzi point;

  void Callback(const sensor_msgs::PointCloud2ConstPtr& cloud)
  {
    sensor_msgs::PointCloud2ConstIterator<float> iter_x(*cloud, "x");
    sensor_msgs::PointCloud2ConstIterator<float> iter_y(*cloud, "y");
    sensor_msgs::PointCloud2ConstIterator<float> iter_z(*cloud, "z");
    sensor_msgs::PointCloud2ConstIterator<float> iter_i(*cloud, "intensity");

    for(; iter_x != iter_x.end(); ++iter_x, ++iter_y, ++iter_z, ++iter_i) 
    {
      point.x = *iter_x;
      point.y = *iter_y;
      point.z = *iter_z;
      point.i = *iter_i;

//      ROS_INFO("x %f",point.x);
//      ROS_INFO("y %f",point.y);
//      ROS_INFO("z %f",point.z);
//      ROS_INFO("i %f",point.i);
      
//      pub_point.publish(point);
    }
    pub_point.publish(point);
  }

  public:
  access_cloud()
  {
    ros::NodeHandle nh("~");
    sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("cloud",100,
                                                       &access_cloud::Callback,this);
    

    pub_point = nh.advertise<access_pointcloud::PointXyzi>("point_xyzi",100);

  }
};

int main(int argc, char** argv)
{
  ros::init(argc,argv,"access_cloud");
  access_cloud ac_pc;
  ros::spin();
}
