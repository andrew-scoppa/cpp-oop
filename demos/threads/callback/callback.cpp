
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <functional>

using namespace std;

using callback = function<void(void)>;

class Sensor
{
private:
	 callback _action = nullptr;

	void setTrigger(long seconds) 
	{
		if (_action == nullptr)
		{
			return;
		}
		
		for (size_t i = 0; i < seconds ; i++)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
		}
		cout << endl;
		_action();
	}
public:
	Sensor(callback fn) : _action(fn)
	{
	}
	void operator()(long seconds){
		this->setTrigger(seconds);
	}
};

void alarm()
{
	cout << "Sensor Alert!" << endl;
}

int main()
{
	Sensor s([](){cout << "Sensor Alert!" << endl;});

	thread t(s,10);
	cout << "Trigger set";
    cout << " 10 seconds " << endl;

	t.join();
	return 0;
}
