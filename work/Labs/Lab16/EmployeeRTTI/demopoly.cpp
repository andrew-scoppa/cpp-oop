//  demopoly.cpp
//
//  Demo program for polymorphism 

#include "trace.h"
#include "employee.h"

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
	pEmp[2] = new SalesEmployee("Sue", 200, 4);
	pEmp[3] = (Employee*) new Object;
	numEmp = 4;
	
	for (int i = 0; i < numEmp; ++i)
		Trace(pEmp[i]->ToString());

	PayReport(pEmp, numEmp);

	for (int i = 0; i < numEmp; ++i)
		delete pEmp[i];

	return 0;
}

