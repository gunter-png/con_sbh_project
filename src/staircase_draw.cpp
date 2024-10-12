#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "turtlesim/msg/pose.hpp"

#define NINETY_DEG 1.56079632679489661923

class StaircaseDraw : public rclcpp::Node
{
public:
    StaircaseDraw() : Node("staircase_draw"), count_(0)
    {
        publisher1_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle2/cmd_vel", 50);
        publisher2_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle3/cmd_vel", 50);
        publisher3_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle4/cmd_vel", 50);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&StaircaseDraw::loop, this)); //timer_cb_group_
        loop();
    }
private:
    void publish_message1(double fwd, double turn) //Moving turtle2
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        publisher1_->publish(message);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // delay for 2 second
    }
private:
    void publish_message2(double fwd, double turn) //Moving turtle3
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        publisher2_->publish(message);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // delay for 2 second
    }
private:
    void publish_message3(double fwd, double turn) //Moving turtle4
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        publisher3_->publish(message);
        std::this_thread::sleep_for(std::chrono::seconds(1)); // delay for 2 second
    }
    void loop()
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // delay for 2 second
        //Drawing the staircase using turtle2
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.25, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.35, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.40, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.55, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.45, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, NINETY_DEG); //turn 90 degrees left
        publish_message1(0.35, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move right
        publish_message1(0, 2 * NINETY_DEG); //turn 180 degrees
        publish_message1(0.25, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.25, 0); //move right
        publish_message1(0, 2 * NINETY_DEG); //turn 180 degrees
        publish_message1(0.15, 0); //move left
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move up
        publish_message1(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message1(0.15, 0); //move right
        //Drawing the staircase using turtle3
        publish_message2(0.25, 0); //move right
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.25, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.35, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.40, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.55, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.45, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, NINETY_DEG); //turn 90 degrees left
        publish_message2(0.35, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move right
        publish_message2(0, 2 * NINETY_DEG); //turn 180 degrees
        publish_message2(0.25, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.25, 0); //move right
        publish_message2(0, 2 * NINETY_DEG); //turn 180 degrees
        publish_message2(0.15, 0); //move left
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move up
        publish_message2(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message2(0.15, 0); //move right
        //Drawing the staircase using turtle4
        publish_message3(0.25, 0); //move right
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.25, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.35, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.40, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.55, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.45, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, NINETY_DEG); //turn 90 degrees left
        publish_message3(0.35, 0); //move left
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move up
        publish_message3(0, -1 * NINETY_DEG); //turn 90 degrees right
        publish_message3(0.15, 0); //move right
        rclcpp::shutdown();
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher1_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher2_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher3_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    double x, y, theta;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StaircaseDraw>());
    rclcpp::shutdown();
    return 0;
}