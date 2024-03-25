#include <iostream>
#include <cstring>

#define SIZE 10

class EnumerableContainer
{
public:
    // Begin nested Enumerator
    class Enumerator
    {
    private:
        EnumerableContainer *m_outer;

    public:
        const int *begin() const;
        const int *end() const;
        Enumerator(EnumerableContainer *pOuter) : m_outer(pOuter){};
    };
    // End nested Enumerator

private:
    int m_ar[SIZE]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const int *const m_begin = m_ar;
    const int *const m_end = m_ar + SIZE;

public:
    EnumerableContainer(){};

    Enumerator GetEnumerator()
    {
        return Enumerator(this);
    };

    int operator[](int i) const
    {
        // if i is out of bounds throw here
        return m_ar[i];
    }
    int &operator[](int i)
    {
        // if i is out of bounds throw here
        return m_ar[i];
    }

    ~EnumerableContainer()
    {
    }
};

const int *EnumerableContainer::Enumerator::begin() const
{
    return m_outer->m_begin;
}
const int *EnumerableContainer::Enumerator::end() const
{
    return m_outer->m_end;
}

int main()
{
    using std::cout;
    using std::endl;

    EnumerableContainer array;

    const auto enumerator = array.GetEnumerator();

    cout << "*for loop - begin to end*" << endl;
    for (auto it = enumerator.begin(); it < enumerator.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "*while* loop - end to begin" << endl;
    auto current = enumerator.end();
    while (--current >= enumerator.begin())
    {
        cout << *current << " ";
    }

    cout << endl;
}
