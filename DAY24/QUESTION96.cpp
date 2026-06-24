#include <iostream>
using namespace std;

int main() 
{
    char str[100];
    bool visited[256] = {false};

    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "String after removing duplicates: ";

    for (int i = 0; str[i] != '\0'; i++) {
        if (!visited[(int)str[i]]) {
            cout << str[i];
            visited[(int)str[i]] = true;
        }
    }

    return 0;
}