#include <iostream>
using namespace std;

int main() 
{
    int num, count = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num > 0) 
    {
        if (num % 2 == 1)
            count++;

        num /= 2;
    }

    cout << "Number of set bits = " << count;

    return 0;
}