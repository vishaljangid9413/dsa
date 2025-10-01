#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given two strings, `s` and `sub`, where `s` is shorter than `sub`, determine the minimum 
// number of times we need to repeat `s` so that `sub` becomes a substring of the repeated `s`. 
// If `sub` cannot be a substring of any number of repetitions of `s`, output -1.

// Approach:
// - We repeatedly concatenate `s` with itself until its length is at least as long as `sub`. 
//   This gives us a candidate for a string that might contain `sub` as a substring.
// - We use the KMP (Knuth-Morris-Pratt) algorithm to check if `sub` is a substring within the 
//   repeated `s`.
// - If `sub` is not found after the initial repetitions, we check one more repetition of `s` 
//   to ensure all cases are covered (e.g., `sub` might partially overlap at the end of one 
//   repetition and the beginning of the next).
// - If `sub` is found, we return the number of repetitions. If not, we return -1.

// Time Complexity: O(m + n), where `m` is the size of `sub` and `n` is the cumulative length 
// of the repeated string `s`. This includes building the LPS array and running KMP on the repeated string.

// Space Complexity: O(m), for the LPS array storage.

bool KMP_MATCH(string s, string sub) {
    vector<int> lps(sub.size(), 0);  // LPS array for `sub`, initialized to zero

    // Step 1: Construct the LPS array for `sub`
    int first = 0, second = 1;
    while (second < sub.size()) {
        if (sub[first] == sub[second]) {
            lps[second] = first + 1;
            first++;
            second++;
        } else {
            if (first == 0) {
                second++;
            } else {
                first = lps[first - 1];
            }
        }
    }

    // Step 2: Use KMP to check if `sub` is a substring of `s`
    first = 0; 
    second = 0; // Reset pointers for matching `sub` in `s`
    while (first < s.size() && second < sub.size()) {
        if (s[first] == sub[second]) {
            first++;
            second++;
        } else {
            if (second == 0) {
                first++;
            } else {
                second = lps[second - 1];
            }
        }
    }

    // If `second` reaches the length of `sub`, `sub` is found in `s`
    return (second == sub.size());
}

int main() {
    string s = "abcd";       // Main string to be repeated
    string sub = "cdabcdab";  // Target substring

    // Check for the trivial case where `s` is equal to `sub`
    if (s == sub) {
        cout << 1;
        return 1;
    }

    int repeat = 1;          // Initial count of repetitions
    string temp = s;         // Temp string to hold repeated versions of `s`

    // Step 1: Repeat `s` until `temp` is at least as long as `sub`
    while (temp.size() < sub.size()) {
        temp += s;
        repeat++;
    }

    // Step 2: Check if `sub` is a substring of the current `temp`
    if (KMP_MATCH(temp, sub)) {
        cout << repeat;      // Output the number of repetitions needed
        return repeat;
    }

    // Step 3: Check with one more repetition of `s` to cover edge cases
    if (KMP_MATCH(temp += s, sub)) {
        cout << repeat + 1;
        return repeat + 1;
    }

    // If `sub` is not found after all repetitions, return -1
    cout << -1;
}
