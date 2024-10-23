#include <iostream>
using namespace std;

/*
Problem: Search for a target element in a rotated sorted array.
- The array is sorted but rotated at some pivot point, and the goal is to find the index of the target element.

Time Complexity: O(log n)
- The algorithm uses binary search, which reduces the search space by half at each step, giving a logarithmic time complexity.

Space Complexity: O(1)
- Only a constant amount of extra space is used for variables.

Approach:
1. The array is sorted but rotated at an unknown pivot point.
2. Use binary search to search for the target:
   - First, check if `arr[mid]` equals the target, if so, return `mid` as the answer.
   - Otherwise, determine which half of the array is sorted:
     - If the left half (`arr[0]` to `arr[mid]`) is sorted, check if the target lies within that half.
     - If the right half (`arr[mid]` to `arr[end]`) is sorted, check if the target lies within that half.
   - Adjust the search range based on whether the target lies in the sorted half or not.
3. Continue this process until the target is found or the search range is exhausted.

*/

int main() {
    int arr[] = {4, 5, 6, 7, 10, 1, 2}; // Example of a rotated sorted array
    int n = size(arr), target = 10; // Size of the array and the target to search
    int start = 0, end = n - 1, mid, ans = -1; // Initialize start, end, mid, and ans
    
    // Binary Search Algorithm to find the target element
    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid to avoid overflow
        
        // Check if the target is at the mid index
        if (arr[mid] == target) {
            ans = mid; // Target found, store the index in ans
            break; // Exit the loop
        }
        // Check if the left half (arr[0] to arr[mid]) is sorted
        else if (arr[0] <= arr[mid]) {
            // If target lies in the sorted left half
            if (arr[0] <= target && target < arr[mid]) {
                end = mid - 1; // Move to the left half
            } else {
                start = mid + 1; // Move to the right half
            }
        }
        // Otherwise, the right half (arr[mid] to arr[end]) must be sorted
        else {
            // If target lies in the sorted right half
            if (arr[mid] < target && target <= arr[end]) {
                start = mid + 1; // Move to the right half
            } else {
                end = mid - 1; // Move to the left half
            }
        }
    }
    
    // Output the index of the target element (or -1 if not found)
    cout << ans;

    return 0;
}
