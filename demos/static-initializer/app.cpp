#include <iostream>
#include "app.h"

using namespace std;

class GlobalInit{
public:
	GlobalInit() {
		// initialize a
		Widget::set(39);
	}

} gi;

int main()
{
	cout << Widget::get();
    return 0;
}

