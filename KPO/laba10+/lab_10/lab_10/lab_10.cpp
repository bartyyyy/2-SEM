#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int target1 = 3;
    int num_items1 = std::count(v.begin(), v.end(), target1);
    std::cout << "Число: " << target1 << " количество " << num_items1 << "\n";

    int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
    std::cout << "количество элементов, кратных 3: " << num_items3 << "\n";
    std::cout << "Лямбда, захват переменных ";

    for (auto i : v) [i]() {if (i % 3 == 0) std::cout << i << " "; }();

    std::cout << "\nЛямбда с параметрами ";
    for (auto i : v) [](auto i) {if (i % 3 == 0) std::cout << i << " "; }(i);

    std::cout << "\nЛямбда без параметрами ";
    for (auto i : v) [i] {if (i % 3 == 0) std::cout << i << " "; }();
}