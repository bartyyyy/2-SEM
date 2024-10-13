#pragma once
#include "stdafx.h"

bool ifYearLeap(int iYear); 
int daySerialNumber(int iDay, int iMonth, int iYear);
int dayBeforeBirthday(int day, int mounth, int iDay, int iMonth, int iYear);
bool check(int day, int month, int year);
void input(int& iDay, int& iMonth, int& iYear, int& birthday, int& birthmonth);