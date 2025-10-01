/*
QUESTION:
Implement a Stack using:
    1. Array (Standard Stack)
    2. Linked List (Stack using Linked List)
Also, show basic usage of C++ STL Stack.

TASK:
- Create Stack class with basic operations: push, pop, peek, isEmpty, and size checking.

TIME COMPLEXITY:
- Push: O(1)
- Pop: O(1)
- Peek: O(1)
- isEmpty: O(1)
- isSize: O(1)

SPACE COMPLEXITY:
- O(N) where N = number of elements in the Stack.

DETAILED APPROACH:
We implement stack operations (push, pop, peek) manually:
1. **Array Implementation**:
    - Use an array to store elements.
    - `top` variable keeps track of the index of the topmost element.
    - When pushing, we increment `top` and store the value at `arr[top]`.
    - When popping, we simply decrease `top`.
    - If `top == size-1`, it is full (overflow).
    - If `top == -1`, it is empty (underflow).

2. **Linked List Implementation**:
    - Each node contains a data value and a pointer to the next node.
    - `top` points to the head of the linked list (top element).
    - Push: Create a new node and make it the new top.
    - Pop: Remove the current top node and update the top pointer.

3. **STL Stack**:
    - Simply use predefined `stack` from C++ STL for direct use.

DIAGRAMS FOR UNDERSTANDING:

(1) ARRAY BASED STACK:

Initially:
    arr = [ _ _ _ _ _ ]
    top = -1 (empty)

Push(5):
    arr = [5 _ _ _ _ ]
    top = 0

Push(10):
    arr = [5 10 _ _ _ ]
    top = 1

Pop():
    arr = [5 10 _ _ _ ]
    top = 0 (after removing 10)

(2) LINKED LIST BASED STACK:

Initially:
    top = NULL

Push(5):
    Node(5) -> NULL
    top -> Node(5)

Push(10):
    Node(10) -> Node(5) -> NULL
    top -> Node(10)

Pop():
    Node(10) popped
    top -> Node(5)

*/

// ----------- Code Starts Here (No modifications) -------------

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// STANDARD STACK CLASS
// Stack class with array
class StandardStack{
    int *arr;     // Dynamic array to store stack elements
    int size;     // Maximum size of the stack
    int top;      // Index of top element

    public:
    bool flag;    // To track if stack is empty

    // Constructor
    StandardStack(int s){
        size = s;
        top = -1;      // Initially, stack is empty
        flag = 1;      // Empty stack
        arr = new int(s);   // Create dynamic array of size 's'
    }

    // Push operation: Insert an element into stack
    void push(int value){
        if(top == size-1){          // Stack full
            cout<<"Stack Overflow\n";
            return;
        }else{
            top++;                  // Increase top index
            arr[top] = value;        // Store value
            cout<<"Pushed "<<value<<endl;
            flag = 0;                // Stack not empty anymore
        }
    };

    // Pop operation: Remove top element from stack
    void pop(){
        if(top == -1){               // Stack empty
            cout<<"Stack Underflow\n";
            return;
        }else{
            cout<<"Popped "<<arr[top]<<endl; // Show popped value
            top--;                   // Decrease top index
            if (top == -1){
                flag = 1;             // Stack is empty again
            }
        }
    }

    // Peek operation: View top element without removing
    int peek(){
        if (top == -1){
            cout<<"Stack is empty\n";
            return -1;
        }else{
            return arr[top];
        }
    }

    // Check if stack is empty
    bool isEmtpy(){
        return top == -1;
    }

    // Get the current size of stack
    bool isSize(){
        return top+1;
    }
};


// STACK with LINKED LIST
// Node class for Linked List
class Node{
    public:
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = NULL; // Initially, next is null
    }
};

// Stack implementation using Linked List
class StackLL{
    Node *top;    // Top node of stack
    int size;     // Number of elements in stack

    public:
    StackLL(){
        top = NULL; // Initially, stack is empty
        size = 0;
    }

    // Push operation: Insert at beginning
    void push(int value){
        Node *temp = new Node(value); // Create new node
        if(temp == NULL){             // Memory allocation failed
            cout<<"Stack Overflow\n";
            return;
        }else{
            temp->next = top;         // New node points to old top
            top = temp;               // New node becomes top
            size++;
            cout<<"Pushed "<<value<<endl;
        }
    }

    // Pop operation: Remove top node
    void pop(){
        if(top == NULL){              // Stack empty
            cout<<"Stack is empty\n";
            return;
        }else{
            cout<<"Popped "<<top->data<<endl;
            Node *temp = top;
            top = top->next;           // Move top pointer
            delete temp;               // Free memory
            size--;
        }
    }

    // Peek operation: View top node value
    int peek(){
        if(top == NULL){
            cout<<"Stack is empty\n";
            return -1;
        }else{
            return top->data;
        }
    }

    // Check if stack is empty
    bool isEmpty(){
        return top == NULL;
    }

    // Get current size
    bool isSize(){
        return size;
    }
};


int main(){
    // Creating a Linked List Stack
    StackLL sll;
    sll.push(4);
    sll.pop();
    cout<<sll.isSize()<<endl;

    // Stack STL (predefined stack class in C++)
    stack<int>s;
    s.push(5);
    cout<<s.top();
}
