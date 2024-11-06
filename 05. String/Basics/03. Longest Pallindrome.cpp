#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: 
// We are given a string that may contain both lowercase and uppercase letters. 
// The task is to find the longest possible palindrome that can be constructed from the string 
// by rearranging the characters. A palindrome reads the same forward and backward.

// Approach:
// - First, count the occurrences of each letter (separately for lowercase and uppercase).
// - Then, to build the longest palindrome:
//   - For each letter, if its count is even, it can be fully used to form the palindrome.
//   - If its count is odd, we can use its largest even part, and one occurrence can be placed 
//     in the middle of the palindrome (if any odd counts exist).
// - The string is then divided into two halves and the second half is the reverse of the first.
// - If there is an odd occurrence letter, it is placed in the center.

// Time Complexity: O(n), where n is the length of the input string.
// Space Complexity: O(1), since we are using fixed-size vectors for the counts of characters (constant space).

// Function to calculate the longest palindrome length
void find_count_pallindrome(vector<int> lower, vector<int> upper) {
    // This function computes the count of the longest possible palindrome.
    int count = 0; // To keep track of total length of characters used in the palindrome.
    bool odd = 0;  // A flag to check if we have any odd count character.

    // Loop over the lowercase and uppercase alphabets (26 each)
    for (int i = 0; i < 26; i++) {
        // For lowercase letters
        if (lower[i] % 2 == 0) {
            count += lower[i]; // Even counts can be fully used in the palindrome.
        } else {
            count += lower[i] - 1; // Use the largest even part.
            odd = 1; // Set odd flag because we can place one odd letter in the center.
        }

        // For uppercase letters
        if (upper[i] % 2 == 0) {
            count += upper[i]; // Even counts can be fully used in the palindrome.
        } else {
            count += upper[i] - 1; // Use the largest even part.
            odd = 1; // Set odd flag for the center placement.
        }
    }
    
    // If we have an odd letter, add 1 for the center position.
    cout << count + odd << endl;
}

// Function to generate the longest possible palindrome string
void find_possible_pallindrome(vector<int> lower, vector<int> upper) {
    // This function creates the longest possible palindrome using available letters.
    string left; // Left half of the palindrome.
    string right; // Right half will be the reverse of the left half.
    char odd_word = '\0'; // Store the letter that has an odd occurrence.

    // Loop over lowercase and uppercase alphabets
    for (int i = 0; i < 26; i++) {
        // Process lowercase letters
        if (lower[i] % 2 != 0) {
            odd_word = char(i + 'a'); // Store the odd occurrence letter.
        }
        if (lower[i]) {
            int temp = lower[i] / 2; // Use half of the count for the left side.
            while (temp--) {
                left += char(i + 'a'); // Append the character to the left half.
            }
        }

        // Process uppercase letters
        if (upper[i] % 2 != 0) {
            odd_word = char(i + 'A'); // Store the odd occurrence letter.
        }
        if (upper[i]) {
            int temp = upper[i] / 2; // Use half of the count for the left side.
            while (temp--) {
                left += char(i + 'A'); // Append the character to the left half.
            }
        }
    }

    // The right half is the reverse of the left half.
    right = left;
    reverse(right.begin(), right.end());

    // If there is an odd occurrence letter, place it in the middle.
    if (odd_word != '\0') {
        left += odd_word;
    }

    // Print the complete palindrome.
    cout << left + right << endl;
}

int main() {
    // Input string containing both lowercase and uppercase letters.
    string s = "aaaAAbdc";

    // Vectors to store the frequency of lowercase and uppercase letters.
    vector<int> lower(26, 0), upper(26, 0);

    // Count the occurrence of each letter in the input string.
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a') {
            // For lowercase letters, increase the count in the 'lower' array.
            lower[s[i] - 'a']++;
        } else {
            // For uppercase letters, increase the count in the 'upper' array.
            upper[s[i] - 'A']++;
        }
    }

    // Call the function to find the count of the longest possible palindrome.
    find_count_pallindrome(lower, upper);

    // Call the function to generate and print the longest possible palindrome.
    find_possible_pallindrome(lower, upper);
}
