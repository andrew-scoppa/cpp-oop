#include <iostream>
#include <cassert>

using namespace std;

class Logger {
private:


	Logger(){
		cout << "c'tor" << endl;
	}

	Logger(const Logger&) {
		cout << "copy c'tor" << endl;
	}

	const Logger& operator=(const Logger&){	}

public:
	static Logger& GetInstance() {
		static Logger _logger;
		return _logger;
	}

	void Log(string message) const{
		cout << message << endl;
	}

	~Logger()
	{
		cout << "d'tor" << endl;
	}
};

int main() {
	cout << "calling GetInstance()" << endl;
	
	Logger& logger1 = Logger::GetInstance();
	Logger& logger2 = Logger::GetInstance();

	assert(&logger1 == &logger2);

	logger1.Log("logging: 123");
	logger2.Log("logging: 456");

}