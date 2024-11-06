#include <iostream>
using namespace std;

// Time Complexity: O(n + 26) -> O(n), where n is the length of the input string
// Space Complexity: O(1), constant space since we use a fixed-size array (26)

int main() {
    string st = "gfkiclwma"; // Input string
    int arr[26] = {0}; // Array to store the frequency of each character
    string ans; // To store the result string in alphabetical order

    // Step 1: Count the occurrences of each character in the string.
    for (int i = 0; i < st.size(); i++) {
        arr[st[i] - 'a']++; // Increment the corresponding index for each character.
    }

    // Step 2: Rebuild the string in alphabetical order based on the frequency.
    for (int i = 0; i < size(arr); i++) {
        char c = i + 'a'; // Convert the index back to the corresponding character.
        while (arr[i] > 0) { // Append the character as many times as its count.
            ans += c;
            arr[i]--; // Decrease the count after adding the character to the result.
        }
    }

    // Step 3: Output the sorted string.
    cout << ans << endl; // The string will be in alphabetical order.
}
