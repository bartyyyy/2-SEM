#include <iostream>
#include <fstream>

template<typename T>
struct StackNode {
    T data;
    StackNode* next;

    StackNode(T value) : data(value), next(nullptr) {}
};

template<typename T>
struct Stack {
    StackNode<T>* top;

    Stack() : top(nullptr) {}
    ~Stack();

    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    void clear();
    void saveToFile(const std::string& filename);
    void readFromFile(const std::string& filename);
    bool hasNextEqual();
};

template<typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::push(T value) {
    StackNode<T>* newNode = new StackNode<T>(value);
    newNode->next = top;
    top = newNode;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        std::cerr << "Ошибка: Стек пуст\n";
        exit(EXIT_FAILURE);
    }
    T data = top->data;
    StackNode<T>* temp = top;
    top = top->next;
    delete temp;
    return data;
}

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        std::cerr << "Ошибка: Стек пуст\n";
        exit(EXIT_FAILURE);
    }
    return top->data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template<typename T>
void Stack<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template<typename T>
void Stack<T>::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << "\n";
        exit(EXIT_FAILURE);
    }

    StackNode<T>* current = top;
    while (current != nullptr) {
        file << current->data << "\n";
        current = current->next;
    }

    file.close();
}

template<typename T>
void Stack<T>::readFromFile(const std::string& filename) {
    clear(); // Очистить стек перед чтением из файла

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << "\n";
        exit(EXIT_FAILURE);
    }

    T value;
    while (file >> value) {
        push(value);
    }

    file.close();
}

template<typename T>
bool Stack<T>::hasNextEqual() {
    if (isEmpty()) {
        std::cerr << "Ошибка: Стек пуст\n";
        exit(EXIT_FAILURE);
    }

    StackNode<T>* current = top;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Stack<int> stack;
    int choice;
    int value;

    do {
        std::cout << "\nМеню стека\n";
        std::cout << "1. Добавить\n";
        std::cout << "2. Удалить\n";
        std::cout << "3. Верхний\n";
        std::cout << "4. Проверить равный следующий\n";
        std::cout << "5. Сохранить в файл\n";
        std::cout << "6. Считать из файла\n";
        std::cout << "7. Очистить стек\n";
        std::cout << "8. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение для добавления: ";
            std::cin >> value;
            stack.push(value);
            break;
        case 2:
            if (!stack.isEmpty())
                std::cout << "Удаленное значение: " << stack.pop() << std::endl;
            else
                std::cout << "Стек пуст\n";
            break;
        case 3:
            if (!stack.isEmpty())
                std::cout << "Верхний элемент: " << stack.peek() << std::endl;
            else
                std::cout << "Стек пуст\n";
            break;
        case 4:
            if (stack.hasNextEqual())
                std::cout << "Следующий элемент равен предыдущему\n";
            else
                std::cout << "Следующий элемент не равен предыдущему\n";
            break;
        case 5:
            stack.saveToFile("данныеСтека.txt");
            std::cout << "Данные стека сохранены в файл\n";
            break;
        case 6:
            stack.readFromFile("данныеСтека.txt");
            std::cout << "Данные стека считаны из файла\n";
            break;
        case 7:
            stack.clear();
            std::cout << "Стек очищен\n";
            break;
        case 8:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор\n";
            break;
        }
    } while (choice != 8);

    return 0;
}
