#include "stdafx.h"

int daySerialNumber(int iDay, int iMonth, int iYear)
{
    int serialNumber = 0;
    int daysInMonth[] = { 0, 31, ifYearLeap(iYear) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = iMonth; i >= 1; i--)
    {
        if (i == iMonth)
            serialNumber += iDay;
        else
            serialNumber += daysInMonth[i];
    }
    return serialNumber;
}