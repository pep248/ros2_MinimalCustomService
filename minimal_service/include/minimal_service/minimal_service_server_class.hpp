#ifndef MINIMAL_ACTION_SERVER_HPP_
#define MINIMAL_ACTION_SERVER_HPP_

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom_service/srv/custom_service.hpp"

class MinimalServiceServer : public rclcpp::Node
{
public:
  MinimalServiceServer();

private:
  rclcpp::Service<custom_service::srv::CustomService>::SharedPtr service_;

  void handle_request(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<custom_service::srv::CustomService::Request> request,
    const std::shared_ptr<custom_service::srv::CustomService::Response> response);
};

#endif  // MINIMAL_SERVICE_SERVER_CLASS_HPP_
