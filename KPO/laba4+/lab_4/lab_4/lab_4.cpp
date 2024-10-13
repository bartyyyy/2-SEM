#include <iostream>
#include <tchar.h>

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
    day dd;
    month mm;
    year yyyy;
};

// Перегрузка оператора '<' для структуры Date
bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.yyyy != rhs.yyyy)
        return lhs.yyyy < rhs.yyyy;
    if (lhs.mm != rhs.mm)
        return lhs.mm < rhs.mm;
    return lhs.dd < rhs.dd;
}

// Перегрузка оператора '==' для структуры Date
bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.yyyy != rhs.yyyy)
        return 0;
    if (lhs.mm != rhs.mm)
        return 0;
    return lhs.dd == rhs.dd;
}

// Перегрузка оператора '>' для структуры Date
bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.yyyy != rhs.yyyy)
        return lhs.yyyy > rhs.yyyy;
    if (lhs.mm != rhs.mm)
        return lhs.mm > rhs.mm;
    return lhs.dd > rhs.dd;
}

int _tmain(int arg, _TCHAR* argv[])
{

    Date date1 = { 27, 1, 1993 };
    Date date2 = { 7, 1, 1993 };
    Date date3 = { 7, 1, 1980 };

    if (date1 < date2) std::cout << "истина\n";
    else std::cout << "лож\n";

    if (date1 > date2) std::cout << "истина\n";
    else std::cout << "лож\n";

    if (date1 == date2) std::cout << "истина\n";
    else std::cout << "лож\n";

    if (date1 == date3) std::cout << "истина\n";
    else std::cout << "лож\n";
}
