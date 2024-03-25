//  Date.cpp
//
//  Implementation file for date class

#include <cstdio>
#include "Trace.h"
#include "Date.h"

Date::Date(short y, short m, short d)
{
 	Trace("Date::Date(short y, short m, short d)");
    year = y; month = m; day = d;
}

Date::~Date()
{
	Trace("Date::~Date()");
}

void Date::SetYear(short y)
{
    year = y;
}
    
void Date::SetMonth(short m)
{
    month = m;
}
    
void Date::SetDay(short d)
{
    day = d;
}

short Date::GetYear()
{
    return year;
}
    
short Date::GetMonth()
{
    return month;
}
  
short Date::GetDay()
{
    return day;
}
  
char * Date::GetDateStr()
{
    sprintf(buffer, "%d/%d/%d", month, day, year);
    return buffer;
}    