#include <minimal_service/minimal_service_server_class.hpp>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto service_server = std::make_shared<MinimalServiceServer>();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(service_server);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
