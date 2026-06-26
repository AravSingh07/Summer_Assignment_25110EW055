#include <iostream>
using namespace std;

int main()
{
    int choice;
    int pin = 1234, enteredPin;
    double balance = 10000, amount;

    cout << "===== ATM Simulation =====" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (enteredPin != pin)
    {
        cout << "Incorrect PIN! Access Denied." << endl;
        return 0;
    }

    do
    {
        cout << "\n===== ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Current Balance: Rs. " << balance << endl;
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Deposit Successful!" << endl;
                cout << "Updated Balance: Rs. " << balance << endl;
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                if (amount <= balance)
                {
                    balance -= amount;
                    cout << "Withdrawal Successful!" << endl;
                    cout << "Remaining Balance: Rs. " << balance << endl;
                }
                else
                {
                    cout << "Insufficient Balance!" << endl;
                }
                break;

            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}