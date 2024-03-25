#include <iostream>

// forward declaration
template <typename>
struct argType;

template <typename R, typename A, typename B, typename C>
struct argType<R(A, B, C)>
{
  using typeA = A;
  using typeB = B;
  using typeC = C;
};

class Foo{};

void foo(int a, double b, Foo c)
{
  std::cout << "In foo(int, double, Foo)" << std::endl;
  std::cout << typeid(a).name() << std::endl;
  std::cout << typeid(b).name() << std::endl;
  std::cout << typeid(c).name() << std::endl;
};

int main()
{
  int a = 0;
  double b = 0.0;
  Foo f;
  auto t = static_cast<typename argType<decltype(foo)>::typeA>(a);
  auto u = static_cast<typename argType<decltype(foo)>::typeB>(b);
  auto v = static_cast<typename argType<decltype(foo)>::typeC>(f);
  std::cout << "In main()" << std::endl;
  std::cout << typeid(t).name() << std::endl;
  std::cout << typeid(u).name() << std::endl;
  std::cout << typeid(v).name() << std::endl;
  foo(0, 0, f);
}