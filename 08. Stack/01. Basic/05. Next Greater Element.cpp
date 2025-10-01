/*
---------------------------------------------------------------------------------
QUESTION:
Given an array of integers, for each element, find the next greater element
to its right in the array. If no such element exists, output -1 for that element.

Example:
Input:  [8,6,4,7,4,9,10,8,12]
Output: [9,7,7,9,9,10,12,12,-1]

---------------------------------------------------------------------------------
TIME COMPLEXITY:
O(N), where N is the number of elements in the array.

SPACE COMPLEXITY:
O(N), for storing the output array and the stack.

---------------------------------------------------------------------------------
STEP-BY-STEP APPROACH:

1. Initialize an empty stack to keep track of indices of elements.
2. Initialize an answer array "ans" filled with -1 initially, meaning "no greater element yet".
3. Loop through the array from left to right:
    - While the stack is not empty and the current element is greater than the element at the index stored at the top of the stack:
        - Set ans[st.top()] = current element (arr[i]).
        - Pop the index from the stack (since we have now found the next greater element for that index).
    - Push the current index into the stack.
4. After the loop ends, any index remaining in the stack did not find a greater element, so they stay -1.

---------------------------------------------------------------------------------
VISUAL DIAGRAM EXPLANATION:

Let's take a small part of the input to visualize:

Input: [8,6,4,7,...]

Initially:
Stack: empty
Answer: [-1, -1, -1, -1, ...]

Step 1:
i = 0, arr[i] = 8
- Stack is empty.
- Push index 0 onto the stack.
Stack: [0]

Step 2:
i = 1, arr[i] = 6
- 6 is smaller than 8 (arr[stack.top()]), so no popping.
- Push index 1 onto the stack.
Stack: [0, 1]

Step 3:
i = 2, arr[i] = 4
- 4 is smaller than 6 (arr[stack.top()]), no popping.
- Push index 2 onto the stack.
Stack: [0, 1, 2]

Step 4:
i = 3, arr[i] = 7
- 7 > 4 (arr[2]), so:
  - ans[2] = 7
  - Pop 2.
- 7 > 6 (arr[1]), so:
  - ans[1] = 7
  - Pop 1.
- 7 < 8 (arr[0]), so no more popping.
- Push index 3 onto the stack.
Stack: [0, 3]

And so on...

At the end:
- If anything remains in the stack, it means no greater element was found for those indices.

---------------------------------------------------------------------------------
CODE WITH DETAILED COMMENTS:
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    // Input array
    int arr[] = {8,6,4,7,4,9,10,8,12};
    
    // Finding the size of the array
    int n = size(arr);
    
    // Output array, initialized with -1 meaning "no next greater element found yet"
    vector<int>ans(n, -1);
    
    // Stack to keep the indices of the elements
    stack<int>st;

    // Loop over each element in the array
    for(int i = 0; i < n; i++) {
        // While stack is not empty and the current element is greater than
        // the element corresponding to the index at the top of the stack
        while(!st.empty() && arr[st.top()] < arr[i]) {
            // Current element is the next greater element for arr[st.top()]
            ans[st.top()] = arr[i];
            // Pop the index from the stack as its next greater element is found
            st.pop();
        }
        // Push the current index onto the stack
        st.push(i);
    }

    // Print the answer array
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
