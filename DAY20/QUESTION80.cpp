#include <iostream>
using namespace std;

int main() 
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int matrix[10][10];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nColumn-wise sums are:\n";

    for (int j = 0; j < cols; j++) {
        int sum = 0;

        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }

        cout << "Sum of Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}