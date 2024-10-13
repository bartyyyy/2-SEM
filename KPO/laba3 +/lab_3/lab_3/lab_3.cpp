#include "stdafx.h"

using namespace std;
int IsLeapYear(int year)
{
	if (year % 4 == 0)
		return 1;
	return 0;
}

void holidays(bool isLeap, int ordinalDay) {

    switch (ordinalDay) {
    case 1: {
        cout << "Новый год" << endl;
        break;
    }

    case 7: {
        cout << "Православное Рождество" << endl;
        break;
    }
    case 256: {
        cout << "День программиста" << endl;
        break;
    }
    case 122: {
        if (isLeap) {
            cout << "Праздник труда" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 121: {
        if (!isLeap) {
            cout << "Праздник труда" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 129: {
        if (!isLeap) {
            cout << "День Победы" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 130: {
        if (isLeap) {
            cout << "День Победы" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 185: {
        if (isLeap) {
            cout << "День Независимости РБ" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 184: {
        if (!isLeap) {
            cout << "День Независимости РБ" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 311: {
        if (!isLeap) {
            cout << "День Октябрьской революции" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 312: {
        if (isLeap) {
            cout << "День Октябрьской революции" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 359: {
        if (!isLeap) {
            cout << "Католическое Рождество" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    case 360: {
        if (isLeap) {
            cout << "Католическое Рождество" << endl;
            break;
        }
        else {
            cout << "Обычный день" << endl;
            break;
        }
    }
    default: {
        cout << "В этот день нет праздника" << endl;
        break;
    }
    }

}

int main()
{

    int year, orderday;
    cout << "введите год ";
    cin >> year;
    int isleap = IsLeapYear(year);
    cout << "введите порядковый номер дня ";
    cin >> orderday;
    if ((orderday > 366 && isleap == 0) || (orderday > 365 && isleap == 1))
        cout << "неверные данные";
    else
    {
        cout << endl;

        int* date = Date(isleap, orderday);
        cout << "дата: " << date[1] << "." << date[0] << "." << year << endl;
        holidays(isleap, orderday);
    }

	return 0;
}