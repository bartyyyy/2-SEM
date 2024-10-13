#pragma once
#include<windows.h>
#include <iostream>

int* ConvertCharToInt(char date[], int arrDate[]);
int Order(int isLeap, int day, int month);
int* Date(int isLeap, int order);
int NumDays(int isLeap, int birthInThisYear, int birthInLastYear, int day);

