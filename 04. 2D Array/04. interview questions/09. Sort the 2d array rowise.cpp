#include <iostream>
#include <vector>
using namespace std;

// Problem: Given a 1D array representing a 3x3 matrix, we need to sort each row individually.
// The sorted rows should then be printed as a 1D array.
//
// Approach: 
// - We'll use the Bubble Sort algorithm to sort each row of the matrix.
// - The algorithm compares adjacent elements and swaps them if they are in the wrong order,
//   repeatedly going through the array until no swaps are needed for each row.
//
// Time Complexity: O(n^2) - Sorting each row individually using Bubble Sort,
// where n is the number of elements in each row (3 in this case).
// Space Complexity: O(1) - Sorting is done in-place, so no additional space is used.

int main() {
    int arr[] = {4, 2, 0, 5, 2, 6, 2, 3, 1}; // The 1D array representing a 3x3 matrix.
    int row = 3, col = 3; // Defining the matrix dimensions (3x3).

    // Sorting each row separately using Bubble Sort.
    for (int i = 0; i < row; i++) {
        // For each row, we perform a bubble sort on the elements of that row.
        for(int j = i * col; j < (i + 1) * col - 1; j++) { 
            // We are iterating over the elements of the current row (subarray of arr).
            for(int k = i * col; k < ((i + 1) * col) - (j % col) - 1; k++) {
                // Compare adjacent elements in the row and swap if needed.
                if(arr[k] > arr[k + 1]) {
                    swap(arr[k], arr[k + 1]); // Swap if the current element is greater than the next.
                }
            }
        }
    }

    // Printing the sorted matrix as a 1D array.
    for(int i = 0; i < row * col; i++) {
        cout << arr[i] << " "; // Output the sorted array.
    }

    return 0; // Return 0 to indicate successful execution.
}
