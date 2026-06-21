#include <iostream>
using namespace std;

int main() 
{
    char str[100];
    int vowels = 0, consonants = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Number of vowels = " << vowels << endl;
    cout << "Number of consonants = " << consonants << endl;

    return 0;
}