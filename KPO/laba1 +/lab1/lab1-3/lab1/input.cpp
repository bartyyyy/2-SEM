#include "stdafx.h"

void input(int& iDay, int& iMonth, int& iYear, int& birthday, int& birthmonth)
{
    int date;
    do
    {
        cout << "Введите дату в формате деньмесяцгод\n";
        cin >> date;

        iDay = date / 1000000;
        iMonth = (date / 10000) % 100;
        iYear = date % 10000;

        if (!check(iDay, iMonth, iYear))
            cout << "Некорректная дата, пожалуйста, повторите ввод" << endl;
    } while (!check(iDay, iMonth, iYear));

    do
    {
        cout << "Введите дату рождения в формате день месяц\n";
        cin >> birthday;
        cin >> birthmonth;

        if (birthmonth > 12 || birthmonth < 1 || birthday > 31 || birthday < 1)
            cout << "Некорректная дата, пожалуйста, повторите ввод" << endl;
    } while (birthmonth > 12 || birthmonth < 1 || birthday > 31 || birthday < 1);
}