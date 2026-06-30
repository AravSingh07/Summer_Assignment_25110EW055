#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor to initialize an account
    BankAccount(int accNum, std::string name, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialDeposit;
    }

    // Getter functions
    int getAccountNumber() const { return accountNumber; }
    std::string getHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // Service methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "\n[Success] Deposit of $" << amount << " processed successfully.";
        } else {
            std::cout << "\n[Error] Invalid deposit amount requested.";
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\n[Error] Invalid withdrawal amount requested.";
            return false;
        }
        if (amount > balance) {
            std::cout << "\n[Error] Insufficient funds available.";
            return false;
        }
        balance -= amount;
        std::cout << "\n[Success] Withdrawal of $" << amount << " processed successfully.";
        return true;
    }

    void displayDetails() const {
        std::cout << "\n-----------------------------------";
        std::cout << "\n Account Number : " << accountNumber;
        std::cout << "\n Account Holder : " << accountHolderName;
        std::cout << "\n Current Balance: $" << std::fixed << std::setprecision(2) << balance;
        std::cout << "\n-----------------------------------";
    }
};

class BankSystem {
private:
    std::vector<BankAccount> accounts;
    int nextAccountNumber = 1001; // Auto-incrementing account numbers

    BankAccount* findAccount(int accNum) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    void createAccount() {
        std::string name;
        double initialDeposit;

        std::cout << "\nEnter Account Holder Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter Initial Deposit Amount: $";
        std::cin >> initialDeposit;

        if (initialDeposit < 0) {
            std::cout << "\n[Error] Account creation failed. Minimum deposit cannot be negative.\n";
            return;
        }

        BankAccount newAccount(nextAccountNumber, name, initialDeposit);
        accounts.push_back(newAccount);

        std::cout << "\n[Success] Account Created Successfully!";
        std::cout << "\nYour Assigned Account Number is: " << nextAccountNumber << "\n";
        nextAccountNumber++;
    }

    void performDeposit() {
        int accNum;
        double amount;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        BankAccount* acc = findAccount(accNum);
        if (acc != nullptr) {
            std::cout << "Enter Amount to Deposit: $";
            std::cin >> amount;
            acc->deposit(amount);
            std::cout << "\nNew Balance: $" << acc->getBalance() << "\n";
        } else {
            std::cout << "\n[Error] Account not found.\n";
        }
    }

    void performWithdrawal() {
        int accNum;
        double amount;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        BankAccount* acc = findAccount(accNum);
        if (acc != nullptr) {
            std::cout << "Enter Amount to Withdraw: $";
            std::cin >> amount;
            if (acc->withdraw(amount)) {
                std::cout << "\nRemaining Balance: $" << acc->getBalance() << "\n";
            }
        } else {
            std::cout << "\n[Error] Account not found.\n";
        }
    }

    void checkBalance() {
        int accNum;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        BankAccount* acc = findAccount(accNum);
        if (acc != nullptr) {
            acc->displayDetails();
        } else {
            std::cout << "\n[Error] Account not found.\n";
        }
    }

    void listAllAccounts() {
        if (accounts.empty()) {
            std::cout << "\nNo active bank accounts found in the system.\n";
            return;
        }
        std::cout << "\n=============================================";
        std::cout << "\n         ALL REGISTERED ACCOUNTS             ";
        std::cout << "\n=============================================";
        for (const auto &acc : accounts) {
            acc.displayDetails();
        }
    }
};

int main() {
    BankSystem bank;
    int choice;

    do {
        std::cout << "\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====";
        std::cout << "\n1. Open New Account";
        std::cout << "\n2. Deposit Funds";
        std::cout << "\n3. Withdraw Funds";
        std::cout << "\n4. Check Balance Inquiry";
        std::cout << "\n5. Display All Registered Accounts";
        std::cout << "\n6. Exit Application";
        std::cout << "\n==========================================";
        std::cout << "\nEnter option choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.performDeposit();
                break;
            case 3:
                bank.performWithdrawal();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                bank.listAllAccounts();
                break;
            case 6:
                std::cout << "\nThank you for choosing our banking system. Goodbye!\n";
                break;
            default:
                std::cout << "\n[Error] Invalid Selection! Choose a valid option (1-6).\n";
        }
    } while (choice != 6);

    return 0;
}
