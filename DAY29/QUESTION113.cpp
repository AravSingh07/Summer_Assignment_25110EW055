#include <iostream>

using namespace std;

// Function declarations to keep code structured
void showMenu();
void handleCalculation(int choice);

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        // Process user choice
        if (choice >= 1 && choice <= 4) {
            handleCalculation(choice);
        } else if (choice == 5) {
            cout << "\nExiting the calculator. Goodbye!\n";
        } else {
            cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }

        cout << "\n-----------------------------------\n";

    } while (choice != 5); // Loop continues until user chooses to exit

    return 0;
}

// Function to display the interactive menu
void showMenu() {
    cout << "===== MENU DRIVEN CALCULATOR =====\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Exit\n";
    cout << "==================================\n";
}

// Function to handle inputs and perform math operations
void handleCalculation(int choice) {
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case 1:
            cout << "\nResult: " << num1 << " + " << num2 << " = " << (num1 + num2) << "\n";
            break;
        case 2:
            cout << "\nResult: " << num1 << " - " << num2 << " = " << (num1 - num2) << "\n";
            break;
        case 3:
            cout << "\nResult: " << num1 << " * " << num2 << " = " << (num1 * num2) << "\n";
            break;
        case 4:
            // Runtime check to prevent undefined behavior / crashes
            if (num2 != 0) {
                cout << "\nResult: " << num1 << " / " << num2 << " = " << (num1 / num2) << "\n";
            } else {
                cout << "\nError: Division by zero is not allowed!\n";
            }
            break;
        default:
            cout << "\nAn unexpected error occurred.\n";
    }
}
