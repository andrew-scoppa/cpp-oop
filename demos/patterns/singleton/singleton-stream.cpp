#include <iostream>
#include <cassert>
#include <fstream>
#include <mutex>

std::string fileName = "log.txt";

class Logger {
private:
	std::mutex _mutex;
	std::ofstream _fs;
	Logger(){
		_fs.open(fileName, std::ios_base::app);
		std::cout << "c'tor" << std::endl;
	}

	Logger(const Logger&) {	}

public:
	static Logger& GetInstance()  {
		static Logger _logger;
		return _logger;
	}

	void Log(std::string message) {
		std::lock_guard<std::mutex> lg(_mutex);
		_fs << message << std::endl;
	}

	~Logger()
	{
		_fs.close();
		std::cout << "d'tor" << std::endl;
	}
};

int main() {
	std::cout << "calling GetInstance()" << std::endl;
	
	Logger& logger1 = Logger::GetInstance();
	Logger& logger2 = Logger::GetInstance();

	assert(&logger1 == &logger2);

	logger1.Log("logging a message");
	logger2.Log("logging another message");

}