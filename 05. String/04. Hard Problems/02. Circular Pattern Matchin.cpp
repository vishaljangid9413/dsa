#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a circular string `s` and a substring `sub`, determine if `sub` can be found 
// as a contiguous substring within `s`, considering its circular nature. If found, 
// output a positive result; otherwise, output -1.

// Approach:
// - To handle the circular nature of `s`, we concatenate `s` to itself. This doubles the 
//   length of `s` and makes any circular rotation of `s` appear as a linear substring within 
//   the concatenated string `s + s`.
// - We then use the Knuth-Morris-Pratt (KMP) algorithm to check if `sub` appears as a 
//   substring within `s + s`.
// - Step 1: Construct the Longest Prefix Suffix (LPS) array for `sub` to optimize the 
//   substring matching process by storing prefix-suffix relationships.
// - Step 2: Use two pointers, `first` for the concatenated string `s + s` and `second` 
//   for `sub`, to attempt to match `sub` within `s + s`.
//   - If characters match, both pointers move forward.
//   - If there's a mismatch, use the LPS array to avoid redundant comparisons and reset 
//     `second` appropriately.
// - If the entire `sub` is found in `s + s`, return a positive result. Otherwise, return -1.

// Time Complexity: O(n + m), where `n` is the length of the concatenated string `s + s` 
// and `m` is the length of `sub`.
// - LPS array computation is O(m), and the substring search in `s + s` is O(n).

// Space Complexity: O(m), for storing the LPS array for `sub`.

int main(){
    string s = "cdeabroab";    // Original circular string
    string sub = "abcde";       // Substring to search for in `s`
    s += s;                     // Concatenate `s` to itself to handle circular nature
    int n = s.size();           // Length of the concatenated string
    int m = sub.size();         // Length of the substring `sub`
    vector<int> lps(m, 0);      // LPS array for `sub`, initialized to zero

    // Step 1: Construct the LPS array for the substring `sub`
    int first = 0, second = 1;  // Pointers to build LPS array
    while (second < m) {
        if (sub[first] == sub[second]) {
            // If characters match, update the LPS value for `second` index
            lps[second] = first + 1;
            first++;
            second++;
        } else {
            // If there's a mismatch
            if (first == 0) {
                // If `first` is zero, simply move the `second` pointer forward
                second++;
            } else {
                // Use the LPS array to avoid redundant checks
                first = lps[first - 1];
            }
        }
    }

    // Step 2: Attempt to match `sub` in the concatenated string `s`
    first = 0; second = 0;       // Reset pointers for matching in `s + s`
    while (first < n && second < m) {
        if (s[first] == sub[second]) {
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

    // Output the result: if `second` reached `m`, `sub` is a substring of `s`
    if (second == m) {
        cout << second << " " << 1;  // Match found
    } else {
        cout << -1;                 // No match found
    }
}
