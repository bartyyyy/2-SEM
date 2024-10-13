#include "stdafx.h"
int NumDays(int isLeap, int birthInThisYear, int birthInLastYear, int day)
{
	int numDaysInThisYear = birthInThisYear - day;
	int daysInLastYear;
	if (isLeap == 0)
		daysInLastYear = 365 - birthInLastYear;
	else
		int daysInLastYear = 366 - birthInLastYear;
	int numDaysInLastYear = daysInLastYear + day;
	if (numDaysInThisYear < numDaysInLastYear)
		return numDaysInThisYear;
	return numDaysInLastYear;

}