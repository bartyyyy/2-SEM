#include "stdafx.h"

int dayBeforeBirthday(int day, int mounth, int iDay, int iMonth, int iYear)
{
    int dayBeforeBirthdayNumber = 0;
    int daysInMonth[] = { 0, 31, ifYearLeap(iYear) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = iMonth; i != mounth; i = (i % 12) + 1)
    {
        if (i == iMonth)
            dayBeforeBirthdayNumber += daysInMonth[i] - iDay;
        else
            dayBeforeBirthdayNumber += daysInMonth[i];
    }
    dayBeforeBirthdayNumber += day;
    return dayBeforeBirthdayNumber;
}