//  TestDate.cpp
//
//  Test program for Date class.

#include <string>
#include "Trace.h"
#include "Date.h"


void PrintDate(Date date)
{
	Trace("year = ", date.GetYear());
	Trace("month = ", date.GetMonth());
	Trace("day = ", date.GetDay());
}

int main()
{
	Date date1, date2(2000, 1, 1);
	char *datebuf;
	datebuf = date1.GetDateStr();
	cout << "default date = " << datebuf << '\n';
	datebuf = date2.GetDateStr();
	cout << "date2 = " << datebuf << '\n';

	PrintDate(date1);

	//	Change default date

	date1.SetYear(2022);
	date1.SetMonth(4);
	date1.SetDay(15);

	PrintDate(date1);

	return 0;
}
