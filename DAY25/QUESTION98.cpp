#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;

    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    cout << "Common characters: ";

    for (int i = 0; i < str1.length(); i++) {
        bool found = false;

        for (int j = 0; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            bool printed = false;

            for (int k = 0; k < i; k++) {
                if (str1[k] == str1[i]) {
                    printed = true;
                    break;
                }
            }

            if (!printed)
                cout << str1[i] << " ";
        }
    }

    return 0;
}