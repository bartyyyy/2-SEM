#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция универсального хеширования
unsigned int universalHash(const string& key, unsigned int prime, unsigned int tableSize) {
    unsigned int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * prime) + ch;
    }
    return hashValue % tableSize;
}

// Функция модульного хеширования
unsigned int modHash(const string& key, unsigned int tableSize) {
    unsigned int hashValue = 0;
    for (char ch : key) {
        hashValue = (hashValue * 31 + ch) % tableSize;
    }
    return hashValue;
}

class HashTable {
private:
    struct HashNode {
        string key;
        int value;
        bool deleted;

        HashNode() : key(""), value(0), deleted(false) {}
    };

    vector<HashNode> table;
    unsigned int size;
    unsigned int prime;

public:
    HashTable(unsigned int initialSize, unsigned int prime) : size(initialSize), prime(prime) {
        table.resize(size);
    }

    void insert(const string& key, int value) {
        unsigned int index = universalHash(key, prime, size);
        unsigned int originalIndex = index;

        while (!table[index].key.empty() && table[index].key != key && !table[index].deleted) {
            index = (index + 1) % size;
            if (index == originalIndex) {
                // Таблица заполнена, невозможно вставить
                cerr << "Error: Table is full!" << endl;
                return;
            }
        }

        table[index].key = key;
        table[index].value = value;
        table[index].deleted = false;
    }

    int search(const string& key) {
        unsigned int index = universalHash(key, prime, size);
        unsigned int originalIndex = index;

        while (!table[index].key.empty()) {
            if (table[index].key == key && !table[index].deleted) {
                return table[index].value;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                // Элемент не найден
                return -1;
            }
        }

        // Элемент не найден
        return -1;
    }

    void remove(const string& key) {
        unsigned int index = universalHash(key, prime, size);
        unsigned int originalIndex = index;

        while (!table[index].key.empty()) {
            if (table[index].key == key && !table[index].deleted) {
                table[index].deleted = true;
                return;
            }
            index = (index + 1) % size;
            if (index == originalIndex) {
                // Элемент не найден
                return;
            }
        }
    }

    void print() {
        for (unsigned int i = 0; i < size; ++i) {
            if (!table[i].key.empty() && !table[i].deleted) {
                cout << "Key: " << table[i].key << ", Value: " << table[i].value << endl;
            }
        }
    }

    // Функция подсчета коллизий
    unsigned int countCollisions() {
        unsigned int collisions = 0;
        for (unsigned int i = 0; i < size; ++i) {
            if (!table[i].key.empty() && !table[i].deleted) {
                unsigned int index = universalHash(table[i].key, prime, size);
                if (index != i)
                    collisions++;
            }
        }
        return collisions;
    }
};

int main() {
    srand(time(NULL));

    const unsigned int tableSizes[] = { 16, 32, 64, 128 };
    const unsigned int prime = 31;
    const unsigned int numKeys = 10000;

    for (unsigned int size : tableSizes) {
        HashTable hashTable(size, prime);
        cout << "Table Size: " << size << endl;

        // Вставка элементов с одинаковыми ключами для сравнения коллизий
        for (unsigned int i = 0; i < numKeys; ++i) {
            string key = "Key";
            int value = rand() % 1000; // Произвольное значение
            hashTable.insert(key, value);
        }

        // Измерение времени поиска
        clock_t startTime = clock();
        for (unsigned int i = 0; i < numKeys; ++i) {
            string key = "Key";
            hashTable.search(key);
        }
        clock_t endTime = clock();
        double searchTime = double(endTime - startTime) / CLOCKS_PER_SEC;
        cout << "Search Time: " << searchTime << " seconds" << endl;

        // Вывод количества коллизий
        cout << "Collisions: " << hashTable.countCollisions() << endl;

        cout << endl;
    }

    return 0;
}
