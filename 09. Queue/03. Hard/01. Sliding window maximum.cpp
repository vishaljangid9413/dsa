#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Problem: Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/description/

// Problem Description:
// Given an array `nums` and a sliding window size `k`, we need to find the maximum element
// in each sliding window of size `k`. As the window slides from left to right, we need to
// efficiently maintain the maximum value of each window without recalculating it from scratch
// for each window.
//
// Approach:
// 1. We use a deque (double-ended queue) to store the indices of elements in the current window
//    such that the elements in the deque are in decreasing order. The first element in the deque
//    represents the maximum element for the current window.
 
// Time Complexity:
// - The overall time complexity is O(n) where n is the size of the input array. This is because
//   each element is pushed and popped from the deque at most once.
//
// Space Complexity:
// - O(k), where k is the size of the sliding window. This is the space used by the deque to store
//   the indices of elements in the current window.

int main() {
    deque<int> dq;  // Deque to store indices of elements in the current window
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};  // Input array
    int n = nums.size();  // Size of the array
    int k = 3;  // Size of the sliding window
    vector<int> ans;  // Vector to store the result (maximum values of each window)

    // We need to maintain the deque such that it stores indices in decreasing order of their values.
    for (int i = 0; i < n; i++) {
        // Remove all elements that are out of the current window (indices <= i - k)
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove all elements from the deque that are smaller than the current element
        // because they will never be the maximum element when the current element is present
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);

        // If we have processed at least k elements, the first element in the deque is the
        // maximum of the current window
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);  // Add the maximum element (the front of the deque)
        }
    }

    // Print the result
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;  // Output the maximum values for each sliding window.
}
