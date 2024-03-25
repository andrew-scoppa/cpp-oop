// employee.h

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "strn.h"

class Employee
{
public:
	Employee(const char *name = "") : m_name(name) 
	{
		Trace("Employee::Employee(const char*)"); 
	}
	~Employee() 
	{
		Trace("Employee::~Employee()");
	}
	void SetName(const char *name) 
		{ m_name = name;}
	const char* GetName() const {return m_name;}
	int GetPay() {return 100; }  // arbitrary default value
private:
	String m_name;
};

class SalaryEmployee : public Employee
{
public:
	SalaryEmployee(const char *name = "", 
		int salary = 0) : Employee(name), 
		m_salary(salary) 
	{
		Trace("SalaryEmployee::SalaryEmployee(const char *, int)");
	}
	~SalaryEmployee()
	{
		Trace("SalaryEmployee::~SalaryEmployee()");
	}
	void SetSalary(int salary) {m_salary = salary;}
	int GetSalary() {return m_salary;}
	int GetPay() { return m_salary; }
private:
	int m_salary;
};
						
class WageEmployee : public Employee
{   
public:
    WageEmployee(const char* name = "", 
		int hours = 0, int wage = 0) : Employee(name),
		m_hours(hours), m_wage(wage) 
	{
		Trace("WageEmployee::WageEmployee(const char*,int,int)");
	}
	~WageEmployee()
	{
		Trace("WageEmployee::~WageEmployee()");
	}
    void SetHours(int hours) {m_hours = hours;}
    int GetHours() {return m_hours;}
    void SetWage(int wage) {m_wage = wage;}
    int GetWage() {return m_wage;}
	int GetPay() {return m_hours * m_wage; }
private:
    int m_hours;
    int m_wage;
};

#endif
        