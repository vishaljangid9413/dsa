#include <iostream>
using namespace std;

/*
Problem: Find the peak element in a bitonic array (an array that first increases, then decreases).
- A peak element is one that is greater than both its neighbors.
- The array should have at least 3 elements (increasing and then decreasing).
- The approach uses binary search to efficiently find the peak element.

Time Complexity: O(log n)
- Binary search reduces the search space by half in each step, giving logarithmic time complexity.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space.

Approach:
1. Use binary search to find the peak element. 
2. For each `mid` index, check if the element is greater than its previous and next elements.
   - If true, the peak is found.
   - Otherwise, adjust the search space:
     - If `arr[mid]` is greater than `arr[mid-1]`, move to the right (the peak lies on the right side).
     - If `arr[mid]` is smaller than `arr[mid-1]`, move to the left (the peak lies on the left side).
3. The peak will be found where `arr[mid-1] < arr[mid] > arr[mid+1]`.
*/

int main() {
    int arr[] = {2, 4, 6, 8, 10, 8, 5}; // Example of a bitonic array
    int n = size(arr); // Size of the array
    int start = 1, end = n - 2, mid, ans = -1; // Initialize start, end, and ans for binary search

    // Ensure the array has more than 2 elements (minimum required for a peak in a bitonic array)
    if (n > 2) {
        while (start <= end) {
            mid = start + (end - start) / 2; // Calculate mid to avoid overflow

            // Check if arr[mid] is the peak element
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                ans = mid; // Peak found at index mid
                break; // Exit the loop as peak is found
            }
            // If arr[mid] is greater than arr[mid-1], move right
            else if (arr[mid - 1] < arr[mid]) {
                start = mid + 1; // Peak must lie on the right side
            }
            // Otherwise, move left
            else {
                end = mid - 1; // Peak must lie on the left side
            }
        }
    }
    
    // Output the index of the peak element
    cout << ans;

    return 0;
}
