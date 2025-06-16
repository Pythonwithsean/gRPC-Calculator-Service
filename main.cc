#include <iostream>
#include "calc_server.h"

// CRLF -> Carriage return line feed
// Carriage return - \r
// Line feed - \n

int main()
{
	std::string server_address = "0.0.0.0:50051";
	CalcServiceImpl service;
	grpc::ServerBuilder builder;
	builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
	builder.RegisterService(&service);
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	server->Wait();
	return 0;
}
