#include <iostream>
using namespace std;

/*
Problem: Find the k-th missing element in a sorted array of distinct integers.
- We use a "virtual" array that counts the number of missing elements before each index.
- Instead of creating the virtual array explicitly, we compute the number of missing elements dynamically using the formula: missing = arr[mid] - mid - 1.

Time Complexity: O(log n)
- The algorithm uses binary search, which halves the search space in each iteration.

Space Complexity: O(1)
- Only a constant amount of extra space is used, regardless of the input size.

Approach:
1. Calculate the number of missing elements up to the current middle element using the formula: `missing = arr[mid] - mid - 1`.
2. Compare this missing count with `k` (the number of missing elements we are looking for).
3. Adjust the search range based on whether the missing count is greater or less than `k`.
4. Once the correct position is found, add `k` to the index to find the k-th missing number.
*/

// Example array: {1, 2, 3, 4, 7, 10, 11, 12}
// k = 3 (We want to find the 3rd missing element)

int main() {
    int arr[] = {1, 2, 3, 4, 7, 10, 11, 12}; // Sorted input array with missing elements
    int n = size(arr), k = 3; // n: Size of the array, k: Which missing element we want to find
    int start = 0, end = n - 1, mid, ans = n; // Initialize binary search variables
    
    // Binary Search Algorithm
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid to avoid overflow

        // Calculate the number of missing elements up to arr[mid]
        int missing = arr[mid] - mid - 1;

        // If missing elements count is greater than or equal to k, move left (check smaller elements)
        if (missing >= k) {
            ans = mid; // Store potential answer index
            end = mid - 1; // Search in the left half
        } else {
            // If the missing count is less than k, search the right half
            start = mid + 1;
        }
    }
    
    // Once we've found the position, calculate the k-th missing element
    cout << (ans + k); // Output the result

    return 0;
}
