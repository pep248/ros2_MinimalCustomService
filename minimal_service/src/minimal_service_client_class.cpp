#include <minimal_service/minimal_service_client_class.hpp>

MinimalServiceClient::MinimalServiceClient() : Node("minimal_service_client")
{
  client_ = this->create_client<custom_service::srv::CustomService>("concatenate_words");

  while (!client_->wait_for_service(std::chrono::seconds(1))) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Service not available, waiting...");
  }
}

std::shared_ptr<custom_service::srv::CustomService::Response> MinimalServiceClient::makeRequest(
  const std::string& word1,
  const std::string& word2)
{
  auto request = std::make_shared<custom_service::srv::CustomService::Request>();
  request->word1 = word1;
  request->word2 = word2;

  auto result = client_->async_send_request(request);
  if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) ==
      rclcpp::FutureReturnCode::SUCCESS)
  {
    return result.get();
  } else {
    RCLCPP_ERROR(this->get_logger(), "Service call failed");
    return nullptr;
  }
}
