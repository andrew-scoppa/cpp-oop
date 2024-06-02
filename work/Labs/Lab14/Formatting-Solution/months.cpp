// months.cpp

#include <iostream>
#include <iomanip>
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
		cout << left << setw(15) << months[i]
			 << right << setw(3) << days[i] << endl;
		total += days[i];
	}
	cout << left << setw(15) << "Total Days = "
		 << right << setw(3) << total << endl;

	return 0;
}
