#include <iostream>
#include <new>

class Heap
{
private:
    long *_data;

public:
    Heap(unsigned int size) : _data(new long[size]) {}

    ~Heap()
    {
        delete[] _data;
    }
};

class BigHeap : public Heap
{

public:
    BigHeap(unsigned size)
    try : Heap(size)
    {
    }
    catch (std::bad_alloc &ex)
    {
        std::cerr << "bad_alloc caught in itialization: " << ex.what();
    }
    catch (...)
    {
        std::cerr << "exception during construction" << std::endl;
    }
};

int main()
{
    BigHeap(100000);
}