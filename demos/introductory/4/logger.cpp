#include <iostream>
#include <cassert>
class Logger
{
    // prevent users from instanciating
private:
    Logger()
    {
        std::cout << "private c'tor" << std::endl;
    }
    Logger(const Logger &)
    {
        std::cout << "private copy c'tor" << std::endl;
    }

public:
    static Logger &GetInstance()
    {
        static Logger logger;
        return logger;
    }
    void Log(std::string message)
    {
        std::cout << message << std::endl;
    }

    ~Logger()
    {
        std::cout << "public d'tor" << std::endl;
    }
};

int main()
{

    Logger &l1 = Logger::GetInstance();
    Logger &l2 = Logger::GetInstance();

    assert(&l1 == &l2);

    l1.Log("Server disconnect");
    l2.Log("Server live");
}
