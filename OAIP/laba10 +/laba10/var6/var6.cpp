#include <iostream>
using namespace std;

int A(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return A(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return A(m - 1, A(m, n - 1));
    }
}

int main() {
    int m, n;
    cout << "Введите целые неотрицательные числа m и n: ";
    cin >> m >> n;
    if (m < 0 || n < 0) {
        cout << "Ошибка: m и n должны быть неотрицательными." << endl;
        return 1;
    }
    int result = A(m, n);

    cout << "Результат вычисления A(" << m << ", " << n << "): " << result << endl;

    return 0;
}
