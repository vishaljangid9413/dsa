#include <iostream>
#include <vector>
using namespace std;

// Problem: Find all majority elements in an array where a majority element is defined 
// as an element that appears more than n/3 times. There can be at most two such majority elements in an array.
// For example, if the size of the array is 7, then the counts for majority elements must satisfy:
// - If one majority element exists, the remaining elements must equal n - (n/3 + 1) * 1
// - If two majority elements exist, the remaining elements must equal n - (n/3 + 1) * 2
// This means there can be at most two majority elements in the array.

// Approach: 
// We will use the Boyer-Moore Majority Vote Algorithm to find up to two candidates 
// for the majority element and then verify their counts in the array.

int main() {
    int arr[] = {2, 1, 1, 3, 1, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // Get the size of the array.

    int candidate = 0, count = 0; // Variables for the first candidate.
    int candidate1 = 0, count1 = 0; // Variables for the second candidate.

    // Step 1: Find potential candidates for the majority elements.
    for (int i = 0; i < n; i++) {
        if (count <= 0 && candidate1 != arr[i]) {
            count = 1; // Reset count for the first candidate.
            candidate = arr[i]; // Set the first candidate.
        } else if (count1 <= 0 && candidate != arr[i]) {
            count1 = 1; // Reset count for the second candidate.
            candidate1 = arr[i]; // Set the second candidate.
        } else if (candidate == arr[i]) {
            count++; // Increment count for the first candidate.
        } else if (candidate1 == arr[i]) {
            count1++; // Increment count for the second candidate.
        } else {
            count--; // Decrement count for the first candidate.
            count1--; // Decrement count for the second candidate.
        }
    }

    // Step 2: Verify the counts of the potential majority candidates.
    count = 0; // Reset count for verification of the first candidate.
    count1 = 0; // Reset count for verification of the second candidate.
    for (int i = 0; i < n; i++) {
        if (candidate == arr[i]) {
            count++; // Count occurrences of the first candidate.
        } else if (candidate1 == arr[i]) {
            count1++; // Count occurrences of the second candidate.
        }
    }

    // Step 3: Store the results of majority candidates.
    vector<int> ans; // Vector to hold the results.
    if (count > n / 3) {
        ans.push_back(candidate); // Add the first candidate if it is a majority.
    }
    if (count1 > n / 3) {
        ans.push_back(candidate1); // Add the second candidate if it is a majority.
    }

    // Output the results.
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " "; // Print the majority elements.
    }

    return 0;
}
