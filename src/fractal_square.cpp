#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "turtlesim/msg/pose.hpp"

class FractalSquare : public rclcpp::Node
{
public:
    FractalSquare() : Node("fractal_square"), count_(0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1), std::bind(&FractalSquare::loop, this)); //timer_cb_group_
        RCLCPP_INFO_STREAM(this->get_logger(), "Drawing a fractal square to turtlesim.");
        loop();
    }

private:
    void publish_message(double fwd, double turn)
    {
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = fwd;
        message.angular.z = turn;
        count_++;
        RCLCPP_INFO(this->get_logger(), "Step %ld. speed: '%.1f' turn: '%.1f'", count_, message.linear.x, message.angular.z);
        publisher_->publish(message);
        // delay for 2 second
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    void big_square(double size)
    {
        for (int i = 0; i < 4; i++)
        {
            publish_message(size, 0.0); // move forward
            publish_message(0.0, M_PI_2); //turn 90 degrees
        }
    }

    void fractal_square(double size, int depth)
    {
        if (depth == 0) return;

        big_square(size);

        for (int i = 0; i < 4; i++)
        {
            publish_message(size / 2, 0.0); // move forward
            fractal_square(size / 2, depth -1 ); //turn 90 degrees
            publish_message(0.0, M_PI_2);
        }
    }
    void loop()
    {
        double initial_size = 4.0;
        int depth = 5;
        fractal_square(initial_size, depth);
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
    rclcpp::spin(std::make_shared<FractalSquare>());
    rclcpp::shutdown();
    return 0;
}