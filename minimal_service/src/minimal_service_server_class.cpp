#include <minimal_service/minimal_service_server_class.hpp>

MinimalServiceServer::MinimalServiceServer()
  : Node("minimal_service_server")
{
  service_ = this->create_service<custom_service::srv::CustomService>(
    "concatenate_words",
    std::bind(&MinimalServiceServer::handle_request, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MinimalServiceServer::handle_request(
  const std::shared_ptr<rmw_request_id_t> request_header,
  const std::shared_ptr<custom_service::srv::CustomService::Request> request,
  const std::shared_ptr<custom_service::srv::CustomService::Response> response)
{
  (void)request_header;
  response->resulting_word = request->word1 + request->word2;
}
