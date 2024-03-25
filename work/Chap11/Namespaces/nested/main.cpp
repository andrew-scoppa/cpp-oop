// ansihello.cpp

#include <iostream>

namespace ns1
{
	std::string message("Message from ns1\n");
	namespace ns2
	{
		using std::string;
		string message("Message from ns1::ns2\n");
	}
}



int main()
{
	std::cout << ns1::message;
	std::cout << ns1::ns2::message;

	return 0;
}
