/*
    Question:
    Build N stacks using a single array of size S. 
    You are given an array that can hold data for multiple stacks. 
    Each stack can hold a maximum of `S / N` elements (approximately). 
    The objective is to implement a system where multiple stacks can coexist in a single array, and you can perform push and pop operations on them individually.

    Link: https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?leftPanelTabValue=PROBLEM

    Time Complexity: 
    - The time complexity for the `push()` and `pop()` operations is O(1) for each operation, because we are using stack operations and linked list manipulations that take constant time.

    Space Complexity: 
    - The space complexity is O(S + N) where:
        - S is the total size of the array `arr` that stores the elements for all stacks.
        - N is the number of stacks. Each stack has a pointer to the top element in the array, so the space for the `top` array is proportional to N.

    Detailed Step-by-Step Approach:
    1. **Data Structure Initialization:**
        - We have an array of size `S` where the actual elements of the stacks are stored.
        - We have `N` stacks, and the `top` array of size `N` is used to keep track of the top elements of each stack.
        - We initialize a `stack<int>` to hold the available indexes in the array `arr`, which will be used to assign new elements.

    2. **Push Operation (Push X to Stack M):**
        - Before pushing an element to the Mth stack, we check if there are any available slots left by checking the `st` stack.
        - If the stack `st` is empty, it means we cannot push any more elements to any stack, and we return `false`.
        - If there is an available index, we take the index from the top of `st`, place the value `X` at that index in the `arr` array, and update the top of the Mth stack to point to the newly pushed element.
        - We then pop the index from `st` to mark it as used.

    3. **Pop Operation (Pop from Stack M):**
        - To pop an element from the Mth stack, we first check if the stack is empty by checking if the `top[m-1]` pointer is `NULL`.
        - If the stack is empty, we return `-1` to indicate that there's no element to pop.
        - If the stack is not empty, we retrieve the index of the top element from the `top` pointer, push it back to the `st` stack to mark it as available for future use, and then update the `top` pointer to point to the next element in the Mth stack.

    4. **Final State:**
        - After performing multiple push and pop operations, the `arr` array holds the values for all stacks, and the `top` array keeps track of the top elements for each stack.

    Explanation with Diagrams:
    Here’s a visual representation of how the stacks are managed:

    Suppose we have:
    - N = 3 (3 stacks)
    - S = 9 (Array size is 9)

    The array `arr` will hold all the elements for all stacks:
    ```
    arr = [5, 3, 8, 2, 7, 1, 4, 6, 9]
    ```

    Initially, the `top` pointers for the 3 stacks are NULL:
    ```
    top[0] = NULL  (Stack 1)
    top[1] = NULL  (Stack 2)
    top[2] = NULL  (Stack 3)
    ```

    After performing a few `push` operations, the `arr` array is populated, and the `top` pointers are updated:
    - Push 5 to Stack 1: `arr[0] = 5`, `top[0] = 0`
    - Push 3 to Stack 1: `arr[1] = 3`, `top[0] = 1`
    - Push 8 to Stack 2: `arr[2] = 8`, `top[1] = 2`

    Now, the state is:
    ```
    arr = [5, 3, 8, 2, 7, 1, 4, 6, 9]
    top[0] = 1  (Stack 1 points to index 1, which holds 3)
    top[1] = 2  (Stack 2 points to index 2, which holds 8)
    top[2] = NULL  (Stack 3 is empty)
    ```

    After a `pop` operation on Stack 1:
    - The top of Stack 1 is at index 1, so we pop the element 3, push index 1 back to `st`, and update `top[0]` to point to the next element (index 0).

    The new state is:
    ```
    arr = [5, 3, 8, 2, 7, 1, 4, 6, 9]
    top[0] = 0  (Stack 1 now points to index 0, which holds 5)
    top[1] = 2  (Stack 2 still points to index 2, which holds 8)
    top[2] = NULL  (Stack 3 is still empty)
    st = {1} (index 1 is available now)
    ```

    The above diagrams demonstrate how the stacks share the same array but are managed through the `top` pointers.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{
    public:
    int index;
    Node *next;

    Node(int x){
        index = x;
        next = NULL;
    }
};

class NStack
{
public:
    stack<int>st;
    int *arr;
    Node **top;

    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new Node*[N];
        // Added null to each ll head
        for (int i=0;i<N;i++){
            top[i] = NULL;     
        }

        // push available indexes into stack
        for(int i=0;i<S;i++){
            st.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (st.empty()){
            return false;
        }
        // add value in arr 
        arr[st.top()] = x;
        Node *element = new Node(st.top());
        element->next = top[m-1];
        top[m-1] = element;
        st.pop();
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m - 1] == NULL){
            return -1;
        }
        st.push(top[m - 1]->index);
        int element = arr[top[m - 1]->index];
        top[m - 1] = top[m - 1]->next;
        return element;

    }
};
