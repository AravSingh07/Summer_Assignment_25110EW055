#include <iostream>
using namespace std;

int main() 
{
    char str1[100], str2[100];
    int count1[256] = {0}, count2[256] = {0};

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    for (int i = 0; str1[i] != '\0'; i++) {
        count1[(int)str1[i]]++;
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        count2[(int)str2[i]]++;
    }

    bool anagram = true;

    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            anagram = false;
            break;
        }
    }

    if (anagram)
        cout << "The strings are anagrams.";
    else
        cout << "The strings are not anagrams.";

    return 0;
}