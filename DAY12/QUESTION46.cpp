#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int n)
{
    int original = n, sum = 0, digits = 0, temp = n;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}
int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
        cout << num << " is an Armstrong Number";
    else
        cout << num << " is not an Armstrong Number";

    return 0;
}