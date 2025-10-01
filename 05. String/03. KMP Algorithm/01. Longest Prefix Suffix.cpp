#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement the Knuth-Morris-Pratt (KMP) pattern matching algorithm to find the 
// length of the longest prefix which is also a suffix in a given string `s`. 
// For example, in the string "abacab", the longest prefix which is also a suffix 
// is "ab", which has a length of 2.

// Approach:
// - The KMP algorithm is based on constructing a Longest Prefix Suffix (LPS) array. 
//   The LPS array stores the length of the longest proper prefix of the substring `s[0...i]` 
//   which is also a suffix of `s[0...i]`.
// - We initialize two pointers: `start` and `end`. The `start` pointer marks the beginning 
//   of the current prefix, and the `end` pointer scans through the string.
// - If `s[start]` matches `s[end]`, it indicates the current prefix is also a suffix, so 
//   we set `lps[end] = start + 1` and move both pointers forward.
// - If there's a mismatch, we check if `start` is zero. If so, we simply move `end` forward. 
//   Otherwise, we set `start` to `lps[start - 1]`, essentially using previously computed 
//   values to avoid redundant checks.
// - The result is stored in the last element of the LPS array, which provides the length 
//   of the longest prefix which is also a suffix.

// Time Complexity: O(n), where `n` is the length of the string `s`.
// - Each character is processed at most twice, making this an efficient algorithm.

// Space Complexity: O(n), as we use an LPS array to store values for each character in the string `s`.

int main(){
    string s = "abacab";  // Input string
    int n = s.size();  // Length of the string
    vector<int> lps(n, 0);  // LPS array initialized to zero for each character in `s`
    int start = 0, end = 1;  // Initial pointers for traversing the string

    // Building the LPS array
    while (end < n) {
        if (s[start] == s[end]) {
            // If characters match, update the LPS value for `end` index
            lps[end] = start + 1;
            start++;
            end++;
        } else {
            // If there's a mismatch
            if (start == 0) {
                // If start is zero, simply move the end pointer forward
                end++;
            } else {
                // Use the value from the LPS array to avoid redundant comparisons
                start = lps[start - 1];
            }
        }
    }

    // Output the length of the longest prefix which is also a suffix
    cout << lps[n - 1];
}
