#include <iostream>
#include <string>
#define MAX_CUSTOMERS 100

struct Customer {
    int account_number;
    std::string name;
    float balance;
};

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

void createAccount()
{
    if (customerCount >= MAX_CUSTOMERS) {
        std::cout << "Maximum number of customers reached." << std::endl;
        return;
    }
    Customer newCustomer;
    std::cout << "Enter account number: ";
    std::cin >> newCustomer.account_number;
    int i;
    for (i = 0; i < customerCount; i++) {
        if (customers[i].account_number == newCustomer.account_number) {
            std::cout << "Account number already exists. Try again." << std::endl;
            return;
        }
    }
    std::cout << "Enter name: ";
    std::cin >> newCustomer.name;
    std::cout << "Enter initial balance: ";
    std::cin >> newCustomer.balance;
    customers[customerCount++] = newCustomer;
    std::cout << "Account created successfully." << std::endl;
}

void displayBalance(int account_number) {
    int i;
    for (i = 0; i < customerCount; i++) {
        if (customers[i].account_number == account_number) {
            std::cout << "Account Number: " << customers[i].account_number << std::endl;
            std::cout << "Name: " << customers[i].name << std::endl;
            std::cout << "Balance: $" << customers[i].balance << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void deposit(int account_number, float amount) {
    int i;
    for (i = 0; i < customerCount; i++) {
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            std::cout << "Deposit successful. New balance: $" << customers[i].balance << std::endl;
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

void withdraw(int account_number, float amount) {
    int i;
    for (i = 0; i < customerCount; i++) {
        if (customers[i].account_number == account_number) {
            if (amount > customers[i].balance) {
                std::cout << "Insufficient funds." << std::endl;
            } else {
                customers[i].balance -= amount;
                std::cout << "Withdrawal successful. New balance: $" << customers[i].balance << std::endl;
            }
            return;
        }
    }
    std::cout << "Account not found." << std::endl;
}

int main() {
    int choice, account_number;
    float amount;
    do {
        std::cout << std::endl;
        std::cout << "**************************" << std::endl;
        std::cout << "Bank Management System" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Display Balance" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Withdraw" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "**************************" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                displayBalance(account_number);
                break;
            case 3:
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                deposit(account_number, amount);
                break;
            case 4:
                std::cout << "Enter account number: ";
                std::cin >> account_number;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                withdraw(account_number, amount);
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice !=0);
    return 0;
}



