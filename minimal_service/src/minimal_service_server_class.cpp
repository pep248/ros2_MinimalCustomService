#include "minimal_service/srv/minimal_service.hpp"
#include "rclcpp/rclcpp.hpp"

class MinimalServiceServer : public rclcpp::Node
{
public:
  MinimalServiceServer()
    : Node("minimal_service_server")
  {
    // Create the service
    service_ = this->create_service<minimal_service::srv::MinimalService>(
      "concatenate_words",
      std::bind(&MinimalServiceServer::handle_service_request, this, std::placeholders::_1, std::placeholders::_2));
  }

private:
  void handle_service_request(
    const std::shared_ptr<minimal_service::srv::MinimalService::Request> request,
    std::shared_ptr<minimal_service::srv::MinimalService::Response> response)
  {
    // Concatenate words and set the result
    response->resulting_word = request->word1 + " " + request->word2;
  }

  rclcpp::Service<minimal_service::srv::MinimalService>::SharedPtr service_;
};