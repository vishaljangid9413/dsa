#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a main string `st` and a substring `sub`, find the starting index 
// in `st` where `sub` is located. If the substring `sub` is not found 
// in `st`, return -1. This is a substring search problem, where we aim 
// to find the first occurrence of `sub` within `st`.

// Approach:
// - This problem can be solved using the Knuth-Morris-Pratt (KMP) algorithm, which 
//   optimizes the substring search by precomputing an LPS (Longest Prefix Suffix) 
//   array for the substring `sub`.
// - Step 1: Construct the LPS array for `sub`, which allows us to skip redundant 
//   comparisons by storing the lengths of the longest proper prefix of `sub` that 
//   is also a suffix up to each position.
// - Step 2: Use two pointers, `first` for the main string `st` and `second` for `sub`, 
//   to attempt to match `sub` in `st`.
//   - If characters match, both pointers are advanced.
//   - If there is a mismatch:
//     - If `second` is zero, only move `first` (no partial match found so far).
//     - Otherwise, reset `second` to `lps[second - 1]`, using the LPS array to skip 
//       redundant checks and resume comparison.
// - If the entire substring `sub` is found in `st`, the start index of the match is 
//   calculated as `first - second`. If no match is found, we return -1.

// Time Complexity: O(n + m), where `n` is the length of `st` and `m` is the length of `sub`.
// - The LPS array is computed in O(m), and the main matching loop is O(n).

// Space Complexity: O(m), due to the storage of the LPS array for `sub`.

int main(){
    string st = "aabaaabaaac";  // Main string
    string sub = "aabaaac";      // Substring to search for
    int n = st.size();           // Length of the main string
    int m = sub.size();          // Length of the substring
    vector<int> lps(m, 0);       // LPS array initialized to zero for `sub`

    // Step 1: Construct the LPS array for the substring `sub`
    int first = 0, second = 1;   // Pointers to build LPS array
    while (second < m) {
        if (sub[first] == sub[second]) {
            // If characters match, update the LPS value for `second` index
            lps[second] = first + 1;
            first++;
            second++;
        } else {
            // If there's a mismatch
            if (first == 0) { 
                // If `first` is zero, set LPS of `second` to 0 and move `second` forward
                lps[second] = 0;
                second++;
            } else {
                // Use the LPS value to skip redundant checks
                first = lps[first - 1];
            }
        }
    }

    // Step 2: Attempt to match `sub` in the main string `st`
    first = 0; second = 0;  // Reset pointers to traverse `st` and `sub`
    while (first < n && second < m) {
        if (st[first] == sub[second]) {
            // If characters match, move both pointers
            first++;
            second++;
        } else {
            // If there's a mismatch
            if (second == 0) {
                // If `second` is zero, move only `first`
                first++;
            } else {
                // Use the LPS array to avoid redundant checks
                second = lps[second - 1];
            }
        }
    }

    // Output the result: start index of match in `st`, or -1 if no match is found
    if (second == m) {
        cout << first - second;  // Match found, output the starting index
    } else {
        cout << -1;              // No match found
    }
}
