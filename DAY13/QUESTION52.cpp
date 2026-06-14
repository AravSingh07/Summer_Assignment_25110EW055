#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    int evenCount = 0, oddCount = 0;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "Number of Even Elements = " << evenCount << endl;
    cout << "Number of Odd Elements = " << oddCount << endl;

    return 0;
}