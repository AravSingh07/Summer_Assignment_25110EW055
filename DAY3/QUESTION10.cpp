#include <iostream>
using namespace std;

int main() {
    int start, end;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    for (int num = start; num <= end; num++) {
        bool prime = true;

        if (num <= 1)
            prime = false;
        else {
            for (int i = 2; i < num; i++) {
                if (num % i == 0) {
                    prime = false;
                    break;
                }
            }
        }

        if (prime)
            cout << num << " ";
    }

    return 0;
}