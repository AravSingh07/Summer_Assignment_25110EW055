#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char str[200];
    char longest[100], word[100];
    int maxLen = 0, j = 0;

    cout << "Enter a sentence: ";
    cin.getline(str, 200);

    for (int i = 0; ; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            word[j++] = str[i];
        } else {
            word[j] = '\0';

            if (j > maxLen) {
                maxLen = j;
                strcpy(longest, word);
            }

            j = 0;

            if (str[i] == '\0')
                break;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length: " << maxLen << endl;

    return 0;
}