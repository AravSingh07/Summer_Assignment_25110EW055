#include <iostream>
using namespace std;

int main() {
    int num, reverse = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        int digit = num % 10;      // Get last digit
        reverse = reverse * 10 + digit;
        num = num / 10;            // Remove last digit
    }

    cout << "Reversed number = " << reverse << endl;

    return 0;
}