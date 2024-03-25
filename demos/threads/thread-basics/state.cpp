/*
Thread parameters allow minimal transfer of thread specific data.

You can also use a class or structure to create a thread object.

The data members provide rich information available to the threads

*/

#include <iostream>
#include <thread>

using namespace std;

class Foo
{
private:
    int _data;

public:
    Foo(int data) : _data(data) {}
    void operator()() /* worker */ { ++_data; }
    void operator()(int arg) /* worker */ { _data += arg; }
    int get() const { return _data; }
};
int main()
{
    Foo foo(100);
    thread t1(std::ref(foo), 12);
    t1.join();
    cout << foo.get() << endl; // prints 101
}
