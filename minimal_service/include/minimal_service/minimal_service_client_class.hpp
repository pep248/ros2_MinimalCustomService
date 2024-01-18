#ifndef MINIMAL_SERVICE_CLIENT_CLASS_HPP_
#define MINIMAL_SERVICE_CLIENT_CLASS_HPP_

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "custom_service/srv/custom_service.hpp"

class MinimalServiceClient : public rclcpp::Node
{
public:
  MinimalServiceClient();

  std::shared_ptr<custom_service::srv::CustomService::Response> makeRequest(
    const std::string& word1,
    const std::string& word2);

private:
  rclcpp::Client<custom_service::srv::CustomService>::SharedPtr client_;
};

#endif  // MINIMAL_SERVICE_CLIENT_CLASS_HPP_
