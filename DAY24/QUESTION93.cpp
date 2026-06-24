#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char str1[100], str2[100], temp[200];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    if (strlen(str1) != strlen(str2)) {
        cout << "Strings are not rotations.";
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2))
        cout << "Strings are rotations of each other.";
    else
        cout << "Strings are not rotations.";

    return 0;
}