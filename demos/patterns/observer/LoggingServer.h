#pragma once
#include "MessageServer.h"

class LoggingServer : public MessageServer
{
public:
	void Log(string message);
};
