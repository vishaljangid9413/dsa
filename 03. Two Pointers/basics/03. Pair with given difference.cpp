#include <iostream>
using namespace std;

/*
Problem: Given a sorted array of positive integers, find two numbers such that the absolute difference between them is equal to the target value.

Time Complexity: O(n)
- The while loop runs with two pointers (`start` and `end`), where each pointer moves forward until the correct pair is found. Each element is processed at most once.

Space Complexity: O(1)
- The algorithm uses a constant amount of space, only requiring a few extra variables (`start`, `end`, `target`), and no additional memory for arrays is used.

Approach:
1. **Two-pointer technique**:
   - Initialize two pointers, `start` and `end`. `start` points to the first element, and `end` points to the second element.
   - Check the difference between `arr[end]` and `arr[start]`.
     - If the difference equals the target, print the pair.
     - If the difference is less than the target, increment `end` to increase the difference.
     - If the difference is greater than the target, increment `start` to decrease the difference.
   - The loop continues until the correct pair is found or until `end` exceeds the array size.

2. **Edge Cases**:
   - If no such pair exists, the loop will terminate without printing any result.
   - If `target` is negative, we convert it to a positive value at the beginning.

*/

int main() {
    int arr[] = {2, 3, 5, 10, 50, 80}; // Input sorted array
    int n = size(arr); // Size of the array
    int start = 0, end = 1, target = 45; // Initialize `start` and `end` pointers, and the target difference

    // Step 1: Ensure the target is a positive value
    if (target < 0) {
        target *= -1;
    }

    // Step 2: Use two pointers to find the pair with the given difference
    while (end < n) {
        if (arr[end] - arr[start] == target) {
            // If the difference between `arr[end]` and `arr[start]` equals the target, we found the pair
            cout << "Ans: " << arr[start] << " " << arr[end] << endl;
            break;
        } else if (arr[end] - arr[start] < target) {
            // If the difference is less than the target, increment `end` to increase the difference
            end++;
        } else {
            // If the difference is greater than the target, increment `start` to decrease the difference
            start++;
        }

        // Make sure `start` and `end` are not equal, as we need two distinct elements
        if (start == end) {
            end++;
        }
    }

    // If no pair is found, this code does not print anything, but you can handle that case
    // by adding a message like: cout << "No pair found" << endl;
}
