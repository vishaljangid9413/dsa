#include <iostream>
using namespace std;

// Problem: Rotate a square 2D array (matrix) by 90 degrees clockwise.
// Approach:
// 1. Reverse the entire matrix vertically by swapping elements in each row.
// 2. This will set the foundation for a clockwise rotation.
// Time Complexity: O(n^2), where n is the number of rows/columns in the square matrix.
// Space Complexity: O(1), as we use a constant amount of extra space for swapping.

int main() {
    // Initialize a 4x4 2D array with values from 1 to 16.
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int row = 4, col = 4; // Define the number of rows and columns.

    for(int i=0;i<row/2;i++){
        for(int j=0;j<col;j++){
            swap(arr[i][j], arr[row-i-1][col-j-1]);
        }
    }

    // Print the rotated 2D array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Print each element followed by a space
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful completion of the program
}
