#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n) for processing the array.
// Space Complexity: O(1) for the in-place modification of the original array.

int main() {
    // Initialize a 2D vector (array) with some sample data.
    vector<vector<int>> arr = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    int row = arr.size(); // Get the number of rows.
    int col = arr[0].size(); // Get the number of columns.
    int n = row * col; // Total number of elements.
    vector<int> ans(2, 0); // To store duplicate and missing values.

    // Step 1: Decrement each element in the array by 1 to fit the index range.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j]--; // Decrement each element to fit the 0-based index.
        }
    }

    // Step 2: Use the modified array to track occurrences of elements.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int value = arr[i][j] % n; // Get the current element's adjusted value.
            int row_index = value / col; // Calculate the row index based on value.
            int col_index = value % col; // Calculate the column index based on value.
            arr[row_index][col_index] += n; // Increment the corresponding index by n.
        }
    }

    // Step 3: Identify the duplicate and missing elements based on occurrences.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int occ = arr[i][j] / n; // Get the occurrence count by dividing by n.
            int index = i * col + j; // Calculate the 1D index for output.
            if (occ == 0) { // If occurrence is zero, the number is missing.
                ans[1] = index + 1; // Store the missing number.
                cout << "Missing: " << index + 1 << endl; // Print the missing number.
            } else if (occ == 2) { // If occurrence is two, the number is duplicate.
                ans[0] = index + 1; // Store the duplicate number.
                cout << "Duplicate: " << index + 1 << endl; // Print the duplicate number.
            }
        }
    }
}
