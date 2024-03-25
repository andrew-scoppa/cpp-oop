
#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Label
{
private:
	string _caption;

public:
	Label(string caption) : _caption(caption) {}
	string get() const
	{
		return _caption;
	}
};

template <typename T, int N = 100>
class Set
{
private:
	T *_elements = new T[N];
	unsigned int _nextSlot = 0;
	Label _label;

public:
	Set(string label = "My Set");
	Set &add(const T &c);
	virtual void report();
	virtual ~Set<T, N>()
	{

		cout << "Destroying Set " << _label.get() << endl;
		delete[] _elements;
	}
};

template <typename T, int N>
Set<T, N>::Set(string label) : _label(label)
{
	memset(_elements, 0, (size_t)N);
	this->_nextSlot = 0;
}

template <typename T, int N>
Set<T, N> &Set<T, N>::add(const T &c)
{
	unsigned int lastSlot = N;
	if (_nextSlot > lastSlot)
	{
		return *this;
	}

	T *p = _elements;
	while (p < _elements + _nextSlot)
	{
		if (*p == c)
		{
			return *this;
		}
		++p;
	}
	*p = c;
	++_nextSlot;
	return *this;
}

template <typename T, int N>
void Set<T, N>::report()
{
	cout << _label.get() << endl;
	for (int i = 0; i < (int)_nextSlot; i++)
	{
		cout << _elements[i] << endl;
	}
}

void setInt();
void setChar();

int main()
{
	setChar();

	return 0;
}

void setInt()
{
	Set<int> *pSet = new Set<int>("set of int");

	pSet->add(100).add(200).add(300).report();
	delete pSet;
	pSet = nullptr;
}

void setChar()
{
	Set<char, 100> set("char");
	set.add('a');
	set.add('b');
	set.add('a');
	set.add('a');
	set.add('d');
	set.report();
}
