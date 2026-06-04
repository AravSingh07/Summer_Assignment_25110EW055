#include <iostream>
using namespace std;

int main() 
{
    int num, binary = 0, place = 1, rem;

    cout << "Enter a decimal number: ";
    cin >> num;

    while (num > 0) 
    {
        rem = num % 2;
        binary += rem * place;
        place *= 10;
        num /= 2;
    }

    cout << "Binary = " << binary;

    return 0;
}