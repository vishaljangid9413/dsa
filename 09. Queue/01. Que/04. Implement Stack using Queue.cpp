#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem Statement:
This code is an implementation of a queue using two stacks. The challenge is to simulate the behavior of a queue (FIFO: First In First Out) using only two stacks, which are inherently LIFO (Last In First Out) structures.

Link to the problem: https://leetcode.com/problems/implement-queue-using-stacks/description/

Time Complexity:
- The `push` operation has O(1) time complexity since adding an element to a stack takes constant time.
- The `pop` operation has amortized O(1) time complexity, but it can be O(n) in the worst case when elements need to be moved between stacks. However, since each element is moved at most once, the average time complexity is O(1) over a series of `pop` operations.
- The `peek` operation has amortized O(1) time complexity. However, like `pop`, it can take O(n) in the worst case when elements need to be moved between stacks.

Space Complexity:
- The space complexity is O(n), where `n` is the number of elements in the queue, because we are using two stacks to store the elements.

Step-by-Step Approach:
1. **Queue Representation with Two Stacks**:
   - We use two stacks: `st1` and `st2`.
   - Stack `st1` is used to hold the incoming elements.
   - Stack `st2` is used to hold the elements in the correct order for output when we perform `pop` or `peek` operations.

2. **Push Operation**:
   - To add an element to the queue, we push the element onto `st1`.
   - This operation is always O(1), as it is simply adding to the stack.

3. **Pop Operation**:
   - If `st2` is empty, we transfer all elements from `st1` to `st2`. This reverses the order of elements so that the oldest element (the one that should be dequeued first) ends up at the top of `st2`.
   - After transferring, we pop the top of `st2`, which will be the oldest element in the queue.
   - If `st2` is not empty, we can directly pop from `st2`.

4. **Peek Operation**:
   - To get the front element of the queue, we check if `st2` is empty.
   - If `st2` is empty, we transfer all elements from `st1` to `st2`.
   - We then return the top of `st2` as the front of the queue.

5. **IsEmpty Operation**:
   - This operation checks if both stacks are empty. If both are empty, the queue is empty.

Explanation with Diagrams:

- Initial state:
  st1 = []
  st2 = []
  (Both stacks are empty)

- After pushing 5, 10, and 11:
  st1 = [5, 10, 11]
  st2 = []

- After popping an element:
  st1 = [10, 11]
  st2 = [5]  (Elements are transferred to st2 in reverse order)

- After pushing 10 again:
  st1 = [10, 10]
  st2 = [5, 11] 

- After popping an element:
  st1 = [10]
  st2 = [5]

- Peek operation will return the top of st2, which is 5.

*/

class Queue {
public:
    stack<int> st1;  // Stack 1 to hold the incoming elements
    stack<int> st2;  // Stack 2 to reverse the order of elements for output

    // Check if the queue is empty
    bool IsEmpty() {
        return st1.empty() && st2.empty();  // The queue is empty if both stacks are empty
    }

    // Peek operation: get the front element of the queue
    int peek() {
        if (IsEmpty()) {
            cout << "Queue is underflowed" << endl;  // If the queue is empty
            return -1;  // Return -1 to indicate the queue is empty
        } else if (st2.empty()) {
            // If st2 is empty, transfer elements from st1 to st2 to reverse the order
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();  // Return the top element of st2 as the front of the queue
    }

    // Push operation: add an element to the queue
    void push(int x) {
        st1.push(x);  // Push the element onto st1
        cout << "Pushed " << x << endl;  // Output the pushed element
    }

    // Pop operation: remove the front element of the queue
    int pop() {
        if (st2.empty()) {
            // If st2 is empty, transfer all elements from st1 to st2
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (!st2.empty()) {
            int element = st2.top();  // Get the front element from st2
            cout << "Popped " << element << endl;  // Output the popped element
            st2.pop();  // Remove the element from st2
            return element;  // Return the popped element
        }

        cout << "Queue is underflowed" << endl;  // If both stacks are empty, the queue is underflowed
        return -1;  // Return -1 to indicate the queue is empty
    }
};

int main() {
    Queue q;  // Create a queue object
    q.push(5);  // Push 5 to the queue
    q.push(10); // Push 10 to the queue
    q.push(11); // Push 11 to the queue
    q.pop();    // Pop an element from the queue
    q.push(10); // Push 10 again to the queue
    q.pop();    // Pop another element from the queue
    cout << q.peek(); // Peek the front element of the queue
}
