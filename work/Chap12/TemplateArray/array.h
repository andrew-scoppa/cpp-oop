template <class E> class Array
{
public:
	Array(int size = 10);
	~Array() {delete [] m_array;};
	Array& operator=(const Array&);
	long size(void) const { return m_lSize;};
	E& operator[](int index) const { return m_array[index];};
private:
	void init(int size);
	long m_lSize;
	E* m_array;
};

template <class E> void Array<E>::init(int size)
{
	m_lSize = size;
	m_array = new E[size];
	for (int i = 0; i < m_lSize; i++)
		m_array[i] = 0;
}

template <class E> Array<E>& Array<E>::operator =(const Array& array)
{
	if (this != &array)
	{
		delete [] m_array;
		init(array.m_lSize);
		for (int i = 0; i < m_lSize; i++)
			m_array[i] = array[i];
	}
	return *this;
}

template <class E> Array<E>::Array(int size)
{
	init(size);
}
