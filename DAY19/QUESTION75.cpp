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

    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}