// Vector.h

class Vector
{
public:
	static int size;
	Vector();
	~Vector();
	void Set(int* arr);
	void Print();
	int DotProduct (const Vector& v);
private:
	int* m_vec;
};