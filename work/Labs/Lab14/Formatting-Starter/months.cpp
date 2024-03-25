// months.cpp

#include <iostream>
using namespace std;

int main()
{
	int days[] = {31,28,31,30,31,30,
				  31,31,30,31,30,31};
	const char* months[] = {"January","February","March",
				"April","May","June",
				"July","August","September",
				"October","November","December"};
	int total = 0;
	for (int i = 0; i < 12; ++i)
	{
		cout << months[i] << "  " << days[i] << endl;
		total += days[i];
	}
	cout << "Total days = " << total << endl;
	return 0;
}
