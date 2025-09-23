#include <iostream>
using namespace std;

/*
Problem: Finding the first element in a sorted array that is greater than or equal to a target value.
Approach:
1. Use binary search to efficiently find the first element that is greater than or equal to the target.
2. The search updates the index `ans` whenever such an element is found.
3. If the current element is greater than or equal to the target, search the left half.
4. If the current element is less than the target, search the right half.
Points to remember:
1. This problem can be solved in O(log n) time using binary search.
2. The variable `ans` holds the index of the first element greater than or equal to the target.
3. If no such element is found, `ans` will be `n`, which can be checked as out of bounds.
*/

// Algorithm: Binary Search
// Time Complexity: O(log n) - Due to binary search.
// Space Complexity: O(1) - No extra space is used.
int main(){
    int arr[] = {1, 4, 6, 8, 10, 14, 16, 18};  // Sorted array
    int n = size(arr), target = -1;  // Target value to search for
    int start = 0, end = n-1, ans = n, mid;

    // Binary search to find the first element greater than or equal to target
    while (start <= end){
        mid = start + (end - start) / 2;  // Calculate mid-point to avoid overflow
        if(arr[mid] >= target){
            ans = mid;  // If the element is greater than or equal to target, store its index
            end = mid - 1;  // Move to the left half to find earlier occurrences
        } else {
            start = mid + 1;  // Move to the right half if the current element is less than target
        }
    }

    // Output the result
    cout << "Ans:: " << ans;
}
