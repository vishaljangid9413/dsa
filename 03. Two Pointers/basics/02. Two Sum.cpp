#include <iostream>
using namespace std;

/*
Problem: Given a sorted array of integers, find two numbers such that their sum equals the target value.

Time Complexity: O(n)
- The while loop runs with two pointers from the beginning and end of the array. Each iteration reduces the search space by moving one of the pointers, making the complexity linear.

Space Complexity: O(1)
- The algorithm uses a constant amount of space since it only involves a few variables (`start`, `end`, `target`), and no additional memory for arrays is used.

Approach:
1. **Two-pointer technique**:
   - The array is sorted, so we use two pointers: one starting at the beginning (`start`) and one at the end (`end`).
   - Check the sum of the elements at `start` and `end`.
     - If the sum equals the target, print the numbers and exit.
     - If the sum is less than the target, increment the `start` pointer (move towards larger numbers).
     - If the sum is greater than the target, decrement the `end` pointer (move towards smaller numbers).
   - The loop continues until the two pointers meet.

2. **Edge Cases**:
   - If no such pair exists, the loop will terminate without printing any result.
   - The array must be sorted for the two-pointer technique to work.

*/

int main() {
    int arr[] = {2, 7, 11, 15, 27}; // Input sorted array
    int n = size(arr); // Size of the array
    int start = 0, end = n - 1, target = 22; // Initialize `start` and `end` pointers, and the target sum

    // Step 1: Use two pointers to find the pair that sums to `target`
    while (start < end) {
        if (arr[start] + arr[end] == target) {
            // If the sum of elements at `start` and `end` equals `target`, we found the pair
            cout << "Ans: " << arr[start] << " " << arr[end] << endl;
            break;
        } else if (arr[start] + arr[end] < target) {
            // If the sum is less than `target`, increment `start` to get a larger sum
            start++;
        } else {
            // If the sum is greater than `target`, decrement `end` to get a smaller sum
            end--;
        }
    }

    // If no pair is found, this code does not print anything, but you can handle that case
    // by adding a message like: cout << "No pair found" << endl;
}
