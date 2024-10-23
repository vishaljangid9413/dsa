#include <iostream>
using namespace std;

// Problem: Search for a given element 'k' in a 2D sorted array.
// Approach: Treat the 2D array as a 1D array and apply binary search.
// To find the corresponding row and column indices from the mid index during the search.
// Time Complexity: O(log(row * col)), as we are performing binary search on the total number of elements.

int main() {
    int arr[3][4] = {1, 3, 5, 7, 
                     10, 11, 16, 20, 
                     23, 30, 34, 60};
    int row = 3, col = 4, k = 3, ans = -1, mid;
    int start = 0, end = (row * col) - 1; // Initialize start and end for binary search

    // Perform binary search
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid index
        int row_index = mid / col; // Calculate the row index
        int col_index = mid % col; // Calculate the column index

        // Check if the element at mid index is equal to k
        if (arr[row_index][col_index] == k) {
            ans = 1; // Element found
            break;
        } else if (arr[row_index][col_index] < k) {
            start = mid + 1; // Move search to the right half
        } else {
            end = mid - 1; // Move search to the left half
        }
    }

    // Return the result of the search (1 if found, -1 if not)
    return ans;
}
