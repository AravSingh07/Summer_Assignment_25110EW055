#include <iostream>
using namespace std;

int main() 
{
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        int count = 1;

        if (str[i] == ' ')
            continue;

        for (int j = i + 1; str[j] != '\0'; j++) {
            if (str[i] == str[j]) {
                count++;
                str[j] = '0';
            }
        }

        if (str[i] != '0')
            cout << str[i] << " = " << count << endl;
    }

    return 0;
}