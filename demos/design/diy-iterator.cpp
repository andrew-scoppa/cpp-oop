#include <iostream>

using namespace std;

struct Num
{
private:
	int _num;

public:
	Num(int num = 0) : _num(num) {}

	int get() const
	{
		return _num;
	}
};

void StackDemo();
void HeapDemo();

int main()
{
	cout << "Stack demo:" << endl;
	StackDemo();
	cout << "Heap demo:" << endl;
	HeapDemo();
	return 0;
}

void StackDemo(){
	Num nums[] = {Num(1), Num(2), Num(3), Num(4), Num(5)};

	const int count = sizeof(nums) / sizeof(Num);
	Num *const begin = nums;
	Num *const end = nums + count;

	for (Num *it = begin; it < end; ++it)
	{
		std::cout << it->get() << std::endl;
	}
}
void HeapDemo(){
	Num *nums[] = {new Num(1), new Num(2), new Num(3), new Num(4), new Num(5)};

	const int count = sizeof(nums) / sizeof(Num*);
	Num **const begin = nums;
	Num **const end = nums + count;

	for (Num **it = begin; it < end; ++it)
	{
		std::cout << (*it)->get() << std::endl;
	}

	// Deallocate the dynamically allocated Num objects
	for (int i = 0; i < count; ++i)
	{
		delete nums[i];
	}
}