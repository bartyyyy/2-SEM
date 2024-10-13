#include "stdafx.h"

bool ifYearLeap(int iYear) 
{
    return iYear % 4 == 0 && (iYear % 100 != 0 || iYear % 400 == 0);
}