#include <iostream>
using namespace std;

// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns.
// Space Complexity: O(1) - We are not using any extra space apart from the input array.

// In this problem, we need to print the 2D array in a "wave" structure. 
// The idea is to print elements in the following pattern: 
// * Traverse the first column top to bottom.
// * Traverse the second column bottom to top.
// * Continue alternating for the remaining columns.
// Example of wave pattern in a 2D array (represented by stars):

// *   * * *   *
// *   *   *   *
// *   *   *   *
// * * *   * * *

int main() {
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // A 3x4 matrix
    int row = 3, col = 4; // Defining the dimensions of the matrix.

    // Looping through each column (wave-like traversal).
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j % 2 == 0) {
                // For even indexed columns, print top to bottom.
                cout << arr[i][j] << " ";
            } else {
                // For odd indexed columns, print bottom to top.
                cout << arr[row - i - 1][j] << " ";
            }
        }
        cout << endl; // New line after each row is printed.
    }
}
