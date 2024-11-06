#include <iostream>
using namespace std;

// Problem: Check if a given sentence is a pangram.
// A pangram is a sentence that contains every letter of the alphabet at least once.

// Approach: 
// - We create an array of size 26 (one for each letter of the alphabet).
// - For each character in the string, if it's not a space, we calculate its position in the alphabet (by subtracting 'a') and increment the corresponding index in the array.
// - Finally, we check if all entries in the array are non-zero (indicating that all letters appeared in the string).

/*
Time Complexity: O(n)
- We traverse the string once (which has length 'n') to update the occurrence array.
- Then we perform a constant-time check of 26 elements, so the time complexity is dominated by the traversal of the string.

Space Complexity: O(1)
- We use an array of fixed size 26 to store the occurrences of letters, which is constant space usage regardless of the input size.
- The space complexity is thus O(1) because the size of the array does not grow with the size of the input.
*/


int main() {
    // Input string to check if it's a pangram.
    string st = "the quick brown fox jumps over the lazy dog";
    
    // Array to keep track of the occurrence of each letter (26 letters in total).
    int arr[26] = {0};

    // Traverse the string and update the occurrence array.
    for (int i = 0; i < st.size(); i++) {
        if (st[i] != ' ') {  // Skip spaces.
            int temp = st[i] - 'a';  // Calculate the index for each letter ('a' is at index 0).
            arr[temp]++;  // Increment the count for the letter.
        }
    }

    // Check if all letters from 'a' to 'z' are present in the string.
    for (int i = 0; i < size(arr); i++) {
        if (arr[i] == 0) {
            cout << "It's not a Pangram Sentence" << endl;
            return 0;  // Exit as soon as we find a missing letter.
        }   
    }

    // If no letter is missing, print that the sentence is a pangram.
    cout << "It's a Pangram Sentence" << endl;
}
