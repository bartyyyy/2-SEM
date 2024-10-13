#include <iostream>
#include <fstream>
#include <string>


struct Book {
    std::string author;
    std::string title;
    std::string publisher;
    std::string genre;
    std::string origin;
    bool available;
};


const int librarySize = 100;
Book library[librarySize];
int currentLibrarySize = 0;


void inputBook(Book* book) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите автора: ";
    std::getline(std::cin, book->author);
    std::cout << "Введите название: ";
    std::getline(std::cin, book->title);
    std::cout << "Введите жанр: ";
    std::getline(std::cin, book->genre);
    std::cout << "Введите издательство: ";
    std::getline(std::cin, book->publisher);
    std::cout << "Введите происхождение(кража, покупка, подарок): ";
    std::getline(std::cin, book->origin);
    std::cout << "Доступна ли книга?( 1- да, 0 -нет): ";
    std::cin >> book->available;
}

void outputBook(const Book & book) {
      std::cout << "Автор: " << book.author << std::endl;
      std::cout << "Название: " << book.title << std::endl;
      std::cout << "Издательство: " << book.publisher << std::endl;
      std::cout << "Жанр: " << book.genre << std::endl;
      std::cout << "Происхождение: " << book.origin << std::endl;
      std::cout << "Доступна: " << (book.available ? "Да" : "Нет") << std::endl;
}

void deleteBook(int index) {
    if (index < currentLibrarySize) {
        for (int i = index; i < currentLibrarySize - 1; i++) {
            library[i] = library[i + 1];
        }
        currentLibrarySize--;
        std::cout << "Книга успешно удалена." << std::endl;
    }
    else {
        std::cout << "Ошибка: Некорректный индекс книги." << std::endl;
    }
}

void searchBook(const std::string& title) {
    bool found = false;
    for (int i = 0; i < currentLibrarySize; i++) {
        if (library[i].title == title) {
            std::cout << "Книга найдена. Информация о книге:" << std::endl;
            outputBook(library[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Книга с таким названием не найдена." << std::endl;
    }
}

void saveLibraryToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < currentLibrarySize; i++) {
            file << "Автор: " << library[i].author << std::endl
                << "Название: " << library[i].title << std::endl
                << "Жанр: " << library[i].genre << std::endl
                << "Происхождение: " << library[i].origin << std::endl
                << "Доступна: " << library[i].available << std::endl
                << "Издательство: " << library[i].publisher << std::endl
                << "---------------------------------" << std::endl;
        }
        std::cout << "Информация о книгах успешно сохранена в файл." << std::endl;
        file.close();
    }
    else {
        std::cout << "Ошибка: Не удалось открыть файл для записи." << std::endl;
    }
}


int main() {
    char choice;

    while (true) {
        std::cout << "Что вы хотите сделать?\n"
            "1. Добавить книгу\n"
            "2. Удалить книгу\n"
            "3. Найти книгу\n"
            "4. Сохранить информацию о книгах в файл\n"
            "5. Выйти\n";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            inputBook(&library[currentLibrarySize]);
            currentLibrarySize++;
            break;
        }
        case '2': {
            int index;
            std::cout << "Введите индекс книги для удаления: ";
            std::cin >> index;
            deleteBook(index);
            break;
        }
        case '3': {
            std::string title;
            std::cout << "Введите название книги для поиска: ";
            std::cin >> title;
            searchBook(title);
            break;
        }
        case '4': {
            saveLibraryToFile("library_data.txt");
            break;
        }
        case '5': {
            std::cout << "До свидания!\n";
            return 0;
        }
        default: {
            std::cout << "Некорректный выбор.\n";
            break;
        }
        }
    }

    return 0;
}