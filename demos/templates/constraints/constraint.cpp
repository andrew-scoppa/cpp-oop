#include <iostream>

template<typename T>
T max(T a, T b){
    // static_assert(std::is_arithmetic<T>::value, "arithmetic value required");
    return a > b ? a : b;

}
void CompareStr()
{
	const char *a = "rook";
	const char *b = "checkmate";

	const char *c = max(a, b);

	std::cout << c << std::endl;
}

int main(){
    int a = 10;
    int b = 20;

    std::cout << max(a,b) << std::endl;
}

