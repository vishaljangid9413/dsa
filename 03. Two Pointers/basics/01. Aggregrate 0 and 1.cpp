#include <iostream>
using namespace std;

/*
Problem: Sort a binary array (0s and 1s) such that all 0s are on the left side and all 1s are on the right side.

Time Complexity: O(n)
- The while loop runs from the start to the end of the array. In each iteration, either `start` is incremented or `end` is decremented, so the number of operations is proportional to `n`.

Space Complexity: O(1)
- The sorting is done in-place, requiring no additional space other than a few extra variables.

Approach:
1. **Two-pointer technique**:
   - We maintain two pointers, `start` and `end`. The `start` pointer starts at the beginning, and the `end` pointer starts at the end.
   - We scan the array from both sides. If `start` points to a `0`, it is already in the correct position, so we increment `start`.
   - If `start` points to a `1`, we need to swap it with a `0` from the right. This is done using the `end` pointer, which scans the array from the right, looking for `0`s.
   - Continue this process until `start` meets `end`.

2. **Edge Cases**:
   - If the array is already sorted with all 0s on the left and 1s on the right, it will not perform unnecessary swaps.
   - If the array contains only `0`s or only `1`s, it will handle that as well.

*/

int main(){
    int arr[] = {1, 0, 1, 0, 1, 0}; // Input array containing 0s and 1s
    int n = size(arr); // Size of the array
    int start = 0, end = n - 1; // Two pointers: `start` from the beginning, `end` from the end

    // Step 1: Use two pointers to sort the array
    while (start < end) {
        if (arr[start] == 0) {
            // If the element at `start` is already 0, it's in the correct position
            start++;
        } else {
            // If the element at `start` is 1, we need to swap it with a 0 from the right
            if (arr[end] == 0) {
                swap(arr[start], arr[end]); // Swap 1 at `start` with 0 at `end`
                start++;
                end--;
            } else {
                // If `end` points to a 1, move the `end` pointer leftwards
                end--;
            }
        }
    }

    // Step 2: Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element in the sorted array
    }
}
