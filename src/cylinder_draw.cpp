#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "turtlesim/msg/pose.hpp"

#define NINETY_DEG 1.56079632679489661923

class CylinderDraw : public rclcpp::Node
{
public:
    CylinderDraw() : Node("cylinder_draw"), count_(0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 25);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&CylinderDraw::loop, this)); //timer_cb_group_
        loop();
    }

private:
    void publish_message(double fwd, double turn) //Moving turtle1
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        publisher_->publish(message);
        std::this_thread::sleep_for(std::chrono::seconds(2)); // delay for 2 second
    }
    void loop()
    {
        //Drawing the cylinder using turtle1
        std::this_thread::sleep_for(std::chrono::seconds(2)); // delay for 2 second
        publish_message(0, NINETY_DEG); //turn 90 degrees
        publish_message(4, 0); //move forward on the right side of the cylinder
        //Drawing the bottom half of the cylinder's top
        publish_message(0, NINETY_DEG+(NINETY_DEG/3)); //turn 120 degrees to the left
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        //Drawing the top half of the cylinder's top
        publish_message(0, -1 * (NINETY_DEG+(NINETY_DEG/3))); //turn 120 degrees right
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        //Going back to the left side of the cylinder
        publish_message(0, -1 * (NINETY_DEG+(NINETY_DEG/3))); //turn 90 degrees right
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        publish_message(1, -1 * (NINETY_DEG/3)); //move forward while turning right
        publish_message(0, NINETY_DEG+(NINETY_DEG/3)); //turn 120 degrees left
        publish_message(4, 0); //move forward on the left side of the cylinder
        //Drawing the cylinder's bottom
        publish_message(0, 2*(NINETY_DEG/3)); //turn 30 degrees to the right
        publish_message(1, NINETY_DEG/3); //move forward while turning left
        publish_message(1, NINETY_DEG/3); //move forward while turning left
        rclcpp::shutdown();
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    double x, y, theta;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CylinderDraw>());
    rclcpp::shutdown();
    return 0;
}