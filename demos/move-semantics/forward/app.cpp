#include "app.h"
#include <iostream>

Bigger::Bigger() {
	std::cout << "default" << std::endl;
};

Bigger::Bigger(const Bigger& a) {
	std::cout << "copy" << std::endl;
};

Bigger::Bigger(Bigger&& a) {
	std::cout << "move" << std::endl;
};

int Bigger::data(){
	return _data;
}

int main()
{
	Bigger b;
	Wrapper(std::move(b));
	return 0;
}
