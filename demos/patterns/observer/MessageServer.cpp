#include "MessageServer.h"
#include <algorithm>

using namespace std;

void MessageServer::Attach(LoggingClient *client)
{
	list.push_back(client);
}
void MessageServer::Detach(LoggingClient *client)
{	
	list.erase(std::remove(list.begin(), list.end(), client), list.end());	
}

void MessageServer::Notify(string message)
{
	for(vector<LoggingClient*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if(*iter != 0)
		{
			(*iter)->OnMessage(message);
		}
	}


}
