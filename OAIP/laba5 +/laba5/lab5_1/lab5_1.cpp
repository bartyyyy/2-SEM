#include <iostream>
#include <string>

enum AccountType {
    ACCOUNT_TYPE_STANDARD,
    ACCOUNT_TYPE_PREMIUM,
    ACCOUNT_TYPE_SAVINGS
};

struct BankClient {
    std::string fullName;
    AccountType accountType;
    int accountNumber;
    double accountBalance;
    unsigned int lastChangeDate;
};

void displayMenu() {
    std::cout << "Система управления клиентами банка" << std::endl;
    std::cout << "1. Добавить нового клиента" << std::endl;
    std::cout << "2. Показать всех клиентов" << std::endl;
    std::cout << "3. Найти клиента по номеру счета" << std::endl;
    std::cout << "4. Удалить клиента по номеру счета" << std::endl;
    std::cout << "5. Выход" << std::endl;
};



void addNewClient(BankClient& client) {
    std::cout << "Введите полное имя: ";
    std::cin.ignore();
    std::getline(std::cin, client.fullName);

    int accountType;
    std::cout << "Введите тип счета (0 = Стандарт, 1 = Премиум, 2 = Сберегательный): ";
    std::cin >> accountType;
    client.accountType = static_cast<AccountType>(accountType);

    std::cout << "Введите номер счета: ";
    std::cin.ignore();
    std::cin >> client.accountNumber;

    std::cout << "Введите баланс счета: ";
    std::cin.ignore();
    std::cin >> client.accountBalance;

    std::cout << "Введите дату последнего изменения (ГГГГММДД): ";
    std::cin >> client.lastChangeDate;
};
void displayClient(const BankClient& client) {
    std::cout << "Полное имя: " << client.fullName << std::endl;
    std::cout << "Тип счета: " << client.accountType << std::endl;
    std::cout << "Номер счета: " << client.accountNumber << std::endl;
    std::cout << "Баланс счета: " << client.accountBalance << std::endl;
    std::cout << "Дата последнего изменения: " << client.lastChangeDate << std::endl;
    std::cout << std::endl;
}

void searchClientByAccountNumber(const BankClient& client, int accountNumber) {
    if (client.accountNumber == accountNumber) {
        displayClient(client);
    }
    else {
        std::cout << "Клиент не найден." << std::endl;
    }
}

void deleteClientByAccountNumber(BankClient& client, int accountNumber) {
    if (client.accountNumber == accountNumber) {
        client = {}; 
        std::cout << "Клиент успешно удален." << std::endl;
    }
    else {
        std::cout << "Клиент не найден." << std::endl;
    }
}

int main() {
    const int MAX_CLIENTS = 10;
    BankClient clients[MAX_CLIENTS];
    int numClients = 0;

    int choice;
    do {
        displayMenu();
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (numClients < MAX_CLIENTS) {
                addNewClient(clients[numClients]);
                numClients++;
            }
            else {
                std::cout << "Достигнуто максимальное количество клиентов." << std::endl;
            }
            break;
        case 2:
            std::cout << "Все клиенты:" << std::endl;
            for (int i = 0; i < numClients; i++) {
                displayClient(clients[i]);
            }
            break;
        case 3:
            int searchAccountNumber;
            std::cout << "Введите номер счета для поиска: ";
            std::cin >> searchAccountNumber;
            for (int i = 0; i < numClients; i++) {
                searchClientByAccountNumber(clients[i], searchAccountNumber);
            }
            break;
        case 4:
            int deleteAccountNumber;
            std::cout << "Введите номер счета для удаления: ";
            std::cin >> deleteAccountNumber;
            for (int i = 0; i < numClients; i++) {
                deleteClientByAccountNumber(clients[i], deleteAccountNumber);
            }
            break;
        case 5:
            std::cout << "Завершение программы. До свидания!";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
        }
    } while (choice != 5);

    return 0;
}