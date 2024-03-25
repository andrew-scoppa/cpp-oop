#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class value_error : public invalid_argument
{
private:
    T _value;
    string _message;

public:
    value_error(T value, const char *what_arg) 
    : _value(value), invalid_argument(what_arg){};
    value_error(T value, std::string &what_arg) 
    : _value(value), invalid_argument(what_arg){};
    T get_value() const
    {
        return _value;
    }
};

template <typename T>
void CheckBounds(T min, T max, T val)
{
    if (val < min || val > max)
    {
        throw value_error(val, "Way out of bounds!");
    }
}

int main()
{
    int val;
    try
    {
        std::cout << "Enter value: ";
        cin >> val;
        CheckBounds<int>(0, 10, val);
    }
    catch (value_error<int> &e)
    {
        cerr << e.what() << ": " << e.get_value() << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}