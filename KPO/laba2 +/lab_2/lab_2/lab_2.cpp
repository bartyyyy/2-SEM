
#include <iostream>
#include <limits>
#include <cmath>

void myFunction(int x) 
{
    std::cout << "Вызвана функция с аргументом: " << x << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 11;
    int X = 9 + n;
    int Y = 10 + n;
    int Z = 11 + n;
    short int shrt1 = X;
    short int shrt2 = -X;
    short int sh1 = 0x7fff;
    short int sh2 = 0x8000;
    unsigned short int usx1 = 0xffff;
    unsigned short int usx2 = 0x0000;
    int iy1 = Y;
    int iy2 = -Y;
    int sxiy1 = 0x7FFFFFFF;
    int sxiy2 = 0x80000000;
    unsigned int hexuiy1 = 0xFFFFFFFF;
    unsigned int hexuiy2 = 0x00000000;
    long int z1 = Z;
    long int z2 = -Z;
    long long int lgz1 = 0x7fffffffffffffffll;
    long long int lgz2 = 0x8000000000000000ll; 
    unsigned long long int lguz1 = 0xffffffffffffffffll;
    unsigned long long int lguz2 = 0x0000000000000000ll;
    float S = 1.0 + (float)n;
    bool bl1 = false, bl2 = true;
    char symb1 = 'r';
    char symb2 = 'р';
    wchar_t wchr1 = 'd';
    wchar_t wchr2 = 'д';
    int size = sizeof(long int);
    float s1 = S;
    float s2 = -S;


    double double_var = 101112.0;

    char* char_ptr = &symb1;
    wchar_t* wchar_ptr = &wchr1;
    short* short_ptr = &shrt1;
    int* int_ptr = &sxiy1;
    float* float_ptr = &S;
    double* double_ptr = &double_var;

 
    char_ptr += 3;
    wchar_ptr += 3;
    short_ptr += 3;
    int_ptr += 3;
    float_ptr += 3;
    double_ptr += 3;

 
    void (*funcPtr)(int) = myFunction;


    funcPtr(42);
}

