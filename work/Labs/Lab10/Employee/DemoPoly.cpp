//  DemoPoly.cpp
//
//  Demo program for polymorphism 

#include "Trace.h"
#include "Employee.h"

void PayReport(Employee** pEmp, int count)
{
	for (int i = 0; i < count; ++i)
		Trace(pEmp[i]->GetName(),"   ", pEmp[i]->GetPay());
}

int main()
{
	Employee* pEmp[10];
	int numEmp;

	pEmp[0] = new SalaryEmployee("Sally", 500);
	pEmp[1] = new WageEmployee("Wally", 40, 10);
	numEmp = 2;

	PayReport(pEmp, numEmp);

	return 0;
}

