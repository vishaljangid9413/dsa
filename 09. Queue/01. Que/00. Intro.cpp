#include <iostream>
using namespace std;

// Problem Statement:
// The code implements a Queue using a circular array. The Queue follows the FIFO (First In, First Out) principle, 
// where elements are added to the rear of the queue and removed from the front. 
// The problem is to create a Queue that efficiently uses space and handles overflow and underflow conditions.
// The queue implementation uses circular array techniques to optimize space by reusing empty slots when elements are removed.
// No specific problem link provided for this example.

// Time Complexity:
// - Push operation: O(1) (constant time). Adding an element to the queue only requires updating the rear pointer and checking for overflow.
// - Pop operation: O(1) (constant time). Removing an element from the queue involves adjusting the front pointer and checking for underflow.
// - IsEmpty operation: O(1) (constant time). Checking whether the queue is empty is a simple comparison of the front pointer.
// - IsFull operation: O(1) (constant time). Checking if the queue is full is a simple modulus operation.

// Space Complexity:
// - O(n), where n is the size of the queue. This is because the queue stores n elements in a dynamically allocated array.
//   We only use space for the array and a few integer variables to track the front, rear, and size of the queue.

// Step-by-Step Approach:
// 1. The Queue class is designed to handle a circular array-based queue.
// 2. The constructor initializes the size of the array and sets the front and rear pointers to -1, indicating an empty queue.
// 3. The IsEmpty() method checks if the queue is empty by comparing if the front pointer is -1.
// 4. The IsFull() method checks if the queue is full by checking if the next position after the rear pointer is equal to the front.
// 5. The start() method returns the front element of the queue, or displays an underflow message if the queue is empty.
// 6. The push() method adds an element to the rear of the queue. If the queue is full, it displays an overflow message. 
//    It updates the rear pointer in a circular manner, ensuring that the array space is reused when elements are removed.
// 7. The pop() method removes the element from the front of the queue. If there is only one element, it resets both the front and rear pointers to -1. 
//    If there are more elements, it updates the front pointer circularly.
// 8. The main() function demonstrates the queue operations by pushing and popping elements from the queue.

// Explanation with Diagrams:
// 1. Initially, the queue is empty:
//    front = -1, rear = -1
//    [ ] [ ] [ ] [ ] [ ]
// 
// 2. After pushing an element (e.g., 4), the queue looks like:
//    front = 0, rear = 0
//    [ 4 ] [ ] [ ] [ ] [ ]
// 
// 3. After pushing another element (e.g., 2), the queue looks like:
//    front = 0, rear = 1
//    [ 4 ] [ 2 ] [ ] [ ] [ ]
// 
// 4. After popping an element, the front moves to the next position, and the queue looks like:
//    front = 1, rear = 1
//    [ ] [ 2 ] [ ] [ ] [ ]
// 
// 5. The queue can be expanded further and will reuse empty positions due to its circular nature. If the rear pointer reaches the last index, it will wrap around to 0, as shown below:
//    [ 4 ] [ ] [ ] [ ] [ 2 ]  (After popping, rear moves circularly and fills the available space.)

class Queue{
    public:
    int *arr;  // Array to hold the queue elements
    int front, rear, size;  // Pointers for front and rear of the queue and the size of the queue

    // Constructor to initialize the queue with a specified size
    Queue(int n){
        size = n;  // Set the size of the queue
        arr = new int[size];  // Dynamically allocate memory for the array
        front = -1;  // Initialize the front to -1 indicating the queue is empty
        rear = -1;  // Initialize the rear to -1 indicating the queue is empty
    }

    // Method to check if the queue is empty
    bool IsEmpty(){
        return front == -1;  // If front is -1, the queue is empty
    }

    // Method to check if the queue is full
    bool IsFull(){
        return (rear + 1) % size == front;  // If rear + 1 modulo size equals front, the queue is full (circular nature)
    }

    // Method to return the front element of the queue without removing it
    int start(){
        if(IsEmpty()){  // If the queue is empty, print underflow message and return -1
            cout<<"Queue is underflowed!"<<endl;
            return -1;
        }else{  // Otherwise, return the element at the front
            return arr[front];
        }
    }

    // Method to add an element to the rear of the queue
    void push(int x){
        if (IsFull()){  // If the queue is full, print overflow message and exit
            cout<<"Queue is Overflowed!"<<endl;
            return;
        }else if(IsEmpty()){  // If the queue is empty, set both front and rear to 0 and add the element
            cout<<"Pushed "<<x<<endl;
            front++;
            rear++;
            arr[rear] = x;
        }else{  // Otherwise, update the rear pointer circularly and add the element
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout<<"Pushed "<<x<<endl;
        }
    }

    // Method to remove and return the front element of the queue
    int pop(){
        if (IsEmpty()){  // If the queue is empty, print underflow message and return -1
            cout<<"Queue is underflow!"<<endl;
            return -1;
        }else if(front == rear){  // If there's only one element, reset both front and rear to -1 after popping
            int element = arr[front];
            front = rear = -1;
            cout<<"Popped out "<<element<<endl;
            return element;
        }else{  // Otherwise, update the front pointer circularly and return the popped element
            int element = arr[front];
            front = (front + 1) % size;
            cout<<"Popped out "<<element<<endl;
            return element;
        }
    }
};


int main(){
    Queue q(5);  // Create a queue of size 5
    q.push(4);   // Push element 4 to the queue
    q.push(2);   // Push element 2 to the queue
    q.pop();     // Pop an element from the queue
    cout<<q.start();  // Display the front element of the queue
}
