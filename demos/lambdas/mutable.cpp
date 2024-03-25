#include <iostream>

int main(){
	int a = 5;
	int b = 10;
	[=] () mutable{
		int temp = a;
		a = b;
		b = temp;
      std::cout << a << " " << b << std::endl;

	}();
	std::cout << a << " " << b << std::endl;
   return 0;
}
