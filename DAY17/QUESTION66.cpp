#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    int arr1[n1];

    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    int arr2[n2];

    cout << "Enter elements of second array:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    cout << "Union of arrays: ";

    for (int i = 0; i < n1; i++)
    {
        bool duplicate = false;

        for (int j = 0; j < i; j++)
        {
            if (arr1[i] == arr1[j])
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
            cout << arr1[i] << " ";
    }

    for (int i = 0; i < n2; i++)
    {
        bool found = false;

        for (int j = 0; j < n1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
            cout << arr2[i] << " ";
    }

    return 0;
}