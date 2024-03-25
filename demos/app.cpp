#include <iostream>
#include <functional>

std::function<int(void)> Func(){
    static int a = 0;
    return [] {return ++a; };
}
int main() {
    auto a = Func();
    auto b = Func();
    std::cout << a() << " " << b();
    // What will be displayed?
};
