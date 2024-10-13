#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void writeToFile(const std::string& input) {
    std::ofstream file("input.txt");
    if (file.is_open()) {
        file << input;
        file.close();
    }
    else {
        std::cout << "Невозможно открыть файл для записи." << std::endl;
    }
}

void readAndPrintOddNumbers() {
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                if (word.find_first_not_of("0123456789") == std::string::npos) {
                    int num = std::stoi(word);
                    if (num % 2 != 0) {
                        std::cout << num << " ";
                    }
                }
            }
        }
        std::cout << std::endl;
        file.close();
    }
    else {
        std::cout << "Невозможно открыть файл для чтения." << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Введите строку чисел и слов, разделенных пробелами: ";
    std::getline(std::cin, input);

    writeToFile(input);
    readAndPrintOddNumbers();

    return 0;
}