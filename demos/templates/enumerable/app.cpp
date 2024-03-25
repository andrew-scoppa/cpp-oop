#include <iostream>
#include <algorithm>

template <typename T, size_t SIZE>
class EnumerableContainer
{
public:
    // nested class Enumerator
    class Enumerator
    {
    private:
        EnumerableContainer<T, SIZE> *m_outer;

    public:
        T *begin();
        T *end();
        Enumerator(EnumerableContainer *pOuter) : m_outer(pOuter){};
    };

private:
    T m_ar[SIZE];
    T *const m_begin = m_ar;
    T *const m_end = m_ar + SIZE;
public:
    EnumerableContainer()
    { };

    Enumerator GetEnumerator()
    {
        return  Enumerator(this);
    };

    T operator[](int i) const
    {
        // if i is out of bounds throw here
        if (i < 0 || i >= SIZE)
            throw std::logic_error("Out of bounds");
        return m_ar[i];
    }
    T &operator[](int i)
    {
        // if i is out of bounds throw here

        if (i < 0 || i >= SIZE)
            throw std::logic_error("Out of bounds");
        return m_ar[i];
    }
};

// implement half-open begin end
template <typename T, size_t SIZE>
T *EnumerableContainer<T, SIZE>::Enumerator::begin()
{
    return this->m_outer->m_begin;
}
template <typename T, size_t SIZE>
T *EnumerableContainer<T, SIZE>::Enumerator::end()
{
    return this->m_outer->m_end;
};

class Rational
{
private:
    int m_numerator;
    int m_denominator;

public:
    Rational(int num = 0, int den = 0) : m_numerator(num), m_denominator(den) {}
    operator double() const
    {
        return m_numerator / double(m_denominator);
    }
    bool operator>(const Rational &rhs) const
    {
        return (m_numerator / double(m_denominator)) > (rhs.m_numerator / double(rhs.m_denominator));
    }
    bool operator<(const Rational &rhs) const
    {
        return (m_numerator / double(m_denominator)) < (rhs.m_numerator / double(rhs.m_denominator));
    }
};

int main()
{
    using std::cout;
    using std::endl;
    const size_t SIZE = 10;

    EnumerableContainer<Rational, SIZE> array;
    for (size_t i = 0; i < SIZE; i++)
    {
        array[i] = Rational(i + 1, i + 2);
    }

    // retrieve enumerator
    EnumerableContainer<Rational, SIZE>::Enumerator p = array.GetEnumerator();

    // using the enumerator, sort array of Rational in descending order
    std::sort(p.begin(), p.end(), std::greater<Rational>());

    // use begin() end() to iterate over and print the value of the Rational
    for (const Rational *it = p.begin(); it < p.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << endl;

    return 0;
}