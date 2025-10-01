#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
--------------------------------------------------------------------------------
Problem Statement:
Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

You are given a string of parentheses '(' and ')'.  
You have to find the **minimum number of parentheses** you must add 
to make the string valid. A string is valid if:
- Every '(' has a corresponding ')'
- Every ')' has a corresponding '(' before it

Example:
Input:  str = "((((()))(()"
Output: 2

--------------------------------------------------------------------------------
Time Complexity:
O(n), where n = length of the input string.
- We traverse each character exactly once.

Space Complexity:
O(n), in the worst case.
- We use a stack that can grow up to n elements if all characters are '('.

--------------------------------------------------------------------------------
Approach (Step-by-Step):

1. Initialize a stack to keep track of unmatched '(' parentheses.
2. Initialize a counter (count) to track unmatched ')' parentheses.

3. Traverse the string character by character:
    a) If the character is ')':
        - If the stack is empty (no unmatched '(' to match with), 
          increment the count (means we need one '(' to match it).
        - Otherwise, pop one '(' from the stack (they form a valid pair).
    b) If the character is '(', push it into the stack (waiting for a match).

4. After the loop ends:
    - The stack contains unmatched '(' parentheses.
    - The count variable contains unmatched ')' parentheses.

5. The total number of parentheses needed to make the string valid =
   unmatched '(' + unmatched ')'

6. Print the result.

--------------------------------------------------------------------------------
Visual Explanation (Diagram):

Let's say str = "((((()))(()"

Step-by-step:
- Character '(': push into stack -> Stack: (
- Character '(': push into stack -> Stack: ((
- Character '(': push into stack -> Stack: (((
- Character '(': push into stack -> Stack: ((((
- Character ')': pop from stack  -> Stack: (((   (matched one pair)
- Character ')': pop from stack  -> Stack: ((    (matched one pair)
- Character ')': pop from stack  -> Stack: (     (matched one pair)
- Character ')': pop from stack  -> Stack:       (matched one pair)
- Character '(': push into stack -> Stack: (
- Character '(': push into stack -> Stack: ((
- Character ')': pop from stack  -> Stack: (     (matched one pair)

At the end:
- Stack has 1 '(' remaining (unmatched).
- Count = 0 (no unmatched ')').

So, total = 1 (unmatched '(') + 0 (unmatched ')') = 1  
=> Output: 1

But in your example `str = "((((()))(())"`, let’s dry run it:

Characters:
- ( -> stack: (
- ( -> stack: ((
- ( -> stack: (((
- ( -> stack: ((((
- ) -> pop -> (((
- ) -> pop -> ((
- ) -> pop -> (
- ( -> push -> ((
- ( -> push -> (((
- ) -> pop -> ((
- ) -> pop -> (

At the end:
- Stack: (  
- Count: 0

Thus, count + st.size() = 1

Output: 1

--------------------------------------------------------------------------------
*/

// Code starts here
int main(){
    string str = "((((()))(())"; // Given input string

    stack<char>st; // Stack to keep track of unmatched '(' characters
    int count = 0; // Counter to keep track of unmatched ')' characters

    for (int i=0; i<str.size(); i++){
        if(str[i] == ')'){          // If we find a closing parenthesis ')'
            if(st.empty()){         // If stack is empty, no '(' available to match
                count++;            // Increase count (we need one '(' to match this ')')
            }else {
                st.pop();           // Otherwise, pop one '(' from stack (they form a pair)
            }
        }else{                      // If we find an opening parenthesis '('
            st.push(str[i]);         // Push it into the stack (waiting for future ')')
        }
    }

    // After processing the string,
    // stack.size() = number of unmatched '('
    // count = number of unmatched ')'
    count += st.size(); // Total insertions needed = unmatched '(' + unmatched ')'
    
    cout<<count; // Output the result
}
