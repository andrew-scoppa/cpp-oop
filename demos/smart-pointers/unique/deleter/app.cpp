#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

using std::string, std::cout, std::endl;

class Parent
{
protected:
    std::string _name;

public:
    Parent(string name) : _name(name)
    {
        std::cout << "Parent c'tor" << std::endl;
    }

    virtual void Talk() = 0;

    virtual ~Parent()
    {
        std::cout << "Parent d'tor" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child(string name) : Parent::Parent(name)
    {
        std::cout << "Child c'tor" << std::endl;
    }
    virtual void Talk() override
    {
        std::cout << _name << " is speaking..." << std::endl;
    }
    virtual ~Child()
    {
        std::cout << "Child d'tor" << std::endl;
    }
};

using namespace std;
void Process(const std::vector<std::unique_ptr<Parent>> &pv)
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
void Talk(std::unique_ptr<Parent> p)
{
    p->Talk();
}

int main()
{
    auto deleter = [](std::vector<Parent*> *ptr){
        for (size_t i = 0; i < ptr->size(); i++)
        {
            cout << "[deleter called]" << endl;
            delete (*ptr)[i];
        }
        
    };
    unique_ptr<std::vector<Parent *>, decltype(deleter)> p(new std::vector<Parent *>, deleter);
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