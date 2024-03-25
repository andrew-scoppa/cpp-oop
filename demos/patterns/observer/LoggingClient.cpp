#include "LoggingClient.h"
#include <iostream>
using namespace std;

LoggingClient::LoggingClient(std::string name)
{
    this->name = name;
}

void LoggingClient::OnMessage(string message)
{
    //Lets print on console just to test the working
	std::cout << name << " received message: "<< message << endl;
}