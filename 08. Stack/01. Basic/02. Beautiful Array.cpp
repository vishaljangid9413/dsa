#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem:
---------
Remove all the adjacent positive and negative elements from an array.
If two adjacent elements have opposite signs (positive and negative), they "cancel" each other out (i.e., they are removed).
The final array should not have any such adjacent opposite-sign elements.

Problem Link:
--------------
https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1

Time Complexity:
-----------------
O(n), where n = number of elements in the array.
- We traverse the array exactly once, and stack operations (push/pop/top) are O(1).

Space Complexity:
------------------
O(n) in the worst case, when no elements cancel out and all elements are stored in the stack.

Step-by-Step Approach:
-----------------------
1. Create an empty stack to help manage adjacent element comparisons.
2. Traverse each element of the array:
    - If the stack is empty, simply push the current element.
    - If the current element is negative:
        - If the top of the stack is also negative, push the current element.
        - If the top of the stack is positive, pop the top element (they cancel out).
    - If the current element is positive:
        - If the top of the stack is also positive, push the current element.
        - If the top of the stack is negative, pop the top element (they cancel out).
3. After the entire array is traversed, the stack will have the final "beautiful" array elements.
4. Finally, print the elements of the stack.

Diagram (Example Walkthrough):
-------------------------------
Input array: [2, 3, 5, -4, 6, -2, -8, 9]

Initial stack: empty

Step-by-step:
- 2 → Stack empty → Push 2 → Stack: [2]
- 3 → 2 is positive, 3 is positive → Push 3 → Stack: [2, 3]
- 5 → 3 is positive, 5 is positive → Push 5 → Stack: [2, 3, 5]
- -4 → 5 is positive, -4 is negative → Pop 5 → Stack: [2, 3]
- 6 → 3 is positive, 6 is positive → Push 6 → Stack: [2, 3, 6]
- -2 → 6 is positive, -2 is negative → Pop 6 → Stack: [2, 3]
- -8 → 3 is positive, -8 is negative → Pop 3 → Stack: [2]
- 9 → 2 is positive, 9 is positive → Push 9 → Stack: [2, 9]

Final stack (printed from top to bottom): 9 2

Notes:
------
- A positive and negative number cancel each other if they are adjacent (by stack behavior).
- Same signs don't cancel out; they stay together.

*/

// Utility function to print the stack elements
void print(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    int arr[] = {2,3,5,-4,6,-2,-8,9}; // Input array
    int n = size(arr);                // Size of the array
    stack<int> st;                    // Stack to maintain elements after cancellation logic

    for (int i = 0; i < n; i++){
        if (st.empty()){
            // If the stack is empty, push the current element
            st.push(arr[i]);
        } else if (arr[i] < 0){
            if (st.top() < 0){
                // If both current and top are negative, push current
                st.push(arr[i]);
            } else {
                // If current is negative and top is positive, pop the top (they cancel out)
                st.pop();
            }
        } else if (arr[i] >= 0){
            if (st.top() >= 0){
                // If both current and top are positive, push current
                st.push(arr[i]);
            } else {
                // If current is positive and top is negative, pop the top (they cancel out)
                st.pop();
            }
        }
    }

    // Print final elements in stack after processing
    print(st);
}
