#include "stdafx.h"

int Order(int isLeap, int day, int month)
{
	int days1 = 31, days2 = 30, days3 = 28, out = 0;
	if (isLeap == 1)
		days3 = 29;
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
			out += days3;
		else if (i == 8)
			out += days1;
		else if (i % 2 == 0 && i < 8)
			out += days2;
		else if (i % 2 != 0 && i < 8)
			out += days1;
		else if (i % 2 != 0 && i > 8)
			out += days2;
		else if (i % 2 == 0 && i > 8)
			out += days1;
	}

	out += day;
	return out;
}

int* Date(int isLeap, int order)
{
	int* out = new int[2];
	int days1 = 31, days2 = 30, days3 = 28, day;
	if (isLeap == 1)
		days3 = 29;
	int i = 0;
	while (order > 0)
	{
		i++;
		if (1 <= order <= 31)
			day = order;
		if (i == 2)
			order -= days3;
		else if (i == 8)
			order -= days1;
		else if (i % 2 == 0 && i < 8)
			order -= days2;
		else if (i % 2 != 0 && i < 8)
			order -= days1;
		else if (i % 2 != 0 && i > 8)
			order -= days2;
		else if (i % 2 == 0 && i > 8)
			order -= days1;
	}

	out[0] = i;
	out[1] = day;

	return out;
}

