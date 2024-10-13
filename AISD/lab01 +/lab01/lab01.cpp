#include <iostream>
#include <time.h> 

using namespace std;

long long int fibonachiFunc(int);

int main() {

    int n;

    printf("Введите N :");
    cin >> n;
    if (n < 0)
        return printf("Вы ввели неверное число");
    if (n == 0)
        return printf("число фибоначи = 0");
    if (n == 1)
        return printf("число фибоначи = 1");

    clock_t start = clock();        

    unsigned long long int* fibonaci = new unsigned long long int[n + 2];
    *fibonaci = 0;
    *(fibonaci + 1) = 1;

    for (int i = 2; i < n; i++) {
        *(fibonaci + i) = *(fibonaci + i - 1) + *(fibonaci + i - 2);
    }

    clock_t end = clock();
    long double seconds = (long double)(end - start) / CLOCKS_PER_SEC;

    int minutes = static_cast<int>(seconds) / 60;

    printf("\nчисло фибоначи = %llu\n", *(fibonaci + n - 1));
    printf("Время: %d минуты, %f секунды для цикла\n", minutes, seconds);
    delete[] fibonaci;
    
    clock_t funcStart = clock();

    long long int fibonaciCounter = fibonachiFunc(n - 1);

    clock_t funcEnd = clock();
    long double funcSeconds = (long double)(funcEnd - funcStart) / CLOCKS_PER_SEC;
    int funcMinutes = static_cast<int>(funcSeconds) / 60;

    printf("\nчисло фибоначи = %lld\n", fibonaciCounter);
    printf("Время: %d минуты, %f секунды для функции\n", funcMinutes, funcSeconds);

    return 0;
}

long long int fibonachiFunc(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return unsigned (fibonachiFunc(n - 1) + fibonachiFunc(n - 2));
    }
}
