//  demopoly.cpp
//
//  Demo program for polymorphism
#include "Employee.h"
#include "Trace.h"

void PayReport(const Employee **pEmp, long count)
{
	for (int i = 0; i < count; ++i){
		cout << pEmp[i]->GetName() << "\t" << pEmp[i]->GetPay() << endl;
	}
}

int main()
{
	const Employee *pEmp[] = {
		new SalaryEmployee("Sally", 500),
		new WageEmployee("Wally", 40, 10),
		new SalesEmployee("Sue", 200, 4),
		nullptr};

	const Employee **pEmpNav = pEmp;

	while (*pEmpNav != nullptr){ ++pEmpNav;}

	long numEmp = pEmpNav - pEmp;

	PayReport(pEmp, numEmp);

	for (int i = 0; i < numEmp; ++i)
		delete pEmp[i];

	
	cout << "Finished" << endl;
	return 0;
}
