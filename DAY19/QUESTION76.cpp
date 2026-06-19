#include <iostream>
using namespace std;

int main() 
{
    int n, sum = 0;

    cout << "Enter the order of square matrix: ";
    cin >> n;

    int matrix[10][10];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    cout << "Sum of principal diagonal elements = " << sum;

    return 0;
}