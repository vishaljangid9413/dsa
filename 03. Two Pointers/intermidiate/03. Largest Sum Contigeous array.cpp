#include <iostream>
using namespace std;

/*
Problem: Find the maximum sum of a contiguous subarray. 
         This is a classic problem known as "Kadane's Algorithm".

Time Complexity: O(n)
- The algorithm makes a single pass through the array, updating the running prefix sum and the maximum sum found so far.

Space Complexity: O(1)
- The algorithm uses only a constant amount of extra space (`maxi`, `prefix`, and the loop variable `i`).

Approach (Kadane’s Algorithm):
1. **Initialize**:
   - `maxi`: To store the maximum sum encountered so far, initialized to a very small value (INT_MIN).
   - `prefix`: To store the sum of the current subarray, initialized to 0.
   
2. **Iterate through the array**:
   - For each element, add it to `prefix`.
   - Update `maxi` if `prefix` exceeds the current `maxi`.
   - If `prefix` becomes negative, reset it to 0 (as a negative sum will decrease the total subarray sum).
   
3. **Result**:
   - The `maxi` will contain the maximum sum of the contiguous subarray.

4. **Edge Cases**:
   - If all numbers are negative, the algorithm will still return the least negative number (which is the maximum sum possible in that case).

*/

int main()
{
    int arr[] = {3, 4, -2, 5, 8, 20, -10, 8}; // Input array
    int n = size(arr); // Get the size of the array

    int maxi = INT_MIN; // To store the maximum sum encountered so far
    int prefix = 0;     // To store the running sum of the current subarray

    // Iterate through the array
    for(int i = 0; i < n; i++) {
        prefix += arr[i];          // Add the current element to the running sum
        maxi = max(maxi, prefix);  // Update maxi if the current sum is greater
        if(prefix < 0) {           // If the running sum is negative, reset it to 0
            prefix = 0;
        }
    }

    cout << "Maximum Sum: " << maxi << endl; // Output the maximum sum
}
