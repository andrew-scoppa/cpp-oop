// array.h

#ifndef _ARRAY_H
#define _ARRAY_H

#include <assert.h>
#include "trace.h"

template<class T>
class Array
{
public:
	Array(int size = 10);
	~Array();
	void SetAt(int i, const T& x);
	T GetAt(int i);
	void Print();
private:
	int m_size;
	T* m_array;
};

template<class T>
Array<T>::Array(int size)
{
	Trace("Array::Array(int)");
	m_size = size;
	m_array = new T[size];
	assert(m_array != NULL);
	for (int i = 0; i < size; ++i)
		m_array[i] = 0;
}

template<class T>
Array<T>::~Array()
{
	Trace("Array::~Array()");
	delete [] m_array;
}

template<class T>
void Array<T>::SetAt(int i, const T& x)
{
//	assert((i >= 0) && (i < m_size));
	if ( (i < 0) || (i >= m_size) )
		throw ("Out of bounds");
	m_array[i] = x;
}

template<class T>
T Array<T>::GetAt(int i)
{
//	assert((i >= 0) && (i < m_size));
	if ( (i < 0) || (i >= m_size) )
		throw ("Out of bounds");
	return m_array[i];
}

template<class T>
void Array<T>::Print()
{
	for (int i = 0; i < m_size; ++i)
		Trace("array[", i, "] = ", m_array[i]);
}
#endif
