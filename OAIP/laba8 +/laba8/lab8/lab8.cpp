#include <iostream>
using namespace std;

class Queue {
private:
    char* arr; // массив для хранения элементов очереди
    int capacity; // максимальная вместимость очереди
    int front; // индекс первого элемента в очереди
    int rear; // индекс последнего элемента в очереди
    int size; // текущий размер очереди

public:
    // Конструктор для инициализации очереди с заданной вместимостью
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new char[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Деструктор для освобождения памяти
    ~Queue() {
        delete[] arr;
    }

    // Проверка на пустоту очереди
    bool isEmpty() {
        return size == 0;
    }

    // Проверка на полноту очереди
    bool isFull() {
        return size == capacity;
    }

    // Добавление элемента в очередь
    void enqueue(char item) {
        if (isFull()) {
            cout << "Очередь переполнена." << endl;
            return;
        }

        // Проверяем на совпадение первого и последнего элементов
        if (!isEmpty() && item == arr[rear]) {
            cout << "Совпадение первого и последнего элементов, удаляем оба." << endl;
            dequeue(); // Удаляем последний элемент
            return;
        }

        // Проверяем на совпадение первого и нового элементов
        if (!isEmpty() && item == arr[front]) {
            cout << "Совпадение первого и нового элементов, удаляем оба." << endl;
            dequeue(); // Удаляем первый элемент
            front = (front + 1) % capacity; // Смещаем указатель на первый элемент
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    // Удаление элемента из очереди
    void dequeue() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return;
        }

        // Удаляем первый элемент
        front = (front + 1) % capacity;
        size--;
    }


    // Получение размера очереди
    int getSize() {
        return size;
    }

    // Вывод элементов очереди
 void display() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return;
        }

        int count = size;
        int i = front;
        while (count > 0) {
            if (arr[i] != '\0') { // Исключаем удаленные элементы
                cout << arr[i] << " ";
            }
            i = (i + 1) % capacity;
            count--;
        }
        cout << endl;
    }


    // Последний элемент в очереди
    char lastElement() {
        if (isEmpty()) {
            cout << "Очередь пуста." << endl;
            return '\0';
        }
        return arr[rear];
    }
};

int main() {
    int capacity;
    cout << "Введите максимальный размер очереди: ";
    cin >> capacity;

    Queue queue(capacity);

    char choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент в очередь\n";
        cout << "2. Удалить элемент из очереди\n";
        cout << "3. Вывести размер очереди\n";
        cout << "4. Вывести элементы очереди\n";
        cout << "5. Выйти из программы\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            char item;
            cout << "Введите символ для добавления в очередь: ";
            cin >> item;
            if (queue.getSize() > 0 && item == queue.lastElement()) {
                queue.dequeue();
            }
            queue.enqueue(item);
            break;
        }
        case '2':
            queue.dequeue();
            break;
        case '3':
            cout << "Размер очереди: " << queue.getSize() << endl;
            break;
        case '4':
            cout << "Элементы очереди: ";
            queue.display();
            break;
        case '5':
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный ввод. Попробуйте снова." << endl;
        }
    } while (choice != '5');

    return 0;
}
