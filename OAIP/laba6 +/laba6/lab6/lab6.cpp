#include <iostream>
#include <fstream>
#include <cctype>

struct Node {
    char data;
    Node* next;

    Node(char c) : data(c), next(nullptr) {}
};

struct LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addElement(char c) {
        Node* newNode = new Node(c);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayList() {
        Node* temp = head;
        while (temp) {
            if (std::isdigit(temp->data) || (temp->data >= 'A' && temp->data <= 'Z') || (temp->data >= 'a' && temp->data <= 'z')) {
                std::cout << temp->data << " ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void saveListToFile(const std::string& filename) {
        std::ofstream file(filename);
        Node* temp = head;
        while (temp) {
            if (std::isdigit(temp->data) || (temp->data >= 'A' && temp->data <= 'Z') || (temp->data >= 'a' && temp->data <= 'z')) {
                file << temp->data << " ";
            }
            temp = temp->next;
        }
        file.close();
    }

    void readListFromFile(const std::string& filename) {
        std::ifstream file(filename);
        char c;
        while (file >> c) {
            addElement(c);
        }
        file.close();
    }

    void findAndDisplayElement(char searchChar) {
        Node* temp = head;
        while (temp) {
            if (temp->data == searchChar) {
                std::cout << "Found element: " << temp->data << " ";
                if (temp->next) {
                    std::cout << temp->next->data;
                }
                std::cout << std::endl;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Element not found." << std::endl;
    }

    void deleteElement(char c) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            if (curr->data == c) {
                if (prev) {
                    prev->next = curr->next;
                    delete curr;
                    return;
                }
                else {
                    head = curr->next;
                    delete curr;
                    return;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        std::cout << "Element not found for deletion." << std::endl;
    }
};

int main() {
    LinkedList list;

    char choice;
    char inputChar;
    char searchChar;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add element\n";
        std::cout << "2. Delete element\n";
        std::cout << "3. Search and display element\n";
        std::cout << "4. Display list\n";
        std::cout << "5. Save list to file\n";
        std::cout << "6. Read list from file\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "Enter a character to add to the list: ";
            std::cin >> inputChar;
            list.addElement(inputChar);
            break;
        case '2':
            std::cout << "Enter a character to delete from the list: ";
            std::cin >> inputChar;
            list.deleteElement(inputChar);
            break;
        case '3':
            std::cout << "Enter a character to search in the list: ";
            std::cin >> searchChar;
            list.findAndDisplayElement(searchChar);
            break;
        case '4':
            std::cout << "List: ";
            list.displayList();
            break;
        case '5':
            list.saveListToFile("list.txt");
            std::cout << "List saved to file.\n";
            break;
        case '6':
            list.readListFromFile("list.txt");
            std::cout << "List loaded from file.\n";
            break;
        case '7':
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '7');

    return 0;
}