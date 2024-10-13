#include "stdafx.h"

int* ConvertCharToInt(char date[], int arrDate[])
{
	char* b = new char[4];
	int n = 0, /*outPut[3],*/ k = 0;
	//cout << value << endl;

	for (int i = 0; i <= 10; i++)
	{
		if (date[i] == '.')
		{
			n = 0;
			int value = atoi(b);
			arrDate[k] = value;
			k++;
			continue;
			//std::cout << b[i];
		}
		b[n] = date[i];
		n++;
	}

	int value = atoi(b);
	arrDate[k] = value;

	return arrDate;
}
