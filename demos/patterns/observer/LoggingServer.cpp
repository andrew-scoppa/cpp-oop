#include "LoggingServer.h"

void LoggingServer::Log(string message)
{
    Notify(message);
}
