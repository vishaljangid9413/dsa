#include <iostream>
#include <vector>
using namespace std;

// Problem:
// We are given a sentence where each word is followed by a number (1 <= number <= 9).
// The task is to sort the sentence such that the words are ordered based on the number
// attached to each word. After sorting, we need to return the sentence without the numbers.

// Approach:
// - Traverse through the string and extract each word, including the number at the end.
// - Use the number to determine the correct position of the word in a temporary vector.
// - Finally, reconstruct the sorted sentence by appending words from the vector in the correct order.

// Time Complexity: O(n), where n is the length of the input string, as we are traversing the string once.
// Space Complexity: O(1), since the space used is proportional to the size of the input, which is bounded (9 words at most).

int main(){
    string st = "is2 sentence4 this1 a3";  // Input sentence with words followed by numbers.
    string ans;                            // Temporary string to hold the word being processed.
    vector<string> sub(10);                // Vector to store words based on their position number.
    int count = 0;                         // To track the number of words in the sentence.

    // Add an empty space at the end of the string to simplify word extraction.
    st += ' ';

    // Traverse the string to extract words and place them at the correct index in 'sub' vector.
    for (int i = 0; i <= st.size(); i++){
        if(st[i] == ' '){  // If space is encountered, a word has ended.
            ans.pop_back();  // Remove the number from the word.
            int index = st[i-1] - '0';  // Extract the position number from the word.
            sub[index] = ans;  // Store the word in the correct position.
            ans.clear();  // Clear the word buffer to process the next word.
            count++;  // Increment the count of words.
        } else {
            ans += st[i];  // Keep building the current word.
        }
    }

    // Now reconstruct the sorted sentence using the words stored in the 'sub' vector.
    for(int i = 1; i <= count; i++){
        ans += sub[i] + ' ';  // Append each word followed by a space.
    }
    ans.pop_back();  // Remove the last space from the final sentence.
    
    cout << ans;  // Output the final sorted sentence.
}
