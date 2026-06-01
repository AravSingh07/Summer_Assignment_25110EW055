#include <iostream>
using namespace std;

int main() {
    int a, b, maxNum;

    cin >> a >> b;

    maxNum = (a > b) ? a : b;

    while (true) {
        if (maxNum % a == 0 && maxNum % b == 0) {
            cout << "LCM = " << maxNum;
            break;
        }
        maxNum++;
    }

    return 0;
}