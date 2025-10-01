#include <iostream>
#include <vector>
using namespace std;

// Problem:
// Find the smallest window (substring) in a given string `s`
// that contains all the unique characters present in the string.
// The window can include duplicate characters but must contain 
// all unique characters at least once.

// Approach (Sliding Window + Two Pointers):
// 1. First, we determine the total number of unique characters in the string.
// 2. Then, using two pointers (first and second), we find the smallest window that contains
//    all unique characters at least once by sliding the window over the string.
// 3. The second pointer is used to expand the window, and the first pointer is used to shrink it
//    when all unique characters are covered. At each step, we update the minimum window length.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), as the size of the array `count` is constant (256 characters).

int main() {
    string s = "AABBBCBBAAC";  // Input string
    vector<int> count(256, 0);  // Array to store the frequency of characters in the current window
    int first = 0, second = 0, unique = 0;  // Pointers and counter for unique characters
    int n = s.size();  // Length of the string
    int ans = n;  // Initialize answer with maximum possible window length (the whole string)

    // Step 1: Find the total number of unique characters in the string
    while (first < n) {
        if (count[s[first]] == 0) {
            unique++;
        }
        count[s[first++]]++;
    }

    // Reset pointers and clear the count array
    first = 0;
    fill(count.begin(), count.end(), 0);  // Clear the frequency count array

    // Step 2: Use two pointers to find the smallest window
    while (second < n) {
        // Expand the window by moving the second pointer until it contains all unique characters
        while (unique && second < n) {
            if (count[s[second]] == 0) {
                unique--;
            }
            count[s[second++]]++;
        }

        // Shrink the window from the left (using the first pointer) as long as it still contains all unique characters
        while (unique == 0) {
            // Shrink the window
            count[s[first]]--;
            if (count[s[first]] == 0) {
                unique++;  // If removing the character makes it incomplete, increment unique count
            }
            first++;
            // Update the minimum window length
            ans = min(ans, second - first + 1);
        }
    }

    cout << ans << endl;  // Output the length of the smallest window
}
