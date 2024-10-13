#include "stdafx.h"

bool check(int day, int month, int year)
{
    int twelve[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day == 29 && ifYearLeap(year))
        return true;
    else if (day > twelve[month - 1]) {
        return false;
    }
    if (month > 12) {
        return false;
    }
    return true;
}