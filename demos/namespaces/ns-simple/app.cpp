#include <iostream>
using std::cout, std::string;
namespace ns1
{
    string message("Buenas dias\n");
}
namespace ns2
{
    string message("Good day\n");
}
int main()
{
    using namespace ns1;
    cout << message << std::endl;
    using std::endl;
    cout << ns2::message << endl;
}
