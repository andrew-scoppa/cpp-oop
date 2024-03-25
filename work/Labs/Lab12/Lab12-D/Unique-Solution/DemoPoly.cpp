//  demopoly.cpp
//
//  Demo program for polymorphism

#include "employee.h"
#include "trace.h"
#include <memory>
#include <vector>
#include <algorithm>

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
	vector<unique_ptr<const Employee>> vEmp;
	vEmp.push_back(unique_ptr<const Employee>(new SalaryEmployee("Sally", 500)));
	vEmp.push_back(unique_ptr<const Employee>(new WageEmployee("Wally", 40, 10)));
	vEmp.push_back(unique_ptr<const Employee>(new SalesEmployee("Sue", 200, 4)));

	for (auto it = vEmp.begin(); it < vEmp.end(); ++it)
	{
		std::cout << (*it)->GetName() << '\t' << (*it)->GetPay() << std::endl;
	}

	PayReport((const Employee **)vEmp.data(), vEmp.size());

	std::cout << "Finished" << std::endl;
	return 0;
}
