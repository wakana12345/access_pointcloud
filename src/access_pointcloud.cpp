#include <ros/ros.h>
#include <sensor_msgs/point_cloud_iterator.h>
#include <sensor_msgs/PointCloud2.h>

class access_pointcloud
{
  private:
  ros::Subscriber sub_cloud;

  void Callback(const sensor_msgs::PointCloud2ConstPtr& cloud)
  {
    sensor_msgs::PointCloud2Modifier modifier(cloud);
    modifier.setPointCloud2FieldsByString(1, "xyzi");
    modifier.resize(100);

    sensor_msgs::PointCloud2Iterator<float> iter_x(cloud, "x");
    sensor_msgs::PointCloud2Iterator<float> iter_y(cloud, "y");
    sensor_msgs::PointCloud2Iterator<float> iter_z(cloud, "z");
    sensor_msgs::PointCloud2Iterator<float> iter_z(cloud, "i");

    //n_point 変える
    for(size_t i=0; i<n_points; ++i, ++iter_x, ++iter_y, ++iter_z, ++iter_i) 
    {
      *iter_x = point_data[3*i+0];
      *iter_y = point_data[3*i+1];
      *iter_z = point_data[3*i+2];
      *iter_i = color_data[3*i+3];
    }
  }

  public:
  access_pointcloud
  {
    ros::NodeHandle nh("~");
    sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("cloud",100,
                                                       &access_pointcloud::Callback)
  }
};

int main(int argc, char** argv)
{
  ros::init(argc,argv,"access_cloud");
  access_pointcloud ac_pc;
  ros::spin();
}
