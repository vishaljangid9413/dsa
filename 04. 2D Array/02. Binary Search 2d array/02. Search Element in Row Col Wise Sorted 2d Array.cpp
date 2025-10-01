#include <iostream>
using namespace std;

// Problem: Search for a target element in a sorted 2D matrix
// where each row is sorted from left to right and each column is sorted from top to bottom.
// Approach: Start searching from the top-right corner of the matrix and eliminate either a row or a column in each iteration.
// Time Complexity: O(row + col), as we can eliminate one row or one column in each step.

int main() {
    int arr[3][5] = {
        {4, 7, 15, 25, 60},
        {18, 22, 26, 42, 80},
        {36, 40, 50, 68, 104}
    };
    int row = 3, col = 5, target = 50;

    // Start from the top-right corner of the matrix
    int row_index = 0, col_index = col - 1;

    // Search for the target element
    while (row_index < row && col_index >= 0) {
        if (arr[row_index][col_index] == target) {
            cout << true; // Element found
            break;
        } else if (arr[row_index][col_index] < target) {
            row_index++; // Move down if current element is less than target
        } else {
            col_index--; // Move left if current element is greater than target
        }
    }

    // If the target is not found, consider printing a message
    if (row_index >= row || col_index < 0) {
        cout << false; // Element not found
    }

    return 0;
}
