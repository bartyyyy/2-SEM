#include <iostream>
#include <cmath>

double equation1(double x) {
    return pow(x, 3) + 2 * x - 1;
}

double equation2(double x) {
    return exp(x) - 2;
}

double bisectionMethod(double (*equation)(double), double a, double b, double eps) {
        double c;
        while ((b - a) >= eps) {
            c = (a + b) / 2;
            if (equation(a) * equation(c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
        }
        return c;
}

int main() {
    double epsilon;

    std::cout << "Введите значение эпсилон: ";
    std::cin >> epsilon;

    double a1, b1;
    std::cout << "Введите интервал для уравнения (x^3)+2x-1 (a b): ";
    std::cin >> a1 >> b1;

    double root1 = bisectionMethod(equation1, a1, b1, epsilon);
    std::cout << "Корень уравнения (x^3)+2x-1: " << root1 << std::endl;

    double a2, b2;
    std::cout << "Введите интервал для уравнения (e^x)-2 (a b): ";
    std::cin >> a2 >> b2;

    double root2 = bisectionMethod(equation2, a2, b2, epsilon);
    std::cout << "Корень уравнения (e^x)-2: " << root2 << std::endl;

    return 0;
}