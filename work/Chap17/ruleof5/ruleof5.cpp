#include <iostream>

using namespace std;

class Widget final
{
private:
	int *_data;

public:
	Widget(int value = 0)
	{
		_data = new int(value);
		cout << "C'tor" << endl;
	}

	Widget(const Widget &rhs)
	{
		cout << "CC'tor" << endl;
		_data = new int(*rhs._data);
	}

	Widget(Widget &&rhs)
	{
		cout << "M'tor" << endl;
		_data = rhs._data;
		rhs._data = nullptr;
	}

	Widget &operator=(const Widget &rhs)
	{
		cout << "op=" << endl;
		if (this == &rhs)
			return *this;

		delete _data;
		_data = new int(*rhs._data);
		return *this;
	}

	Widget &operator=(Widget &&rhs)
	{
		cout << "move op=" << endl;
		if (this == &rhs)
			return *this;

		delete _data;
		_data = rhs._data;

		rhs._data = nullptr;

		return *this;
	}

	int Get() const
	{
		return *_data;
	}

	void Set(int value)
	{
		*_data = value;
	}

	~Widget()
	{
		cout << "D'tor" << endl;
		delete _data;
	}
};

void exchange(Widget &&a, Widget &&b)
{
	std::swap(a, b);
}

void exchange(Widget &a, Widget &b)
{
	Widget tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	Widget a(1), b(2);
	cout << a.Get() << ", " << b.Get() << endl;

	exchange(a, b);
	cout << a.Get() << ", " << b.Get() << endl;

	// exchange(move(a), move(b));
	// cout << a.Get() << ", " << b.Get() << endl;
	return 0;
}