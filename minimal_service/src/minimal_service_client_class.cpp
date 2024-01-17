#include "minimal_service/srv/minimal_service.hpp"
#include "rclcpp/rclcpp.hpp"

class MinimalServiceClient : public rclcpp::Node
{
public:
  MinimalServiceClient()
    : Node("minimal_service_client")
  {
    // Create the client
    client_ = this->create_client<minimal_service::srv::MinimalService>("concatenate_words");

    // Wait for the service to be available
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "Service not available, waiting...");
    }

    // Call the service
    auto request = std::make_shared<minimal_service::srv::MinimalService::Request>();
    request->word1 = "Hello";
    request->word2 = "ROS";

    auto result = call_service(request);

    if (result) {
      RCLCPP_INFO(this->get_logger(), "Result: %s", result->resulting_word.c_str());
    } else {
      RCLCPP_ERROR(this->get_logger(), "Service call failed");
    }
  }

private:
  std::shared_ptr<minimal_service::srv::MinimalService::Response> call_service(
    const std::shared_ptr<minimal_service::srv::MinimalService::Request> request)
  {
    // Create a promise and a future to get the result asynchronously
    auto promise_result = std::make_shared<std::promise<std::shared_ptr<minimal_service::srv::MinimalService::Response>>>();
    auto future_result = promise_result->get_future();

    // Make the service call
    auto request_handle = client_->async_send_request(request, [promise_result](rclcpp::Client<minimal_service::srv::MinimalService>::SharedFuture future) {
      if (future.valid()) {
        promise_result->set_value(future.get());
      } else {
        promise_result->set_value(nullptr);
      }
    });

    // Wait for the result
    rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_result);

    // Return the result
    return future_result.get();
  }

  rclcpp::Client<minimal_service::srv::MinimalService>::SharedPtr client_;
};