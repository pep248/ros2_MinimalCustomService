#include <minimal_service/minimal_service_client_class.hpp>

int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);

  // Create an instance of the MinimalServiceClient
  auto service_client = std::make_shared<MinimalServiceClient>();

  // 1 time execution, so no executor needed

  // Make a request
  std::string word1 = "Hello ";
  std::string word2 = "ROS";
  auto result = service_client->makeRequest(word1, word2);

  if (result) {
    RCLCPP_INFO(rclcpp::get_logger("minimal_service_client_node"), "Result: %s", result->resulting_word.c_str());
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("minimal_service_client_node"), "Service call failed");
  }

  rclcpp::shutdown();
  return 0;
}



