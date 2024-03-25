#include "stdafx.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class BigData
{
public:
    // Simple constructor that initializes the resource.
    explicit BigData(size_t length) : _length(length), _data(new int[length])
    {
        // cout << "In BigData(size_t) length = " << _length << "." << endl;
    }

    BigData(const BigData &rhs)
    {
        _length = rhs._length;
        _data = new int[_length];
        for (size_t i = 0; i < _length; i++)
        {
            _data[i] = rhs._data[i];
        }
    }

    BigData &operator=(const BigData &rhs)
    {
        if (this == &rhs)
            return *this;
        delete[] _data;
        _data = new int[_length];
        for (size_t i = 0; i < _length; i++)
        {
            _data[i] = rhs._data[i];
        }
        return *this;
    }

    ~BigData()
    {
        // cout << "In ~BigData() length = " << _length << ".";

        if (_data != nullptr)
        {
            // cout << " Deleting resource.";

            delete[] _data;
        }

        // cout << endl;
    }

/*
    Instructions
    
    1) Add a move constructor.
       If you provide both a move constructor and a move assignment operator for your class,
       you can eliminate redundant code by writing the move constructor to call the move assignment operator.

    2) Add a move assignment operator.
*/

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }

private:
    size_t _length; // The length of the resource.
    int *_data;     // The resource.
};

int main()
{
    using namespace std::chrono;

    vector<BigData> v;

    auto a = high_resolution_clock::now();

    const int quant = 10;
    for (size_t i = 1; i <= quant; i++)
    {
        v.push_back(BigData(i * 100));
    }

    // Insert a new element into the second position of the vector.
    for (size_t i = 1; i <= quant; i++)
    {
        v.insert(v.begin() + 1, BigData(i * 100));
    }

    auto b = high_resolution_clock::now();

    cout << endl
         << "Elapsed time: " << duration_cast<microseconds>(b - a).count() << " microseconds" << endl
         << endl;
    return 0;
}