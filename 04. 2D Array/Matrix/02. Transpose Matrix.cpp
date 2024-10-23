#include <iostream>
using namespace std;

// Problem: Transpose a square 2D array (matrix).
// Approach: Swap the elements arr[i][j] with arr[j][i] to achieve the transpose.
// Time Complexity: O(row * col), since we iterate over the matrix.
// Space Complexity: O(1), as we are using a constant amount of extra space for swapping.

int main() {
    // Initialize a 3x3 2D array with values from 1 to 9.
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int row = 3, col = 3; // Define the number of rows and columns.

    // Loop through the upper triangular part of the matrix to swap elements.
    for (int i = 0; i < row - 1; i++) { // Iterate through rows
        for (int j = i + 1; j < col; j++) { // Iterate through columns, starting from i+1 to avoid double swapping
            swap(arr[i][j], arr[j][i]); // Swap the element at (i, j) with (j, i)
        }
    }

    // Print the transposed 2D array.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Print each element followed by a space.
        }
        cout << endl; // Move to the next line after printing each row.
    }

    return 0; // Indicate successful completion of the program.
}
