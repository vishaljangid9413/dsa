#include <iostream>
using namespace std;

// Problem: Reverse each row of a 2D array.
// Approach: For each row, use a two-pointer technique to swap elements from the start and end until they meet in the middle.
// Time Complexity: O(row * col), since we visit each element once.
// Space Complexity: O(1), as we are using a constant amount of extra space for swapping.

int main() {
    // Initialize a 3x3 2D array with values from 1 to 9.
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int row = 3, col = 3; // Define the number of rows and columns.

    // Loop through each row to reverse its elements.
    for (int i = 0; i < row; i++) {
        int start = 0; // Start pointer at the beginning of the row.
        int end = col - 1; // End pointer at the last element of the row.

        // Continue swapping until the start pointer is less than the end pointer.
        while (start < end) {
            swap(arr[i][start], arr[i][end]); // Swap elements at start and end pointers.
            start++; // Move the start pointer to the right.
            end--; // Move the end pointer to the left.
        }
    }

    // Print the reversed 2D array.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << ","; // Print each element followed by a comma.
        }
        cout << " "; // Print a space after each row.
    }

    return 0; // Indicate successful completion of the program.
}
