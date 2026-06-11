#include <iostream>
using namespace std;

int main() 
{
    int rows = 5;

    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= rows - i; j++) 
        {
            cout << " ";
        }
        for (char ch = 'A'; ch < 'A' + i; ch++) 
        {
            cout << ch;
        }
        for (char ch = 'A' + i - 2; ch >= 'A'; ch--) 
        {
            cout << ch;
        }

        cout << endl;
    }
    return 0;
}