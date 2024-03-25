// employee.h

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "trace.h"
#include "strn.h"
#include "object.h"

class Employee : public Object
{
public:
	Employee(const char *name = ""); 
	virtual ~Employee(); 
	void SetName(const char *name) 
		{ m_name = name;}
	const char* GetName() const {return m_name;}
	virtual int GetPay() = 0;
//	const char* ToString() {return "Employee";}
private:
	String m_name;
};

class SalaryEmployee : public Employee
{
public:
	SalaryEmployee(const char *name = "", 
		int salary = 0); 
	~SalaryEmployee();
	int GetPay();
//	const char* ToString() {return "SalaryEmployee";}
private:
	int m_salary;
};
						
class WageEmployee : public Employee
{   
public:
    WageEmployee(const char* name = "", 
		int hours = 0, int wage = 0);
	~WageEmployee();
	int GetPay();
//	const char* ToString() {return "WageEmployee";}
private:
    int m_hours;
    int m_wage;
};

class SalesEmployee : public Employee
{   
public:
    SalesEmployee(const char* name = "", 
		int sales = 0, int commission = 0);
	~SalesEmployee();
	int GetPay();
//	const char* ToString() {return "SalesEmployee";}
private:
    int m_sales;
    int m_commission;
};

#endif
