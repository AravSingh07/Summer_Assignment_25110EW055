#include <iostream>
using namespace std;

int main() 
{
    int n, a = 0, b = 1, next;

    cout << "Enter n: ";
    cin >> n;

    if (n == 1)
        cout << "Nth Fibonacci term = " << a;
    else if (n == 2)
        cout << "Nth Fibonacci term = " << b;
    else {
        for (int i = 3; i <= n; i++) 
        {
            next = a + b;
            a = b;
            b = next;
        }
        cout << "Nth Fibonacci term = " << b;
    }

    return 0;
}