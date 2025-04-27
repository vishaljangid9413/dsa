// -----------------------------------------------------------------------------
// Problem Statement:
// Given a string consisting of parentheses '(' and ')' along with other characters,
// assign a unique counter number to each opening and closing parenthesis.
// 
// When encountering an opening '(', push a unique number onto a stack.
// When encountering a closing ')', pop the number from the stack and associate it with that ')'
// Output the sequence of numbers (for both '(' and ')') as per their order in the string.
//
// Example:
// Input:  "((aa(bdc))P((de)))"
// Output: 1123325544666
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Time Complexity: O(N)
//  - We traverse the string once, and each stack operation (push/pop) takes O(1).
//
// Space Complexity: O(N)
//  - Stack and vector may store up to N/2 elements for parentheses.
// -----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    string str = "((aa(bdc))P((de)))"; // The input string containing parentheses and characters
    vector<int>ans; // Vector to store the sequence of numbers associated with '(' and ')'
    stack<int>st;   // Stack to keep track of the numbers assigned to open parentheses
    int counter = 0; // Counter to assign a unique number to each '('

    // Step 1: Traverse the string
    for (int i=0; i<str.size(); i++){
        // Step 2: If current character is an opening parenthesis '('
        if(str[i] == '('){
            counter++;          // Increment counter to get a new unique number
            st.push(counter);   // Push the counter to the stack
            ans.push_back(counter); // Store the counter in ans for '('
        }
        // Step 3: If current character is a closing parenthesis ')'
        else if(str[i] == ')'){
            ans.push_back(st.top()); // Take the top number from the stack and add it to ans
            st.pop();                // Remove the number from the stack (because this '(' is now closed)
        }
        // Step 4: If it's any other character, we simply ignore it
    }
    
    // Step 5: Print the stored sequence
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]; // Output the sequence of numbers
    }
}
