#include <iostream>
#include <vector>
using namespace std;

// Problem: Find the row with the maximum number of 1s in a binary matrix.
// Approach: Start from the top-right corner of the matrix and move through it, 
// keeping track of the count of 1s in each row and identifying the row with the maximum count of 1s.
// Time Complexity: O(row + col) as we can eliminate either a row or a column in each step.

int main() {
    // Initialize the binary matrix with rows of 0s followed by 1s.
    vector<vector<int>> arr = {
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int row = arr.size();       // Get the number of rows in the matrix.
    int col = arr[0].size();    // Get the number of columns in the matrix.
    int index = -1;             // Initialize variable to store the index of the row with the maximum number of 1s.
    int row_index = 0, col_index = col - 1; // Start from the top-right corner of the matrix.
    int count = 0;              // Variable to count the number of 1s in the current row.
    int maxi = 0;               // Variable to keep track of the maximum count of 1s found so far.

    // Loop until we traverse the entire matrix
    while (row_index < row && col_index >= 0) {
        // Check if the current row contains only 1s (i.e., first element is 1)
        if (arr[row_index][0] == 1) {
            index = row_index; // Record the current row index as it contains only 1s.
            cout << index << " " << col - 1; // Output the index of the row and the last column.
            return 1; // Exit the program as we found the row with only 1s.
        }
        // Check if the current element is 1
        else if (arr[row_index][col_index] == 1) {
            count++; // Increment count of 1s in the current row.
            col_index--; // Move left to check the next element in the row.
        } else {
            // If the current element is 0, check if the count of 1s is greater than the maximum count found so far.
            if (count > maxi) {
                index = row_index; // Update the index of the row with maximum 1s.
                maxi = count; // Update the maximum count of 1s.
            }
            count = 0; // Reset the count for the next row.
            row_index++; // Move to the next row.
            col_index = col - 1; // Reset column index to the last column for the new row.
        }
    }
    // After traversing the matrix, output the index of the row with maximum 1s found.
    cout << index << endl; // If no row with only 1s is found, the index will remain -1.
}
