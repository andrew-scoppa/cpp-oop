
#include <iostream>
using namespace std;

class Employee
{
public:
	Employee(bool fulltime, double startingSalary = 10000)
		: m_salary(startingSalary), _fulltime(fulltime)
	{
		m_empID = ++EMPID;
	};
	// function operator
	void RaiseSalary(double pctRaise) { m_salary *= (1.0 + pctRaise / 100); }
	double GetSalary(void) const { return m_salary; }
	long GetID() { return m_empID; };
	bool IsFulltime() const { return _fulltime; }
	static void Raise(Employee *pEmp, double pctRaise)
	{
		pEmp->RaiseSalary(pctRaise);
	}
	static long EMPID;

private:
	double m_salary;
	long m_empID;
	bool _fulltime;
};
long Employee::EMPID = 100;

template <typename T, typename TF, typename PR>
void transform(T *start, T *end, TF func, PR where, double pctRaise = 5)
{
	T *current;
	current = start;
	while (current != end)
	{
		if (where(current))
		{
			func(current, pctRaise);
		}
		current++;
	}
}

struct FullTime
{
	bool operator()(Employee *emp)
	{
		return emp->IsFulltime();
	}
};

bool IsFulltime(Employee *emp)
{
	return emp->IsFulltime();
}

int main()
{

	Employee EmpList[] =
		{Employee(true, 30000),
		 Employee(false, 45000),
		 Employee(true, 25000),
		 Employee(true, 35000),
		 Employee(false, 15000)};

	cout << "Before transform:" << endl;
	for (int i = 0; i < 5; i++)
		cout << EmpList[i].GetID() << "  " << EmpList[i].GetSalary() << endl;

	transform(EmpList, EmpList + 3, Employee::Raise, IsFulltime, 20);     // 20% raise if FT
	transform(EmpList + 3, EmpList + 5, Employee::Raise, FullTime(), 10); // 10% raise if FT

	cout << "After transform:" << endl;
	for (int i = 0; i < 5; i++)
		cout << EmpList[i].GetID() << "  " << EmpList[i].GetSalary() << endl;
}
