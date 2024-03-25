// Employee.cpp

#include "Employee.h"

Employee::Employee(const char *name) : m_name(name) 
{
	Trace("Employee::Employee(const char*)"); 
}

Employee::~Employee() 
{
	Trace("Employee::~Employee()");
}

SalaryEmployee::SalaryEmployee(const char *name, int salary) 
	: Employee(name), m_salary(salary) 
{
	Trace("SalaryEmployee::SalaryEmployee(const char *, int)");
}

SalaryEmployee::~SalaryEmployee()
{
	Trace("SalaryEmployee::~SalaryEmployee()");
}

int SalaryEmployee::GetPay()
{
	return m_salary;
}

WageEmployee::WageEmployee(const char* name, int hours, int wage) 
	: Employee(name), m_hours(hours), m_wage(wage) 
{
	Trace("WageEmployee::WageEmployee(const char*,int,int)");
}

WageEmployee::~WageEmployee()
{
	Trace("WageEmployee::~WageEmployee()");
}

int WageEmployee::GetPay()
{
	return m_hours * m_wage;
}
