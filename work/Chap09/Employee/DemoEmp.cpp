//  DemoEmp.cpp
//
//  Demo program for Employee classes

#include "Trace.h"
#include "Employee.h"

int main()
{
	SalaryEmployee sally("Laura", 500);
	WageEmployee larry("Larry", 40, 10);
	
	Trace("Laura's name = ", sally.GetName());
	Trace("Laura's salary = ", sally.GetSalary());
	Trace("Larry's name = ", larry.GetName());
	Trace("Larry's hours = ", larry.GetHours());
	Trace("Larry's wage = ", larry.GetWage());
	return 0;
}

