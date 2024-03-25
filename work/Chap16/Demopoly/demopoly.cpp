//  demopoly.cpp
//
//  Demo program for polymorphism and RTTI

#include "trace.h"
#include "employee.h"
#include <typeinfo>

void PayReport(Employee** pEmp, int count)
{
	for (int i = 0; i < count; ++i)
	{
		char ch = ' ';
		SalesEmployee *se = dynamic_cast<SalesEmployee*>(pEmp[i]);
		if (se != nullptr){
			ch = '*';
		}
		Trace(ch, pEmp[i]->GetName(),"   ", pEmp[i]->GetPay());
	}
}

int main()
{
	Employee* pEmp[10];
	int numEmp;

	pEmp[0] = new SalaryEmployee("Sally", 500);
	pEmp[1] = new WageEmployee("Wally", 40, 10);
	pEmp[2] = new SalesEmployee("Sue", 200, 4);
	numEmp = 3;
	
	PayReport(pEmp, numEmp);

	for (int i = 0; i < numEmp; ++i)
		delete pEmp[i];

	return 0;
}
