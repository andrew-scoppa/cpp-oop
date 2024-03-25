#pragma once
#include <string>
#include "IObserver.h"

class LoggingClient : IObserver
{
	std::string name;
public:
	LoggingClient(std::string n); 
    void OnMessage(string message);          
};
