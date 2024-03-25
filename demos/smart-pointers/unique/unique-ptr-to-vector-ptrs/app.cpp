#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

using std::string, std::cout, std::endl;

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

using namespace std;
void Process(const vector<unique_ptr<Parent>> &pv)
{
    for (size_t i = 0; i < pv.size(); i++)
    {
        pv[i]->Talk();
    }
}

void Talk(Parent *p)
{
    p->Talk();
}
void Talk(unique_ptr<Parent> p)
{
    p->Talk();
}

int main()
{
    auto deleter = [](vector<Parent*> *ptr){
        for (size_t i = 0; i < ptr->size(); i++)
        {
            cout << "[deleter called]" << endl;
            delete (*ptr)[i];
        }
        
    };
    unique_ptr<vector<Parent *>, decltype(deleter)> p(new vector<Parent *>, deleter);
    p->push_back(new Child("Andrew"));
    p->push_back(new Child("Donna"));

    for (size_t i = 0; i < p->size(); i++)
    {
        (*p)[i]->Talk();
    }
    
}

void step1()
{
    std::unique_ptr<Parent> w(new Child("Donna"));

    w->Talk();
}