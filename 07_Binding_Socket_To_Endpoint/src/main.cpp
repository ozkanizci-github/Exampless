//============================================================================
// Name        : 03_Create_End_Point
// Programer   : Mert AceL
// Version     : 1.0
// Copyright   : Boost.Asio C++ Network Programming Cookbook
// Description : Boost.Asio C++ Network Programming Cookbook
//============================================================================
#include <boost/asio.hpp>
#include <iostream>
using namespace boost;
int main()
{
	// Step 1. Here we assume that the server application has
	// already obtained the protocol port number.
	unsigned short port_num = 3333;
	// Step 2. Creating an endpoint.
	asio::ip::tcp::endpoint ep(asio::ip::address_v4::any(), port_num);
	// Used by 'acceptor' class constructor.
	asio::io_service ios;
	// Step 3. Creating and opening an acceptor socket.
	asio::ip::tcp::acceptor acceptor(ios, ep.protocol());

	boost::system::error_code ec;
	// Step 4. Binding the acceptor socket.
	acceptor.bind(ep, ec);

	// Handling errors if any.
	if (ec.value() != 0)
	{
		// Failed to bind the acceptor socket. Breaking
		// execution.
		std::cout << "Failed to bind the acceptor socket."
				  << "Error code = " << ec.value() << ". Message: "
				  << ec.message();
		return ec.value();
	}

	std::cout << "Finish..." << std::endl;

	return 0;
}