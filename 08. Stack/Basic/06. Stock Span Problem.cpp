#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
-------------------------------------------
QUESTION:
-------------------------------------------
Given an array, for each element, find the total number of continuous smaller elements to its left (including itself).  
In other words, for each element, we want to know how many consecutive elements including itself are smaller on the left side.

Input: arr[] = {100, 80, 55, 70, 60, 75, 85}  
Output: 1 1 1 2 1 4 6

-------------------------------------------
TIME COMPLEXITY:
-------------------------------------------
- O(N), where N = number of elements in the array.
  - Each element is pushed and popped from the stack exactly once.

-------------------------------------------
SPACE COMPLEXITY:
-------------------------------------------
- O(N), where N = number of elements.
  - Because we use a stack and an answer array of size N.

-------------------------------------------
STEP-BY-STEP APPROACH:
-------------------------------------------

1. We initialize an empty stack 'st' to keep indexes of elements.
2. We start iterating the array **from the end (right to left)**.
3. For each element:
   - While the stack is **not empty** and the **current element** is **greater** than the element at the top index of the stack:
     - It means we have found the **next bigger element on the left** for the element at stack top.
     - So, the number of smaller elements for the element at 'st.top()' = (st.top() - current index i).
     - We set that value in the ans array.
     - Pop the top index from the stack.
4. After checking and updating, we **push the current index** into the stack.
5. After the main loop, there may still be some elements left in the stack.
   - For these elements, there is no bigger element to their left.
   - So, the count = (index + 1) (because they can only count up to themselves).

6. Finally, we print the 'ans' array.

-------------------------------------------
DIAGRAM EXPLANATION:
-------------------------------------------

Let's see how this works step by step:

arr = {100, 80, 55, 70, 60, 75, 85}

We move **from right to left**:

- i = 6 (85):
  - Stack empty, push(6)

- i = 5 (75):
  - 75 < arr[6] (85), so push(5)

- i = 4 (60):
  - 60 < arr[5] (75), so push(4)

- i = 3 (70):
  - 70 > arr[4] (60)
    - ans[4] = 4 - 3 = 1
    - pop(4)
  - 70 < arr[5] (75), so push(3)

- i = 2 (55):
  - 55 < arr[3] (70), so push(2)

- i = 1 (80):
  - 80 > arr[2] (55)
    - ans[2] = 2 - 1 = 1
    - pop(2)
  - 80 > arr[3] (70)
    - ans[3] = 3 - 1 = 2
    - pop(3)
  - 80 > arr[5] (75)
    - ans[5] = 5 - 1 = 4
    - pop(5)
  - 80 < arr[6] (85), so push(1)

- i = 0 (100):
  - 100 > arr[1] (80)
    - ans[1] = 1 - 0 = 1
    - pop(1)
  - 100 > arr[6] (85)
    - ans[6] = 6 - 0 = 6
    - pop(6)
  - Stack empty, push(0)

After main loop:
- Stack has index 0
- ans[0] = 0 + 1 = 1
- pop(0)

Final ans = {1, 1, 1, 2, 1, 4, 6}

-------------------------------------------
CODE WITH COMMENTS:
-------------------------------------------
*/

int main(){
    int arr[] = {100,80,55,70,60,75,85}; // Given array
    int n = size(arr); // Find size of the array
    vector<int>ans(n); // Answer array to store the number of smaller elements to the left
    stack<int>st; // Stack to store indexes

    // Traverse the array from right to left
    for(int i=n-1;i>=0;i--){
        // Check if current element is greater than elements at top of stack
        while(!st.empty() && arr[i] > arr[st.top()]){
            // If yes, update ans for the element at st.top()
            ans[st.top()] = st.top() - i;
            st.pop(); // Remove the element because we found the next greater element on left
        }
        st.push(i); // Push current index into stack
    }

    // For remaining elements in stack (no greater element on left)
    while(!st.empty()){
        ans[st.top()] = st.top() + 1; // All elements till the start including itself are smaller
        st.pop();
    }

    // Output the answer
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
