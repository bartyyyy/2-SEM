#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file1("FILE1.txt");
    std::ofstream file2("FILE2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Ошибка открытия файлов.\n";
        return 1;
    }

    std::string line;
    int size_file1 = 0;
    int size_file2 = 0;
    bool is_even_line = false;

    while (std::getline(file1, line)) {
        size_file1 += line.size() + 1; 

        if (is_even_line) {
            file2 << line << "\n";
            size_file2 += line.size() + 1; 
        }

        is_even_line = !is_even_line;
    }

    file1.close();
    file2.close();

    std::cout << "Размер FILE1.txt: " << size_file1 << " байт\n";
    std::cout << "Размер FILE2.txt: " << size_file2 << " байт\n";

    return 0;
}