//  DemoEmp.cpp
//
//  Demo program for Employee classes

#include "Trace.h"
#include "Employee.h"

int main()
{
	SalaryEmployee sally("Sally", 500);
	WageEmployee susan("Susan", 40, 10);
	
	Trace("Sally's name = ", sally.GetName());
	Trace("Sally's salary = ", sally.GetSalary());
	Trace("Susan's name = ", susan.GetName());
	Trace("Susan's hours = ", susan.GetHours());
	Trace("Susan's wage = ", susan.GetWage());
	return 0;
}

