#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Parent
{
protected:
    string _name;

public:
    Parent(string name) : _name(name)
    {
        cout << "Parent c'tor" << endl;
    }

    virtual void Talk() = 0;

    virtual ~Parent()
    {
        cout << "Parent d'tor" << endl;
    }
};

class Child : public Parent
{
public:
    Child(string name) : Parent::Parent(name)
    {
        cout << "Child c'tor" << endl;
    }
    virtual void Talk() override
    {
        cout << _name << " is speaking..." << endl;
    }
    virtual ~Child()
    {
        cout << "Child d'tor" << endl;
    }
};

int main()
{
    vector<unique_ptr<Parent>> v;
    v.push_back(unique_ptr<Parent>(new Child("alice")));
    v.push_back(unique_ptr<Parent>(new Child("bob")));
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i]->Talk();
    }
}