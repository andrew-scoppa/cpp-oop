// Vector.h

class Vector
{
public:
	static int size;
	Vector();
	~Vector();
	void Set(int* arr);
	void Print() const;
	int operator * (const Vector& v2);
	friend int DotProduct (const Vector& v1,
						   const Vector& v2);
private:
	int* m_vec;

};

