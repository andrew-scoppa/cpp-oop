//  demopoly.cpp
//
//  Demo program for polymorphism
#include "Employee.h"
#include "Trace.h"

void PayReport(const Employee **pEmp, long count)
{
	int total = 0;
	for (int i = 0; i < count; ++i)
	{
		total += pEmp[i]->GetPay();
		std::cout << pEmp[i]->GetName() << "\t" << pEmp[i]->GetPay() << std::endl;
	}
	std::cout << "Total: " << total << std::endl;
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
