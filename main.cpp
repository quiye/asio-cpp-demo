#define ASIO_STANDALONE

#include <iostream>
#include <string>

#include "asio/asio/include/asio.hpp"

// asio/asio/src/examples/cpp03/porthopper/client.cpp:40
// asio/asio/src/examples/cpp11/socks4/sync_client.cpp:69
int main() {
  const std::string host = "localhost";
  const std::string port = "8080";
  // asio::ip::tcp::endpoint target(asio::ip::make_address(host), port);

  asio::io_context io_context;

  // Determine the location of the server.
  asio::ip::tcp::resolver resolver(io_context);
  asio::ip::tcp::endpoint remote_endpoint =
      *resolver.resolve(host, port).begin();

  asio::ip::tcp::socket control_socket(io_context);
  control_socket.connect(remote_endpoint);
  if (!control_socket.is_open()) {
    return 1;
  }

  std::string request =
      "GET / HTTP/1.0\r\n"
      "Host: localhost:8080\r\n"
      "Accept: */*\r\n"
      "Connection: close\r\n\r\n";

  asio::write(control_socket, asio::buffer(request));
  std::array<char, 512> response;
  std::error_code error;
  while (std::size_t s =
             control_socket.read_some(asio::buffer(response), error))
    std::cout.write(response.data(), s);
  if (error != asio::error::eof) throw std::system_error(error);
}
