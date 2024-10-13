#include <iostream>
#include <string>
#include <unordered_map>

bool validateString(const std::string& input, const std::unordered_map<char, char>& validationTable) {
    for (char ch : input) {
        auto it = validationTable.find(ch);
        if (it == validationTable.end()) {
            std::cout << "Invalid character: " << ch << std::endl;
            return false;
        }
    }
    return true;
}

int main() {
    // Таблица проверки
    std::unordered_map<char, char> validationTable = {
        {'a', '1'},
        {'b', '2'},
        {'c', '3'}
    };

    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (validateString(input, validationTable)) {
        std::cout << "The string is valid." << std::endl;
    }
    else {
        std::cout << "The string contains invalid characters." << std::endl;
    }

    return 0;
}
