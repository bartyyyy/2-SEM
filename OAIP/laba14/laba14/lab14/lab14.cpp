#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <random>

// Универсальная хеш-функция
class UniversalHash {
private:
    std::vector<unsigned int> a, b;
    unsigned int p, m;

public:
    UniversalHash(unsigned int size) : p(10000019), m(size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<unsigned int> dis(1, p - 1);
        for (unsigned int i = 0; i < 2; ++i) {
            a.push_back(dis(gen));
            b.push_back(dis(gen));
        }
    }

    unsigned int hash(unsigned int key) const {
        return ((a[0] * key + b[0]) % p) % m;
    }
};

// Структура для элемента в таблице
struct Book {
    unsigned int bookNumber;
    std::string title;

    Book(unsigned int number, const std::string& t) : bookNumber(number), title(t) {}
};

// Хеш-таблица с цепочками разного размера
class HashTable {
private:
    unsigned int size;
    std::vector<std::list<Book>> table;
    UniversalHash hashFunction;

public:
    HashTable(unsigned int tableSize) : size(tableSize), table(tableSize), hashFunction(tableSize) {}

    void insert(unsigned int key, const std::string& title) {
        unsigned int index = hashFunction.hash(key);
        table[index].push_back(Book(key, title));
    }

    bool search(unsigned int key, Book& result) const {
        unsigned int index = hashFunction.hash(key);
        for (const auto& book : table[index]) {
            if (book.bookNumber == key) {
                result = book;
                return true;
            }
        }
        return false;
    }

    bool remove(unsigned int key) {
        unsigned int index = hashFunction.hash(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->bookNumber == key) {
                chain.erase(it);
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Создаем хеш-таблицу размером 100
    HashTable library(100);

    // Добавляем несколько книг
    library.insert(12345, "Война и мир");
    library.insert(54321, "Преступление и наказание");
    library.insert(98765, "Мастер и Маргарита");

    // Поиск книги
    Book result(0, "");
    if (library.search(54321, result)) {
        std::cout << "Найдена книга: " << result.title << std::endl;
    }
    else {
        std::cout << "Книга не найдена." << std::endl;
    }

    // Удаление книги
    if (library.remove(12345)) {
        std::cout << "Книга удалена." << std::endl;
    }
    else {
        std::cout << "Книга не найдена для удаления." << std::endl;
    }

    return 0;
}
