#include <iostream>
using namespace std;

int numsq(int a, int b) {
    if (b == 0)
        return 0;

    if (a > b)
        return numsq(b, a - (a / b) * b);

    return numsq(b, a % b) + (a / b);
}

int main() {
    int a, b;
    cout << "Введите стороны прямоугольника a и b: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Ошибка: стороны прямоугольника должны быть натуральными числами." << endl;
        return 1;
    }

    int result = numsq(a, b);

    cout << "Количество полученных квадратов: " << result << endl;

    return 0;
}
