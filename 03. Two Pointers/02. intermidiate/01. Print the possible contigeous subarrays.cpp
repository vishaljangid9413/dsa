#include <iostream>
using namespace std;

/*
Problem: Generate and print all possible contiguous subarrays from a given array.

Time Complexity: O(n^3)
- The outer loop runs `n` times. 
- The second loop runs for each possible starting point of a subarray, ranging from `n` to `1` elements.
- The innermost loop runs for each subarray, printing its elements, and in total, across all iterations, it processes all subarray elements.

Space Complexity: O(1)
- We are using only a constant amount of extra space for the loop variables and no additional arrays or data structures.
- The space used for outputting subarrays does not count towards space complexity as it does not hold memory persistently.

Approach:
1. **Triple-loop method**:
   - Outer loop (`i`): Controls the length of the subarrays (from 1 element to `n` elements).
   - Second loop (`j`): Moves the starting index of the subarray.
   - Innermost loop (`k`): Extracts and prints the elements of the subarray.
   
2. **Edge Cases**:
   - Empty arrays should be handled outside of this loop, though this current implementation assumes the array is not empty.
   - Single-element arrays will print themselves as the only subarray.

*/

int main()
{
    int arr[] = {2, 4, 5, 6}; // Input array
    int n = size(arr); // Get the size of the array

    // Outer loop to control the length of the subarray
    for(int i = 0; i < n; i++) {
        // Second loop to control the starting point of the subarray
        for(int j = 0; j < n - i; j++) {
            // Print the subarray starting from index `j` of length `i+1`
            cout << "[";
            for(int k = 0; k <= i; k++) {
                cout << arr[j + k]; // Print each element in the subarray

                // To format the output correctly with commas
                if (k != i) {
                    cout << ", ";
                }
            }
            cout << "] ";
        }
        cout << endl; // Move to the next line after printing all subarrays of length `i+1`
    }
}
