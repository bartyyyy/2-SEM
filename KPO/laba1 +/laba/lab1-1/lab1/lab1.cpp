#include <iostream>

using namespace std;

bool ifYearLeap(int);
int daySerialNumber(int, int, int);
int dayBeforeBirthday(int, int, int, int, int);
bool check(int, int, int);

typedef struct birthDay
{
    int day;
    int mounth;
} BIRTH;

int main()
{

    int date;
    int iYear, iMonth, iDay, serialNumber, dayBeforeBirthdayNumber;
    BIRTH birthday;
    do
    {
        cout << "Введите дату в формате ДДММГГГГ\n";
        cin >> date;

        iDay = date / 1000000;
        iMonth = (date / 10000) % 100;
        iYear = date % 10000;

        if (!check(iDay, iMonth, iYear))
            cout << "Дата введена некорректно повторите ввод" << endl;
    } while (!check(iDay, iMonth, iYear));

    do
    {
        cout << "Введите вашу дату рождения в формате ДД ММ\n";
        cin >> birthday.day;
        cin >> birthday.mounth;

        if (birthday.mounth > 12 || birthday.mounth < 1 || birthday.day > 31 || birthday.day < 1)
            cout << "Дата введена некорректно повторите ввод" << endl;
    } while (birthday.mounth > 12 || birthday.mounth < 1 || birthday.day > 31 || birthday.day < 1);
    //------------------------------------------

    serialNumber = daySerialNumber(iDay, iMonth, iYear);
    dayBeforeBirthdayNumber = dayBeforeBirthday(birthday.day, birthday.mounth, iDay, iMonth, iYear);

    cout << "Порядковый номер введенного дня: " << serialNumber << endl;
    cout << "День до вашего дня рождения: " << dayBeforeBirthdayNumber << endl;
}

//--------------------------------------
bool ifYearLeap(int iYear) // Проверка на високосный год
{
    return iYear % 4 == 0 && (iYear % 100 != 0 || iYear % 400 == 0);
}

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

int dayBeforeBirthday(int day, int mounth, int iDay, int iMonth, int iYear)
{
    int dayBeforeBirthdayNumber = 0;
    int daysInMonth[] = { 0, 31, ifYearLeap(iYear) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = iMonth; i != mounth; i = (i % 12) + 1)
    {
        if (i == iMonth)
            dayBeforeBirthdayNumber += daysInMonth[i] - iDay;
        else
            dayBeforeBirthdayNumber += daysInMonth[i];
    }
    dayBeforeBirthdayNumber += day;
    return dayBeforeBirthdayNumber;
}

bool check(int day, int month, int year) 
{ // Добавлены аргументы в функцию check
    int twelve[]{ 31, ifYearLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > twelve[month - 1]) {
        return false;
    }
    if (month > 12) {
        return false;
    }
    return true; 
}