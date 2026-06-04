#include <iostream>
using namespace std;

int main() {
    int num, largestFactor = 0;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 2; i <= num; i++) 
    {
        if (num % i == 0) 
        {
            bool isPrime = true;

            for (int j = 2; j < i; j++) 
            {
                if (i % j == 0) 
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) 
            {
                largestFactor = i;
            }
        }
    }

    cout << "Largest Prime Factor = " << largestFactor;

    return 0;
}