#pragma once
#include <vector>
#include <list>
#include "LoggingClient.h"

class MessageServer
{
	//Lets keep a track of all the shops we have observing
	std::vector<LoggingClient*> list;

public:
	void Attach(LoggingClient *product);
    void Detach(LoggingClient *product);
	void Notify(string message); 
};
