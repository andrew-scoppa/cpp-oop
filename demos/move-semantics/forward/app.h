#pragma once
#include <iostream>

class Bigger {
	int _data = 100;
public:

	Bigger();

	Bigger(const Bigger& a);

	Bigger(Bigger&& a);

	int data();

	Bigger equals(const Bigger& a) const {
		std::cout << "op+ copy" << std::endl;
		return *this;
	}

	Bigger operator=(Bigger&& a) noexcept{
		std::cout << "op+ move" << std::endl;
		return *this;
	}
};

template<typename T>
void Func(T b) {
	std::cout << "Func " << b.data() << std::endl;
}

template<typename T>
void Wrapper(T&& b) {
	// arg is always lvalue
	Func<T>(std::forward<T>(b));  // Forward as lvalue or as rvalue, depending on T
	// Func<T>(b);
}

