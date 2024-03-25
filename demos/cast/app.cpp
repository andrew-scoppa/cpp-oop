#include <iostream>
#include <typeinfo>

using namespace std;

class Parent
{
public:
    Parent(){};

    virtual void speak()
    {
        cout << typeid(*this).name() << " is speaking" << endl;
    }

    virtual ~Parent()
    {
    }
};

class Child : public Parent
{

public:
    void speak() override
    {
        cout << typeid(*this).name() << " is speaking" << endl;
    }

    void play()
    {
        cout << "...playing...." << endl;
    }
    void run()
    {
        cout << "...running...." << endl;
    }
};

int main()
{
    // OK
    Parent *p1 = new Child();
    const type_info& id = typeid(*p1);
    if (id == typeid(Child))
    {
        ((Child *)p1)->play();
    }

    // Better
    Child *p2 = dynamic_cast<Child *>(p1);
    if (p2 != nullptr)
    {
        p2->run();
    }
    delete p1;
    delete p2;
    return 0;
}
