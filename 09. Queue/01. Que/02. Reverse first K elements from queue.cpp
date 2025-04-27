#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*
Problem Statement:
This code implements the solution for the problem of reversing the first 'k' elements of a queue.
The challenge is to reverse the first 'k' elements of the queue while maintaining the order of the remaining elements.
Link to the problem: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions

Time Complexity:
- Pushing 'k' elements into the stack takes O(k) time.
- Popping 'k' elements from the queue and pushing them into the stack takes O(k) time.
- Pushing back the reversed elements from the stack into the queue takes O(k) time.
- Rotating the remaining n-k elements of the queue takes O(n-k) time, where n is the total number of elements in the queue.

Thus, the total time complexity is O(n), where n is the size of the queue.

Space Complexity:
- The space complexity is O(k) because we use a stack to store 'k' elements from the queue for reversal.

Step-by-Step Approach:
1. We first declare a stack `st` and a queue `q`.
2. We fill the stack with the first 'k' elements of the queue. This is done by repeatedly popping the front element of the queue and pushing it onto the stack.
3. After the stack contains the 'k' elements in reversed order, we push these elements back into the queue in reverse order.
4. Finally, we rotate the remaining elements of the queue (those that were not reversed) by pushing them from the front to the back. This ensures that the order of elements after the 'k' reversed elements is preserved.

Explanation with Diagrams:
Initially, the queue looks like this (for example with values 1, 2, 3, 4, 5):
    Front -> 1 -> 2 -> 3 -> 4 -> 5 <- Rear

Let's assume `k = 3` (we want to reverse the first 3 elements).

Step 1: Push the first 3 elements (1, 2, 3) into the stack.
    Stack: [3, 2, 1]
    Queue (remaining): 4 -> 5

Step 2: Push the reversed elements (3, 2, 1) back into the queue:
    Queue: 3 -> 2 -> 1 -> 4 -> 5

Step 3: Rotate the remaining elements (4, 5) to maintain their order:
    Queue: 3 -> 2 -> 1 -> 4 -> 5

Final result: The first 3 elements are reversed, and the rest remain unchanged.

Simple Explanation of the Code:
- The code uses a stack to reverse the first 'k' elements of the queue. 
- The stack helps in reversing the order of the first 'k' elements since stacks follow the Last-In-First-Out (LIFO) principle.
- After reversing the first 'k' elements, the remaining elements of the queue are rotated to maintain their order.

*/

// Required libraries for queue and stack
#include <queue>
#include <stack>

int main(){
    // Declare a queue and stack
    stack<int> st;
    queue<int> q;
    int k = 2;  // We want to reverse the first 'k' elements in the queue

    // Fill the queue with sample elements for demonstration
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Fill the stack with the first 'k' elements for reversal
    while(k--){
        st.push(q.front());  // Push the front element of the queue to the stack
        q.pop();  // Remove the front element from the queue
    }

    int n = q.size();  // Get the size of the remaining elements in the queue

    // Push the reversed elements from the stack back into the queue
    while(!st.empty()){
        q.push(st.top());  // Push the top element of the stack to the queue
        st.pop();  // Remove the top element from the stack
    }

    // Now, rotate the remaining elements of the queue to maintain their order
    while(n--){
        q.push(q.front());  // Push the front element to the back of the queue
        q.pop();  // Remove the front element from the queue
    }

    // Display the modified queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
