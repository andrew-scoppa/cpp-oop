#include <iostream>
#include <functional>

using namespace std;

function<int(void)> Func()
{
    static int a=1;
    return [&] {return ++a; };
}

int main() {

    auto a = Func();
    auto b = Func();
    cout << a() << " " << b();

};
