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

    cout << "\nRow-wise sums are:\n";

    for (int i = 0; i < rows; i++) {
        int sum = 0;

        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }

        cout << "Sum of Row " << i + 1 << " = " << sum << endl;
    }

    return 0;
}