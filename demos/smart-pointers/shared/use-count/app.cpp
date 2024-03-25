
#include <iostream>
#include <memory>
using namespace std;

class Widget
{
private:
	int _data;

public:
	Widget(int data = 0) : _data(data) { cout << "Widget c'tor" << endl; }
	virtual void Talk() const = 0;
	operator int() const { return _data; }
	~Widget() { cout << "Widget d'tor" << endl; }
};

class Gidget : public Widget
{
public:
	Gidget(int data = 0) : Widget(data) { cout << "Gidget c'tor" << endl; }
	void Talk() const override
	{
		cout << "Gidget speaking..." << endl;
	}
	~Gidget() { cout << "Gidget d'tor" << endl; }
};

void Talk(shared_ptr<Widget> w)
{
	cout << w.use_count() << endl;
	w->Talk();
}

int main()
{
	std::shared_ptr<Widget> wrappedPtr(nullptr);
	cout << wrappedPtr.use_count() << endl;
	wrappedPtr = std::make_shared<Gidget>();
	cout << wrappedPtr.use_count() << endl;

	Talk(wrappedPtr);
	
	if (true)
	{
		shared_ptr<Widget> inner = wrappedPtr;
		cout << inner.use_count() << endl;
	}
	cout << wrappedPtr.use_count() << endl;

	wrappedPtr.reset();
	cout << wrappedPtr.use_count() << endl;

	return 0;
}