#include <iostream>
#include <fstream>
#include <string>

using namespace std;

union AccountType {
    string fixed;
    int preferential;
};

// Structure representing bank client data
typedef struct  {
    string fullName;
    AccountType accountType;
    int accountNumber;
    double accountBalance;
    string lastModifiedDate;
}BankClient;

// Function to input client data from keyboard
void inputClientData(BankClient& client) {
    cout << "Enter client's full name: ";
    getline(cin, client.fullName);

    cout << "Enter Account Type (fixed/preferential): ";
    cin >> client.accountType.fixed; // Example for type "fixed", you can add logic for other types

    cout << "Enter Account Number: ";
    cin >> client.accountNumber;

    cout << "Enter Account Balance: ";
    cin >> client.accountBalance;

    cout << "Enter Last Modified Date: ";
    cin >> client.lastModifiedDate;
}

// Function to write client data to file
void writeClientDataToFile(const BankClient& client) {
    ofstream file("clients.txt", ios::app);
    if (file.is_open()) {
        file << client.fullName << "," << client.accountType.fixed << "," << client.accountNumber << ","
            << client.accountBalance << "," << client.lastModifiedDate << "\n";
        file.close();
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to display client data on screen
void displayClientDataOnScreen(const BankClient& client) {
    cout << "Full Name: " << client.fullName << endl;
    cout << "Account Type: " << client.accountType.fixed << endl;
    cout << "Account Number: " << client.accountNumber << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
    cout << "Last Modified Date: " << client.lastModifiedDate << endl;
}

// Function to read client data from a file
void readClientDataFromFile(int accountNumber) {
    ifstream file("clients.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Example parsing of a line
            // Complete this part for reading data and comparing with account
        }
        file.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }
}

// Example function for finding a client by account number
void findClientByAccountNumber(int accountNumber) {
    // Logic to find a client by account number
}

int main() {
    BankClient client;

    inputClientData(client);
    writeClientDataToFile(client);

    displayClientDataOnScreen(client);

    // Example of finding a client by account number
    int accountNumberToSearch = 123456;
    findClientByAccountNumber(accountNumberToSearch);

    return 0;
}