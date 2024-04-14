// BadAllocation.cpp

#include <iostream>
#include <new>
#include <climits>

class Big
{
	// 1 million long integers initialzed to 0
	long arr[1000000] = {0};
};

int main()
{
    long n = LONG_MAX;
    Big* singleBig = new Big();
    std::cout << "Size of one Big instance (bytes): " << sizeof(*singleBig) << std::endl;
    delete singleBig;  // Free the memory for singleBig

    std::cout << "Attempt to create " << n << " instances..." << std::endl;
    try
    {
        Big* huge = new Big[n];
        std::cout << "Succeeded" << std::endl;
        delete[] huge;  // Free the memory for the array
    }
    catch (std::bad_alloc &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
}