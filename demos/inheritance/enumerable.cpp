#include <iostream>
#include <cstring>
#include <stdexcept>

#define SIZE 10

class IEnumerable;
class IEnumerator;

class IEnumerable
{
public:
    virtual IEnumerator *GetEnumerator() = 0;
};

class IEnumerator
{
public:
    virtual const int *begin() = 0;
    virtual const int *end() = 0;
    virtual const int *move_next() = 0;
    virtual const int *reset() = 0;
    virtual const int *current() = 0;
};

class EnumerableContainer : public IEnumerable
{
public:
    // begin nested class
    class Enumerator : public IEnumerator
    {
    private:
        EnumerableContainer *m_outer;

    public:
        const int *begin();
        const int *end();
        const int *move_next();
        const int *reset();
        const int *current();
        Enumerator(EnumerableContainer *pOuter) : m_outer(pOuter){};
    };
    // end nested class

private:
    int m_ar[SIZE]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int *m_current = m_ar;
    const int *const m_begin = m_ar;
    const int *const m_end = m_ar + SIZE;
    IEnumerator *m_enumerator = nullptr;

public:
    EnumerableContainer(){

    };

    IEnumerator *GetEnumerator()
    {
        return new Enumerator(this);
    };

    ~EnumerableContainer()
    {
        delete m_enumerator;
    }

    int operator[](int i) const
    {
        // if i is out of bounds throw here
        size_t elements = (m_end - m_begin) / sizeof(int);
        if (i < 0 || i > elements - 1)
            throw std::logic_error("Out of bounds");
        return m_ar[i];
    }
    int &operator[](int i)
    {
        // if i is out of bounds throw here
        size_t elements = (m_end - m_begin) / sizeof(int);
        if (i < 0 || i > elements - 1)
            throw std::logic_error("Out of bounds");
        return m_ar[i];
    }
};

// implement half-open begin end
const int *EnumerableContainer::Enumerator::begin()
{
    return this->m_outer->m_begin;
}
const int *EnumerableContainer::Enumerator::end()
{
    return this->m_outer->m_end;
};

const int *EnumerableContainer::Enumerator::move_next()
{
    if (this->m_outer->m_current + 1 == this->m_outer->m_end)
    {
        return nullptr;
    }

    return ++(this->m_outer->m_current);
}
const int *EnumerableContainer::Enumerator::reset()
{
    return this->m_outer->m_current = this->m_outer->m_begin - 1;
}

const int *EnumerableContainer::Enumerator::current()
{
    return this->m_outer->m_current;
};

int main()
{
    using std::cout;
    using std::endl;

    EnumerableContainer array;
    auto pEnumerator = array.GetEnumerator();

    for (auto it = pEnumerator->begin(); it < pEnumerator->end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    pEnumerator->reset();
    while (pEnumerator->move_next())
    {
        cout << *pEnumerator->current() << " ";
    };
}