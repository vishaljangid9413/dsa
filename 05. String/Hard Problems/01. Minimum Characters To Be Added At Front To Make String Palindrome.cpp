#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem Statement:
// Given a string `s`, find the minimum number of characters that need to be 
// added at the beginning of `s` to make it a palindrome. A palindrome is a 
// string that reads the same forward and backward. For example, for `s = "ROORSP"`, 
// we want to add characters at the start to make it a palindrome.

// Approach:
// - To solve this problem, we use the KMP (Knuth-Morris-Pratt) algorithm, 
//   specifically focusing on finding the Longest Prefix Suffix (LPS) array 
//   for the string `s + '$' + reverse(s)`.
// - Step 1: Concatenate the string `s` with a special character '$' (to avoid 
//   overlapping) and then with its reverse. This combined string helps us 
//   determine the longest prefix of `s` which is also a suffix when checking 
//   for palindromic properties.
// - Step 2: Construct the LPS array for this combined string. The LPS value 
//   at the last position in the array indicates the longest prefix of `s` 
//   that is also a suffix in the combined string.
// - Step 3: Subtract this LPS value from the length of the original string to 
//   get the minimum number of characters to add. We also print these characters 
//   in reverse order since they need to be added at the beginning of the original 
//   string to form a palindrome.

// Time Complexity: O(n), where `n` is the length of the combined string `s + '$' + reverse(s)`.
// - Each character is processed at most twice due to the KMP algorithm's efficiency.

// Space Complexity: O(n), for the LPS array to store the prefix-suffix lengths.

int main(){
    string s = "ROORSP";       // Original string
    string temp = s;            // Store original string for final output
    int size = s.size();        // Length of the original string

    // Step 1: Reverse the string `s` and concatenate it with the original string and a special character `$`
    string rev = s;             
    reverse(rev.begin(), rev.end());  // Reverse the original string
    s += '$';                    // Add a special character to separate original and reversed string
    s += rev;                    // Concatenate reversed string
    int n = s.size();            // Length of the combined string

    // Step 2: Compute the LPS array for the combined string
    vector<int> lps(n, 0);       // LPS array initialized to zero
    int start = 0, end = 1;      // Pointers for LPS construction
    while (end < n) {
        if (s[start] == s[end]) {
            // If characters match, update the LPS value for `end` index
            lps[end] = start + 1;
            start++;
            end++;
        } else {
            // If there's a mismatch
            if (start == 0) {
                // If `start` is zero, simply move the `end` pointer forward
                end++;
            } else {
                // Use the LPS array to skip redundant checks
                start = lps[start - 1];
            }
        }
    }

    // Step 3: Calculate and output the number of characters to add
    cout << "Ans: " << size - lps[n - 1] << endl << "Characters: ";

    // Step 4: Output the characters to be added at the beginning to make `s` a palindrome
    for (int i = size - 1; i >= lps[n - 1]; i--) {
        cout << temp[i];
    }
}
