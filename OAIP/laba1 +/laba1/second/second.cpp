#include <iostream>
#include <cstdarg>

int mn(int count, ...) {
    va_list args;
    va_start(args, count);

    int min = va_arg(args, int);

    for (int i = 1; i < count; ++i) {
        int num = va_arg(args, int);
        if (num < min) {
            min = num;
        }
    }

    va_end(args);

    return min;
}

int main() {

    int num1 = mn(2, 10, 5);
    int num2 = mn(4, 20, 15, 30, 25);
    int num3 = mn(3, 8, 12, 6);

    std::cout << "Минимальное число из 10 и 5: " << num1 << std::endl;
    std::cout << "Минимальное число из 20, 15, 30 и 25: " << num2 << std::endl;
    std::cout << "Минимальное число из 8, 12 и 6: " << num3 << std::endl;

    return 0;
}