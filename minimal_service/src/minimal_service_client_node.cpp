#include <minimal_service/minimal_service_client_class.hpp>

using namespace std;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    // Create an instance of the MinimalActionClient()
    auto service_client = std::make_shared<MinimalServiceServer>();

    // Create an executor and put the service_client inside
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(service_client);
    // Send the goal
    service_client->send_goal(10);

    // Check if the service was successful and kill the node once finished
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
