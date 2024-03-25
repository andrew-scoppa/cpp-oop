#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class ReuseMemory
{
	// not related to memory management:

public:
	ReuseMemory(int data = 0) : _data(data) {}
	~ReuseMemory() {}

	int getData() const
	{
		return _data;
	}

	void reset(){
		_data = -1;
	}

private:
	int _data;

	// related to memory management:

private:
	static vector<void *> _reusable_instances;
	static std::new_handler _handler;

public:
	static void *operator new(std::size_t s);
	static void operator delete(void *p);

	static void *operator new[](std::size_t s);
	static void operator delete[](void *p);

	new_handler setNewHandler(new_handler p)
	{
		new_handler oldHandler = _handler;
		_handler = p;
		return oldHandler;
	}
};

// related to memory management:
std::new_handler ReuseMemory::_handler = 0;

vector<void *> ReuseMemory::_reusable_instances;

void *ReuseMemory::operator new(std::size_t s)
{
	if (_reusable_instances.empty())
	{
		return ::operator new(s);
	}
	else
	{
		void *result = _reusable_instances.back();
		_reusable_instances.pop_back();
		return result;
	}
}

void ReuseMemory::operator delete(void *p)
{
	_reusable_instances.push_back(p);
}

void *ReuseMemory::operator new[](std::size_t s)
{
	return ::operator new[](s);
}

void ReuseMemory::operator delete[](void *p)
{
	::operator delete[](p);
}

void outOfMemory()
{
	std::abort();
}

int main()
{


	ReuseMemory *p1 = new ReuseMemory(1);
	p1->setNewHandler(outOfMemory);

	std::cout << p1 << std::endl;
	std::cout << p1->getData() << std::endl;

	delete p1;

	ReuseMemory *p2 = new ReuseMemory(2);

	std::cout << p2 << std::endl;
	std::cout << p2->getData() << std::endl;

	delete p2;

	ReuseMemory *p3 = new ReuseMemory(3);

	std::cout << p3 << std::endl;
	std::cout << p3->getData() << std::endl;


	return 0;
}
