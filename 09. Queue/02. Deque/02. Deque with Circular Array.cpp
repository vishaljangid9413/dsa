#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem: Implementing a Double Ended Queue (Deque) using a Circular Array
// A Deque (Double-Ended Queue) allows inserting and deleting elements from both ends efficiently.
// The challenge is to implement a deque using a circular array to make sure the space is used optimally without any overflow until the deque is full.

//
// Time Complexity:
// - Push front and push back: O(1) (Amortized constant time due to array operations)
// - Pop front and pop back: O(1) (Amortized constant time due to array operations)
// - Start and end: O(1) (Accessing the front or rear element)
// - Empty: O(1) (Simple comparison of count with 0)
// - Full: O(1) (Simple comparison of count with size)
//
// Space Complexity:
// - O(n), where n is the size of the deque. We use an array of size 'n' to store the elements.
//
// Approach:
//
// 1. We create a deque using a circular array with operations to push and pop elements from both ends.
// 2. We handle the circular nature of the array by using modulo operations to manage the indices for the front and rear pointers.
// 3. We handle the "overflow" and "underflow" conditions when trying to add or remove elements from the deque.
// 4. The deque operates with constant-time insertions and deletions from both ends, making it efficient for dynamic-sized applications.

class dequeue {
    int front, rear, size, count;  // front and rear are pointers to the deque, size is the maximum capacity, and count is the current number of elements.
    int *arr;  // The array that holds the elements of the deque.

public:
    // Constructor: Initializes a deque with the given size.
    dequeue(int n) {
        arr = new int[n];   // Allocating memory for the array.
        size = n;           // Maximum size of the deque.
        count = 0;          // Initially, the deque is empty.
        front = rear = -1;  // Initializing pointers to -1 (indicating empty deque).
    }

    // push_front: Inserts an element at the front of the deque.
    void push_front(int x) {
        if (full()) {
            cout << "Deque is overflowed" << endl;  // Deque is full, cannot insert.
            return;
        } else if (empty()) {
            front = rear = 0;  // First element, both front and rear point to index 0.
            arr[0] = x;        // Inserting element at the front.
            count++;           // Incrementing the count of elements.
        } else {
            front = (front - 1 + size) % size;  // Circular movement for the front pointer.
            arr[front] = x;  // Insert element at the front.
            count++;         // Incrementing the count of elements.
        }
        cout << "Pushed " << x << " in front" << endl;
    }

    // push_back: Inserts an element at the rear of the deque.
    void push_back(int x) {
        if (full()) {
            cout << "Deque is overflowed" << endl;  // Deque is full, cannot insert.
            return;
        } else if (empty()) {
            front = rear = 0;  // First element, both front and rear point to index 0.
            arr[0] = x;        // Inserting element at the rear.
            count++;           // Incrementing the count of elements.
        } else {
            rear = (rear + 1) % size;  // Circular movement for the rear pointer.
            arr[rear] = x;    // Insert element at the rear.
            count++;          // Incrementing the count of elements.
        }
        cout << "Pushed " << x << " in rear" << endl;
    }

    // pop_front: Removes the element from the front of the deque and returns it.
    int pop_front() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;  // Deque is empty, cannot pop.
            return -1;
        } else {
            int element = arr[front];    // Store the front element.
            front = (front + 1) % size;  // Move the front pointer circularly.
            count--;                     // Decrease the count of elements.
            cout << "Popped out " << element << endl;
            return element;
        }
    }

    // pop_back: Removes the element from the rear of the deque and returns it.
    int pop_back() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;  // Deque is empty, cannot pop.
            return -1;
        } else {
            int element = arr[rear];    // Store the rear element.
            rear = (rear - 1 + size) % size;  // Move the rear pointer circularly.
            count--;                         // Decrease the count of elements.
            cout << "Popped out " << element << endl;
            return element;
        }
    }

    // start: Returns the front element of the deque without removing it.
    int start() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;  // Deque is empty, cannot access.
            return -1;
        } else {
            return arr[front];   // Return the front element.
        }
    }

    // end: Returns the rear element of the deque without removing it.
    int end() {
        if (empty()) {
            cout << "Deque is underflowed" << endl;  // Deque is empty, cannot access.
            return -1;
        } else {
            return arr[rear];    // Return the rear element.
        }
    }

    // empty: Checks if the deque is empty.
    bool empty() {
        return count == 0;   // Returns true if the deque is empty (count = 0).
    }

    // full: Checks if the deque is full.
    bool full() {
        return count >= size;   // Returns true if the deque is full (count >= size).
    }
};

int main() {
    dequeue d(4);  // Create a deque with a size of 4.

    // Insert elements at the front and rear.
    d.push_front(1);
    d.push_back(2);
    d.push_back(3);

    // Remove elements from the front and rear.
    d.pop_front();
    d.pop_back();
    d.pop_back();

    // Add elements again.
    d.push_back(3);
    d.push_front(1);

    // Display front, rear, and check if deque is empty.
    cout << d.start() << endl;  // Display the front element.
    cout << d.end() << endl;    // Display the rear element.
    cout << d.empty();          // Check if the deque is empty.

    return 0;
}
