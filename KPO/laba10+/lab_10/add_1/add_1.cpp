#include <iostream>

int main() {
    int x = 5;
    int y = -3;

    auto checkPositive = [](int num) {
        return num > 0;
        };

    // Проверяем числа на положительность
    std::cout << x << " положительное? "  << checkPositive(x) << std::endl;
    std::cout << y << " положительное? " << checkPositive(y) << std::endl;

    return 0;
}
