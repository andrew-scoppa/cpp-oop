#include <iostream>
#include <vector>

using std::cout, std::endl;

class Big
{
private:
    size_t _length; // The length of the resource.
    int *_data;     // The resource.
public:
    // Simple constructor that initializes the resource.
    Big(size_t length) : _length(length), _data(new int[length])
    {
        cout << "In c'tor length = " << _length << "." << endl;
    }

    Big(const Big &rhs)
    {
        cout << "copy c'tor" << endl;
        _length = rhs._length;
        this->_data = new int[_length];
        for (size_t i = 0; i < _length; i++)
        {
            _data[i] = rhs._data[i];
        }
    }

    Big &operator=(const Big &rhs)
    {
        cout << "copy assign" << endl;
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
    // Big b(move(other))
    Big(Big &&rhs)
    {
        cout << "move construct" << endl;
        *this = std::move(rhs);
    }

    // a = move(b);
    Big &operator=(Big &&rhs)
    {
        cout << "move assign" << endl;
        if (this == &rhs)
        {
            return *this;
        }
        delete[] _data;
        this->_data = rhs._data;
        this->_length = rhs._length;

        rhs._data = nullptr;
        rhs._length = 0;
        return *this;
    }

    ~Big()
    {
        cout << "d'tor"
             << ".";

        if (_data != nullptr)
        {
            cout << " Deleting resource.";

            delete[] _data;
        }

        cout << endl;
    }

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }
};

Big GenData()
{
    return Big(10);
}

int main()
{
    std::vector<Big> v;
    v.push_back(Big(10));
    v.push_back(Big(30));
    v.push_back(Big(50));

    for (auto &&b : v){
        cout << b.Length() << endl;
    }

    v.clear();

    return 0;
}