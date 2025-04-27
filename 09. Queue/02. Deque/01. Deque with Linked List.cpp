#include <iostream>
using namespace std;

/*
Problem: Creating a Double-Ended Queue (Deque) Using Doubly Linked List
- A deque (double-ended queue) allows insertion and deletion of elements from both ends (front and rear).
- This code implements a deque using a doubly linked list where each node has a pointer to both the next and previous node.

Time Complexity:
- push_front(x): O(1) - Insertion at the front of the deque is constant time.
- push_back(x): O(1) - Insertion at the rear of the deque is constant time.
- pop_front(): O(1) - Removal from the front of the deque is constant time.
- pop_back(): O(1) - Removal from the rear of the deque is constant time.
- start() and end(): O(1) - Accessing the front and rear elements of the deque are constant time operations.
- empty(): O(1) - Checking if the deque is empty is constant time.

Space Complexity: O(n)
- The space complexity is O(n), where n is the number of elements in the deque. Each element requires one node, and each node stores additional pointers (prev and next).

Step-by-Step Approach:
1. **Node Class**: The `Node` class represents each element in the deque. Each node has three parts:
   - `value`: Stores the value of the node (element of the deque).
   - `prev`: Pointer to the previous node.
   - `next`: Pointer to the next node.

2. **Deque Class**: The `dequeue` class contains two pointers: `Front` (points to the first node) and `Rear` (points to the last node).
   - The `push_front(x)` method inserts a node at the front of the deque.
   - The `push_back(x)` method inserts a node at the rear of the deque.
   - The `pop_front()` method removes and returns the node from the front of the deque.
   - The `pop_back()` method removes and returns the node from the rear of the deque.
   - The `start()` method returns the value of the front node (or -1 if empty).
   - The `end()` method returns the value of the rear node (or -1 if empty).
   - The `empty()` method checks if the deque is empty.
   - The `handle_single_node_deletion()` method handles deletion when there is only one element left in the deque.

3. **Deque Operations**:
   - The main program demonstrates deque operations by pushing and popping elements from both ends, displaying the front and rear elements, and checking if the deque is empty.

Explanation with Diagrams:
- The deque is represented as a doubly linked list, where each node points to its next and previous nodes.
- Example:
   - After pushing elements: `push_front(1)`, `push_back(2)`, `push_back(3)` results in: 
     ```
     Front <-> 1 <-> 2 <-> 3 <-> Rear
     ```
   - After popping from the front: `pop_front()` results in:
     ```
     Front <-> 2 <-> 3 <-> Rear
     ```
   - After popping from the back: `pop_back()` results in:
     ```
     Front <-> 2 <-> Rear
     ```

*/

class Node {
public:
    int value;  // Stores the value of the node (element in the deque)
    Node *prev;  // Pointer to the previous node
    Node *next;  // Pointer to the next node

    Node(int x) {
        value = x;
        prev = NULL;
        next = NULL;
    }
};

class dequeue {
public:
    Node *Front, *Rear;  // Pointers to the front and rear nodes of the deque

    // Constructor to initialize an empty deque
    dequeue() {
        Front = NULL;
        Rear = NULL;
    }

    // Push a new element to the front of the deque
    void push_front(int x) {
        Node *temp = new Node(x);

        if (empty()) {
            Front = Rear = temp;
        } else {
            temp->next = Front;
            Front->prev = temp;
            Front = temp;
        }
        cout << "Pushed " << x << " in front" << endl;
    }

    // Push a new element to the back of the deque
    void push_back(int x) {
        Node *temp = new Node(x);

        if (empty()) {
            Front = Rear = temp;
        } else {
            Rear->next = temp;
            temp->prev = Rear;
            Rear = temp;
        }
        cout << "Pushed " << x << " in rear" << endl;
    }

    // Pop an element from the front of the deque
    int pop_front() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;
            return -1;
        } else if (Front == Rear) {
            return handle_single_node_deletion();
        } else {
            Node *temp = Front;
            int element = temp->value;

            Front = Front->next;
            Front->prev = NULL;
            delete temp;

            cout << "Popped out " << element << endl;
            return element;
        }
    }

    // Pop an element from the back of the deque
    int pop_back() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;
            return -1;
        } else if (Front == Rear) {
            return handle_single_node_deletion();
        } else {
            Node *temp = Rear;
            int element = temp->value;

            Rear = Rear->prev;
            Rear->next = NULL;
            delete temp;

            cout << "Popped out " << element << endl;
            return element;
        }
    }

    // Return the value at the front of the deque
    int start() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;
            return -1;
        } else {
            return Front->value;
        }
    }

    // Return the value at the back of the deque
    int end() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;
            return -1;
        } else {
            return Rear->value;
        }
    }

    // Check if the deque is empty
    bool empty() {
        if (Front == NULL && Rear == NULL) {
            return true;
        } else {
            return false;
        }
    }

    // Handle deletion when there is only one element left in the deque
    int handle_single_node_deletion() {
        Node *temp = Front;
        int element = temp->value;

        Front = Front->next;
        Rear = Rear->next;
        delete temp;

        cout << "Popped out " << element << endl;
        return element;
    }
};

int main() {
    dequeue d;
    d.push_front(1);  // Pushing 1 to the front
    d.push_back(2);   // Pushing 2 to the rear
    d.push_back(3);   // Pushing 3 to the rear

    d.pop_front();    // Popping element from the front
    d.pop_back();     // Popping element from the rear
    d.pop_back();     // Popping element from the rear

    cout << d.start() << endl;  // Printing the front element
    cout << d.end() << endl;    // Printing the rear element
    cout << d.empty() << endl;  // Checking if the deque is empty
}
