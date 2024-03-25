#include "LoggingServer.h"

int main(int argc, char *argv[])
{
	LoggingServer server{};

	LoggingClient client1("client 1");
	LoggingClient client2("client 2");

	server.Attach(&client1);
	server.Attach(&client2);

	server.Log("file change notification");

	server.Detach(&client2);

	server.Log("disk fail");

	server.Detach(&client1);

	server.Log("disk recovered"); // no receivers (OK)

	return 0;
}
