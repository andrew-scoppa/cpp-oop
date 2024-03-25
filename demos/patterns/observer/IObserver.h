#pragma once

using namespace std;

class IObserver
{
public:
	virtual void OnMessage(string message) = 0; 
};
