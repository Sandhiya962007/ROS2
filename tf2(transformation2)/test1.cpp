#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <cmath>
#include <thread>
#include <chrono>


// simplify the notation
using namespace std::chrono;

// class for embedding the broadcaster node
// this class inherits from the Node class
class TFBroadcasterNode : public rclcpp::Node
{
public:

    // constructor
    TFBroadcasterNode() :
        // here, we call the constructor of the parent class and set the created node name
        Node("broadcaster_node")
    {

        // print the message in the terminal
        RCLCPP_INFO(this->get_logger(), "Started the broadcaster node!");

        // instantiate the broadcaster object
        broadcasterObject = std::make_shared<tf2_ros::TransformBroadcaster>(this);

        // instantiate the timer and bind the broadcaster function
        timerObject = this->create_wall_timer(
            100ms,
            std::bind(&TFBroadcasterNode::BroadcastTransformFunction, this)
        );
    }

    // function that will publish user-specified joint states
    void BroadcastTransformFunction();
    


    private:
       rclcpp::TimerBase::SharedPtr timerObject;
       std::shared_ptr<tf2_ros::TransformBroadcaster> broadcasterObject;

};

void TFBroadcasterNode::BroadcastTransformFunction()
{
  // here, we create the tf messages that need to be broadcasted
  // t1 is from base_link to first_link
  // t2 is from base_link to second_link

  geometry_msgs::msg::TransformStamped t1;
  geometry_msgs::msg::TransformStamped t2;

  // we need to add a time stamp
  t1.header.stamp = this->get_clock()->now();
  t2.header.stamp = this->get_clock()->now();

  // every message need to have a parent and child frame names
  t1.header.frame_id = "base_link";
  t1.child_frame_id = "first_link";

  t2.header.frame_id = "base_link";
  t2.child_frame_id = "second_link";

  // we need to define translation between frames
  t1.transform.translation.x = 0.5;
  t1.transform.translation.y = 0.5;
  t1.transform.translation.z = 0.0;

  t2.transform.translation.x = 0.5;
  t2.transform.translation.y = 0.5;
  t2.transform.translation.z = 0.0;

  
  tf2::Quaternion q1;
  tf2::Quaternion q2;

  q1.setRPY(0,0,3.14/2);
  t1.transform.rotation.x=q1.x();
  t1.transform.rotation.y=q1.y();
  t1.transform.rotation.z=q1.z();
  t1.transform.rotation.w=q1.w();
  
  q2.setRPY(0,0,-3.14/2);
  t2.transform.rotation.x=q2.x();
  t2.transform.rotation.y=q2.y();
  t2.transform.rotation.z=q2.z();
  t2.transform.rotation.w=q2.w();

  broadcasterObject->sendTransform(t1);
  broadcasterObject->sendTransform(t2);

  RCLCPP_INFO(this->get_logger(),"TF messsage broadcasted!");


}

int main(int argc,char*argv[]){

    rclcpp::init(argc,argv);
    auto TestNode=std::make_shared<TFBroadcasterNode>();
    rclcpp::spin(TestNode);
    rclcpp::shutdown();
    return 0;

}