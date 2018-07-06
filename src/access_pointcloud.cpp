#include <ros/ros.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <sensor_msgs/PointCloud2.h>

class access_pointcloud
{
  private:
  ros::Subscriber sub_cloud;

  void Callback(const sensor_msgs::PointCloud2ConstPtr& cloud)
  {
    sensor_msgs::PointCloud2Iterator<float> iter_x(*cloud, "x");
    sensor_msgs::PointCloud2Iterator<float> iter_y(*cloud, "y");
    sensor_msgs::PointCloud2Iterator<float> iter_z(*cloud, "z");
    sensor_msgs::PointCloud2Iterator<float> iter_i(*cloud, "intensity");

    for(; iter_x != iter_x.end(); ++iter_x, ++iter_y, ++iter_z, ++iter_i) 
    {
      ROS_INFO("x=%f\n",*iter_x);
      ROS_INFO("y=%f\n",*iter_y);
      ROS_INFO("z=%f\n",*iter_z);
      ROS_INFO("intensity=%f\n",*iter_i);

      //今は表示だがmsg型作成してpublish できるようにしたい
    }
  }

  public:
  access_pointcloud()
  {
    ros::NodeHandle nh("~");
    sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("cloud",100,
                                                       &access_pointcloud::Callback);
  }
};

int main(int argc, char** argv)
{
  ros::init(argc,argv,"access_cloud");
  access_pointcloud ac_pc;
  ros::spin();
}
