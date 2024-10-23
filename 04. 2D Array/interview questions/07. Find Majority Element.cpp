#include <iostream>
using namespace std;

// Problem: Given an array of size n, where the goal is to find the majority element,
// which is defined as an element that appears more than n/2 times. If such an element
// exists, we need to return it; otherwise, indicate that there is no majority element.
//
// Approach:
// 1. Use the Boyer-Moore Majority Vote Algorithm to find a candidate for the majority element.
// 2. Verify if the candidate is indeed the majority by counting its occurrences in the array.
// 3. If the candidate's count is greater than n/2, it is the majority element; otherwise, it is not.
//
// Time Complexity: O(n) for traversing the array twice.
// Space Complexity: O(1) since we are using a constant amount of extra space.

int main() {
    // Initialize the array with elements to find the majority element.
    int arr[] = {2, 2, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Get the size of the array.

    int candidate = 0; // To store the potential majority element.
    int count = 0; // To count occurrences of the candidate.

    // Step 1: Boyer-Moore Majority Vote Algorithm to find the candidate.
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i]; // Set the current element as the candidate.
            count = 1; // Reset count for the new candidate.
        } else if (arr[i] == candidate) {
            count++; // Increment count if the current element matches the candidate.
        } else {
            count--; // Decrement count if the current element does not match.
        }
    }

    // Step 2: Verify if the candidate is indeed the majority element.
    count = 0; // Reset count for verification.
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++; // Count how many times the candidate appears.
        }
    }

    // Step 3: Check if the candidate's count is greater than n/2.
    if (count > n / 2) {
        cout << "YES " << candidate; // Print the candidate if it is the majority.
    } else {
        cout << "NO"; // Indicate that there is no majority element.
    }

    return 0;
}
