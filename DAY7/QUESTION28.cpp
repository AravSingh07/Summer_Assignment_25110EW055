#include <iostream>
using namespace std;

int reverseNum(int n, int rev = 0)
{
    if (n == 0)
        return rev;

    return reverseNum(n / 10, rev * 10 + n % 10);
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Reversed number = " << reverseNum(num) << endl;

    return 0;
}