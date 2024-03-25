#include <iostream>
#include <string>
using namespace std;

class app
{
private:
    /* data */
    int _data;

public:
    void dump()
    {
        cout << "_data: " << endl;
        cout << this->_data << endl;
    }
    app(int data)
    try : _data(data)
    {

        cout << "c'tor w one arg" << endl;
    }
    catch (...)
    {
    }

    app() : app::app(0)
    {
        cout << "default c'tor" << endl;
    }

    ~app()
    {
        cout << "d'tor" << endl;
    }
};

int main()
{
    cout << "Entering code bloc..." << endl;
    {
        app a;
    }
    cout << "Left code bloc..." << endl;

    return 0;
}
