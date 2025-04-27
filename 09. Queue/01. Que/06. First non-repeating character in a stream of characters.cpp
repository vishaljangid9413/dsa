#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem: First Non-Repeating Character in a Stream of Characters
Link: https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

Time Complexity: O(n)
- The time complexity is O(n), where n is the length of the input string `A`. 
- This is because each character in the input string is processed once, and each operation in the queue (push and pop) is O(1).

Space Complexity: O(26) = O(1)
- The space complexity is O(26) because we are using a fixed-size array `repeated` of size 26 to store counts of characters (for the 26 lowercase letters). The queue `q` holds at most 26 characters at any time.

Step-by-Step Approach:
1. Initialize an array `repeated` of size 26 to keep track of how many times each character appears in the stream.
2. Use a queue `q` to store characters as they are encountered, but only store the first occurrence of non-repeating characters.
3. For each character in the string:
   - Increment the count of that character in `repeated`.
   - If the character appears for the first time, push it onto the queue `q`.
   - If the current character is repeating (count > 1), remove any characters from the front of the queue that are repeating.
   - After updating the queue, append the first non-repeating character (if any) to the output string `B`. If no non-repeating character exists, append a `#`.
4. Print the result string `B` which contains the first non-repeating character at each step.

Explanation with Diagrams:
- At each step, the program processes the next character in the string `A`. It adds non-repeating characters to the queue and ensures that only the first non-repeating character is at the front of the queue.
- If there are no non-repeating characters, it appends `#` to the result.

Example:
For the string `A = "abcabdcad"`, we process the characters as follows:
- **a**: Non-repeating → Queue: [a] → Output: a
- **b**: Non-repeating → Queue: [a, b] → Output: ab
- **c**: Non-repeating → Queue: [a, b, c] → Output: abc
- **a**: Repeating → Queue: [b, c] → Output: bc
- **b**: Repeating → Queue: [c] → Output: c
- **d**: Non-repeating → Queue: [c, d] → Output: cd
- **c**: Repeating → Queue: [d] → Output: d
- **a**: Repeating → Queue: [d] → Output: d
- **d**: Repeating → Queue: [] → Output: #

Thus, the output string will be: `abc#c#d#`.

*/

int main(){
    string A = "abcabdcad";  // Input stream of characters
    string B;  // Result string to store the first non-repeating character at each step
    vector<int> repeated(26, 0);  // Array to store frequency of characters 'a' to 'z'
    queue<char> q;  // Queue to store non-repeating characters

    // Iterate over each character in the input string A
    for (int i = 0; i < A.size(); i++) {
        char element = A[i];  // Current character
        int index = A[i] - 'a';  // Convert character to index (0 for 'a', 1 for 'b', etc.)

        // Increase the count of the current character in the repeated array
        repeated[index]++;

        // If character is not repeating (it appears for the first time), add it to the queue
        if (repeated[index] == 1) {
            q.push(A[i]);
        }

        // Remove characters from the queue if they are repeating
        while (!q.empty() && repeated[index] > 1) {
            q.pop();
        }
        
        // If queue is empty, append '#' to the result (no non-repeating character found)
        // Otherwise, append the front character from the queue (the first non-repeating character)
        B += q.empty() ? '#' : q.front();
    }

    cout << B;  // Output the result string
}
