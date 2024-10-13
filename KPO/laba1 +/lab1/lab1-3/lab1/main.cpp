#include "stdafx.h"

using namespace std;

typedef struct birthDay
{
    int day;
    int mounth;
} BIRTH;

int main()
{

    int iYear, iMonth, iDay, serialNumber, dayBeforeBirthdayNumber, birthDay, birthMonth;
    
    input(iDay, iMonth, iYear, birthDay, birthMonth);

    cout << "Порядковый номер введенного дня: " << daySerialNumber(iDay, iMonth, iYear) << endl;
    cout << "День до вашего дня рождения: " << dayBeforeBirthday(birthDay, birthMonth, iDay, iMonth, iYear) << endl;
}