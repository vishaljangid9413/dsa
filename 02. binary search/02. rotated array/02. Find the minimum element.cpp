#include <iostream>
using namespace std;

/*
Problem: Find the index of the minimum element in a rotated sorted array.
- The array is sorted but rotated, and we want to find the index of the smallest (pivot) element.

Time Complexity: O(log n)
- The algorithm uses binary search, which reduces the search space by half in each step, leading to a logarithmic time complexity.

Space Complexity: O(1)
- Only a constant amount of extra space is used for variables.

Approach:
1. The array is sorted but rotated, which means there is a pivot point where the minimum element occurs.
2. Use binary search to find this pivot (minimum element):
   - If `arr[mid]` is greater than `arr[0]`, it means the left part is sorted, so the minimum element must be in the right half.
   - If `arr[mid]` is smaller than or equal to `arr[0]`, it means the pivot is in the left half, and we update the answer to `mid`.
3. The binary search continues until we find the minimum element.
*/

int main() {
    int arr[] = {4, 6, 8, 10, 11, 0, 1, 2}; // Example of a rotated sorted array
    int n = size(arr); // Size of the array
    int start = 0, end = n - 1, mid, ans = arr[0]; // Initialize start, end, mid, and ans
    
    // Binary Search Algorithm to find the minimum element (pivot)
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid to avoid overflow
        
        // If the first element is smaller than mid, the minimum must be in the right half
        if (arr[0] < arr[mid]) {
            start = mid + 1; // Move to the right half
        }
        // If arr[mid] is smaller or equal to arr[0], the minimum is either at mid or in the left half
        else {
            ans = mid; // Update the answer to the current mid index (potential minimum)
            end = mid - 1; // Move to the left half
        }
    }

    // Output the index of the minimum element
    cout << ans; // Output the index of the pivot (minimum element)

    return 0;
}
