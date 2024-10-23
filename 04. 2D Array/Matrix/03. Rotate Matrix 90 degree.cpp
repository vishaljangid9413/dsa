#include <iostream>
using namespace std;

// Problem: Rotate a square 2D array (matrix) by 90 degrees clockwise.
// Approach: 
// 1. First, transpose the matrix by swapping elements arr[i][j] with arr[j][i].
// 2. Then, reverse each row of the transposed matrix.
// Time Complexity: O(n^2), where n is the number of rows/columns in the square matrix.
// Space Complexity: O(1), as we are using a constant amount of extra space for swapping.

int main() {
    // Initialize a 4x4 2D array with values from 1 to 16.
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int row = 4, col = 4; // Define the number of rows and columns.

    // Step 1: Transpose the matrix
    for (int i = 0; i < row - 1; i++) { // Iterate through rows
        for (int j = i + 1; j < row; j++) { // Iterate through columns starting from i + 1
            swap(arr[i][j], arr[j][i]); // Swap the element at (i, j) with (j, i)
        }
    }

    // Step 2: Reverse each row of the transposed matrix
    for (int i = 0; i < row; i++) { // Iterate through each row
        int start = 0; // Start index of the row
        int end = col - 1; // End index of the row
        while (start < end) { // While the start index is less than the end index
            swap(arr[i][start], arr[i][end]); // Swap elements at start and end indices
            start++; // Move start index forward
            end--; // Move end index backward
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
