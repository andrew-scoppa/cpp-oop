#include <iostream>
#include <cassert>
#include <stdexcept>
#include <new>

/*
Function Swap exchanges the values of two integers.
Arguments:
The function should take two integer pointers 'p1' and 'p2' as parameters.
Details:
The function should exchange the values of the integers pointed to by 'p1' and 'p2'.
Return Value:
The function should not return a value.
 */
void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/*
Function 'AllocIntArray'  allocates storage for an array of int on the heap and returns a pointer to the first element.
Arguments:
The function should take an integer parameter 'n' that specifies the number of elements in the array.
Details:
The function should allocate storage for an array of 'n' integers on the heap.
Return Value:
The function should return a pointer to the first element of the array.
If a BadAlloc exception is thrown, the function should log a message then return nullptr.
*/
int *AllocIntArray(int n)
{
    int *p = nullptr;
    try
    {
        p = new int[n];
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "Allocation failed: " << e.what() << std::endl;
        return nullptr;
    }
    return p;
}

/*
Function 'DeallocIntArray'  deallocates the storage for an array of int on the heap.
Arguments:
The function should take a reference to a pointer 'p' to the first element of the array as a parameter.
Details:
The function should set the pointer to nullptr after deallocation.
Return Value:
The function should not return a value.
*/
void DeallocIntArray(int *&p)
{
    delete[] p;
    p = nullptr;
}

/*
This program demonstrates how to swap two integers using pointers.
*/
int main()
{
    // allocate storage for an array of 2 integers on the heap
    int *p = AllocIntArray(2);
    assert(p != nullptr);

    // Prompt the user to enter two integers
    std::cout << "Enter two integers: ";
    std::cin >> p[0] >> p[1];

    // Swap the values of the two integers
    Swap(&p[0], &p[1]);

    // Output the swapped values
    std::cout << "Swapped values: " << p[0] << " " << p[1] << std::endl;

    // Deallocate the storage
    DeallocIntArray(p);

    return 0;
}