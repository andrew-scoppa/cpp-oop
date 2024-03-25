// Employee.h

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <cstring>

class Employee
{
public:
	enum {MAXNAME = 20};
	Employee(const char *name = "")
		{strcpy(m_name, name);}
	void SetName(const char *name) 
		{strcpy(m_name, name);}
	const char* GetName() const {return m_name;}
private:
	char m_name[MAXNAME];
};

class SalaryEmployee : public Employee
{
public:
	SalaryEmployee(const char *name, int salary)
		: Employee(name) {m_salary = salary;}
	void SetSalary(int salary) {m_salary = salary;}
	int GetSalary() const {return m_salary;}
protected:
	int m_salary;
};

class WageEmployee : public Employee
{   
public:
	WageEmployee(const char* name, int hours, int wage)
		: Employee(name){m_hours = hours; m_wage = wage;}
	void SetHours(int hours) {m_hours = hours;}
	int GetHours() const {return m_hours;}
	void SetWage(int wage) {m_wage = wage;}
	int GetWage() const {return m_wage;}
private:
	int m_hours;
	int m_wage;
};

#endif
        