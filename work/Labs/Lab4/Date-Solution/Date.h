//  Date.h
//
//  Specification file for date class

#ifndef _DATE_H
#define _DATE_H

class Date
{
public:

    Date(short y = 2024, short m = 1, short d = 1);
    ~Date();
    void SetYear(short y);
    void SetMonth(short m);
    void SetDay(short d);
    short GetYear();
    short GetMonth();
    short GetDay();
    char* GetDateStr();

private:
    char buffer[20];
    short year;
    short month;
    short day;
};

#endif
