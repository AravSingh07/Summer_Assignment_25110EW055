#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    int original = n, reverse = 0;

    while (n > 0)
    {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    return original == reverse;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num))
        cout << num << " is a Palindrome Number";
    else
        cout << num << " is not a Palindrome Number";

    return 0;
}