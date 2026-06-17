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

    cout << "Common elements are: ";

    for (int i = 0; i < n1; i++)
    {
        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (arr1[i] == arr1[k])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
            continue;

        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
        }
    }

    return 0;
}