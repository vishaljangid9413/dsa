#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
--------------------------------------------------------------------------------
Problem:
Insert an element at the bottom of a stack.

Problem Link:
https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions

Given a stack and an element x, insert x at the bottom of the stack.

Example:
Input: Stack = [1,2,3,4,5], x = 7
Output: Stack = [7,1,2,3,4,5]

--------------------------------------------------------------------------------
Approach (Step-by-Step):

1. We first fill the given stack with the existing elements (from the array).
2. Then, we create a temporary stack to **reverse** the elements:
   - We pop elements from the original stack and push them into the temporary stack.
   - This way, the order of the elements becomes reversed.
3. Now, the original stack is empty.
4. We **push the new element `x`** into the original stack. Since the stack was empty,
   `x` will be at the bottom.
5. Finally, we move back all the elements from the temporary stack to the original stack,
   restoring the original order but now with `x` at the bottom.

--------------------------------------------------------------------------------
Time Complexity:
- O(N), where N = number of elements in the stack.
  (We push and pop every element exactly once.)

Space Complexity:
- O(N), because we use an additional temporary stack to hold all elements.

--------------------------------------------------------------------------------
Diagram (Visual Explanation):

Initial stack (`st`):
Top -> 5
       4
       3
       2
Bottom->1

Temporary stack (`temp`) during shifting:
Top -> 1
       2
       3
       4
Bottom->5

After inserting x = 7 into `st`:
Top -> 7

Moving elements back from `temp` to `st`:
Top -> 5
       4
       3
       2
       1
       7 (Bottom)

Final stack (`st`):
Top -> 5
       4
       3
       2
       1
Bottom->7

(Note: Since the topmost element is printed first, the output will look reversed.)

--------------------------------------------------------------------------------
*/

// Function to print the stack elements
void print(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";  // Print top element
        st.pop();             // Remove top element
    }
}

int main(){
    int x = 7; // The new element we want to insert at the bottom of the stack.

    stack<int> st; // Create an empty stack.

    // Fill the stack with existing elements from an array
    int arr[] = {1,2,3,4,5}; 
    int n = size(arr); // Get the size of the array.

    for (int i=0; i<n; i++){
        st.push(arr[i]); // Push each array element into the stack
    }
    
    // Shift all elements to a temporary stack
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top()); // Push the top element of 'st' into 'temp'
        st.pop();            // Remove the top element from 'st'
    }

    // Now the original stack is empty
    // Add the new element at the bottom
    st.push(x);

    // Refill the original stack from the temporary stack
    while(!temp.empty()){
        st.push(temp.top()); // Push back elements from temp to st
        temp.pop();          // Remove the top element from temp
    }

    // Print the final stack
    print(st);

}
