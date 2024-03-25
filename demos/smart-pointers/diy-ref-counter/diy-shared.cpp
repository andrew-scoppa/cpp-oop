/*
A shared pointer keeps a pointer to an object and a pointer to a shared reference count.
Every time a copy of the smart pointer is made using the copy constructor,
the reference count is incremented.

When a shared pointer is destroyed, the reference count for its object is decremented.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct RefCounter
{
    int refCount = 0;
};

template <typename T>
class SmartPtr
{
private:
    RefCounter *_refCounter = nullptr;
    T *_data;

public:
    SmartPtr(T *data) : _data(data)
    {
        if (_refCounter == nullptr)
        {
            _refCounter = new RefCounter();
        }
        _refCounter->refCount++;
    }
    SmartPtr(const SmartPtr &rhs)
    {
        if (this == &rhs)
            return;
        this->_data = rhs._data;
        this->_refCounter = rhs._refCounter;
        this->_refCounter->refCount++;
    }
    const SmartPtr &operator=(const SmartPtr &rhs)
    {
        if (this == &rhs)
            return *this;
        this->_refCounter->refCount--;
        this->_refCounter = rhs._refCounter;
        this->_refCounter->refCount++;
        this->_data = rhs._data;
        return *this;
    }
    void Dump()
    {
        cout << *_data << endl;
    }

    ~SmartPtr()
    {
        _refCounter->refCount--;
        if (_refCounter->refCount == 0)
        {
            delete[] _data;
            delete _refCounter;
            cout << "d'tor = 0" << endl;

            return;
        }
        cout << "d'tor" << endl;
    }
};

int main()
{
    cout << "> Outer" << endl;
    SmartPtr<int> sp1(new int(10));
    SmartPtr<int> sp2 = sp1;
    {
        cout << "> Inner" << endl;
        SmartPtr<int> sp3 = sp1;
        SmartPtr<int> sp4(new int(11));
        sp3 = sp4;
        cout << "< Inner" << endl;
    }
        cout << "< Outer" << endl;
    return 0;
}