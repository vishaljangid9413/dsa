#include <iostream>
using namespace std;

// Problem Statement:
// This code implements a Queue using a linked list, where the elements are inserted at the head of the list (front of the queue).
// The problem is to simulate a queue with a fixed limit, implementing the basic operations of enqueue (push) and dequeue (pop).
// The Queue has additional features, such as checking if the queue is empty, getting the front element, and checking the queue size.
// It also handles overflow and underflow conditions properly. 
// The problem is designed for scenarios where queue operations need to be managed using linked list data structures.
// No specific problem link provided for this example.

// Time Complexity:
// - Push operation: O(1) (constant time). The operation simply creates a new node and adds it at the front of the queue.
// - Pop operation: O(1) (constant time). The operation removes the front node and adjusts the head pointer accordingly.
// - IsEmpty operation: O(1) (constant time). Checking if the queue is empty is done by comparing the count variable.
// - Start operation: O(1) (constant time). Returning the value of the front element is done in constant time.
// - Size operation: O(1) (constant time). The size is directly returned from the count variable.

// Space Complexity:
// - O(n), where n is the number of elements in the queue. This is because each element requires a separate node in memory.
//   The space required is proportional to the number of elements in the queue due to the linked list structure.


// Step-by-Step Approach:
// 1. **Node class**: Defines the individual elements of the queue. Each node contains a value and a pointer to the next node in the queue.
// 2. **Queue class**: Manages the queue. It includes methods to check if the queue is empty, get the size of the queue, and perform push and pop operations.
//    - The `push` method adds an element to the front of the queue by creating a new node and adjusting the head pointer.
    // - The `pop` method removes an element from the front by updating the head pointer and freeing the memory for the removed node.
// 3. The queue also has a limit on its size, meaning it will refuse to add elements once the limit is reached, displaying an overflow message.
// 4. The queue checks for underflow when attempting to pop an element from an empty queue and displays an underflow message if so.

// Explanation with Diagrams:
// **Queue Structure** (Linked List Representation):
// Initially, the queue is empty:
//     Head -> NULL
//     (count = 0)
// 
// After pushing 5:
//     Head -> 5 -> NULL
//     (count = 1)
//
// After pushing 10:
//     Head -> 10 -> 5 -> NULL
//     (count = 2)
//
// After pushing 12 (overflow occurs as the limit is 2):
//     "Queue is overflowed!"
//     (count = 2)
//
// Pop operation (removing the front element):
// After popping:
//     Head -> 5 -> NULL
//     (count = 1)
//
// The queue works using a linked list structure where each element is a node, and the queue operates by manipulating the head pointer and the next pointers of the nodes.


// Simple Explanation of the Code:
// The code implements a basic queue with a linked list structure. The queue allows you to add elements to the front and remove elements from the front.
// It handles the following scenarios:
// 1. **Overflow**: The queue can hold a maximum number of elements (based on the limit). If you try to add more, it gives an "overflow" message.
// 2. **Underflow**: If you try to remove an element when the queue is empty, it gives an "underflow" message.
// 3. The `start()` method gives you the value of the element at the front of the queue without removing it.


// Code Implementation:

class Node{
    public:
    int value;  // The value stored in the node
    Node *next;  // Pointer to the next node in the queue

    // Constructor to initialize a new node with a given value
    Node(int x){
        value = x;  // Set the value of the node
        next = NULL;  // Initialize the next pointer to NULL
    }
};

class Queue{
    public:
    int count, limit;  // count stores the current number of elements in the queue, limit is the maximum size of the queue
    Node *Head;  // Pointer to the front of the queue (head of the linked list)

    // Constructor to initialize the queue with a size limit
    Queue(int n = -1){
        limit = n;  // Set the maximum size of the queue
        count = 0;  // Initialize the count to 0 (queue is empty)
        Head = NULL;  // Initialize the head pointer to NULL (queue is empty)
    }

    // Method to check if the queue is empty
    bool IsEmpty(){
        return count == 0;  // Queue is empty if count is 0
    }

    // Method to get the front element of the queue (without removing it)
    int start(){
        if(IsEmpty()){  // If the queue is empty, print underflow message and return -1
            cout<<"Queue is underflowed!"<<endl;
            return -1;
        }else{  // Otherwise, return the value at the front of the queue
            return Head->value;
        }
    }

    // Method to get the current size of the queue
    int size(){
        return count;  // Return the current number of elements in the queue
    }

    // Method to push a new element to the front of the queue
    void push(int x){
        if (count == limit){  // If the queue is full, print overflow message
            cout<<"Queue is overflowed!"<<endl;
            return;
        }

        Node *temp = new Node(x);  // Create a new node with the given value
        if (temp == NULL){  // If memory allocation fails, print overflow message
            cout<<"Queue is overflowed!"<<endl;
        }

        // If the queue is empty, set the new node as the head
        if (Head == NULL){
            Head = temp;
        }else{  // Otherwise, insert the new node at the front (update head pointer)
            temp->next = Head;
            Head = temp;
        }
        count++;  // Increment the count of elements in the queue
        cout<<"Pushed "<<x<<endl;  // Print the pushed value
    }

    // Method to pop (remove) the front element of the queue
    int pop(){
        if(IsEmpty()){  // If the queue is empty, print underflow message and return -1
            cout<<"Queue is underflowed!"<<endl;
            return -1;
        }

        Node *temp = Head;  // Store the front node temporarily
        int value = temp->value;  // Store the value of the front node
        Head = Head->next;  // Move the head pointer to the next node (remove the front node)
        delete temp;  // Free the memory of the removed node
        count--;  // Decrement the count of elements in the queue
        return value;  // Return the value of the popped element
    }
};


int main(){
    Queue q(2);  // Create a queue with a limit of 2 elements
    q.push(5);   // Push 5 to the queue
    q.push(10);  // Push 10 to the queue
    q.push(12);  // Try to push 12, but it will overflow since the queue limit is 2

    cout<<q.start();  // Print the front element of the queue (should be 10 after the pop operation)
}
