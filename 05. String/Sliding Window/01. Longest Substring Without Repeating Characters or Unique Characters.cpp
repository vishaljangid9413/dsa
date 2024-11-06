#include <iostream>
#include <vector>
using namespace std;

// Problem:
// Find the length of the longest substring in a given string `s` 
// that contains only unique characters.

// Approach 1 (Sliding Window with Hash Map):
// The idea is to maintain a sliding window of unique characters.
// For each new character, if it's already in the window, 
// shift the starting point to the right of the previous occurrence of that character.
// Keep track of the maximum window length with unique characters.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since the size of the array is constant (255 characters).

void first_approach(string s, int n) {
    vector<int> arr(255, 0);  // Array to store the latest index of characters
    int start = 0, end = 0;
    int ans = 1;

    // Sliding window over the string
    while (end < n) {
        char c = s[end];
        // If the character is already in the window, move the start to the right
        if (arr[c] && start < arr[c]) {
            start = arr[c];
        }
        arr[c] = ++end;  // Update the position of the character
        ans = max(ans, end - start);  // Calculate the maximum length
    }
    cout << "First Approach Ans: " << ans << endl;
}

// Approach 2 (Sliding Window with Frequency Count):
// Here, we again use a sliding window, but instead of storing the last position of the character,
// we store whether the character is in the current window or not. If a duplicate is found, 
// shift the start pointer until the window is valid again (contains unique characters).

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since we are using a fixed-size array of 255 characters.

void second_approach(string s, int n) {
    vector<int> arr(255, 0);  // Array to mark whether the character is in the current window
    int start = 0, end = 0;
    int ans = 0;

    while (end < n) {
        char c = s[end];
        // If the current character is already in the window, move the start pointer
        while (arr[c]) {
            arr[s[start]] = 0;
            start++;
        }

        arr[c] = 1;  // Mark the character as present in the window
        end++;
        ans = max(ans, end - start);  // Update the maximum length of unique characters
    }
    cout << "Second Approach Ans: " << ans << endl;
}

int main() {
    string s = "abbannc";  // Input string
    int n = s.size();  // Size of the string

    first_approach(s, n);  // First approach to find the longest substring
    second_approach(s, n);  // Second approach to find the longest substring
}
