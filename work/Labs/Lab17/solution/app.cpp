#include "stdafx.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class BigData
{
public:
    explicit BigData(size_t length) : _length(length), _data(new int[length])
    {
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

    BigData(BigData &&other)
        : _data(nullptr), _length(0)
    {
        *this = std::move(other);
    }

    // Move assignment operator.
    BigData &operator=(BigData &&other)
    {

        if (this != &other)
        {
            // Free the existing resource.
            delete _data;

            // Copy the data pointer and its length from the source object.
            _data = other._data;
            _length = other._length;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }

    ~BigData()
    {
        if (_data != nullptr)
        {
            delete _data;
        }
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