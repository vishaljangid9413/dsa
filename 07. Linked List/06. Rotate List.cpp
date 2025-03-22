/*
Example Diagram:

Given array: [1, 2, 3, 4, 5, 6]
Convert to linked list:
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

Rotate right by k = 2 positions:
Step 1: Find length of the list (count = 6)
Step 2: k = k % count = 2
Step 3: Identify the new head (count - k = 4th node)
    New head: 5 (previously 4th node)
Step 4: Update connections:
    - New tail (4th node) next = NULL
    - Old tail (6th node) next = old head (1st node)

Result after rotation:
    5 -> 6 -> 1 -> 2 -> 3 -> 4 -> NULL
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given an array of integers, first create a linked list from the array.
Then, rotate the linked list to the right by K positions.

Approach:
1. Convert the given array into a linked list using recursion.
2. Calculate the total number of nodes in the linked list.
3. Find the tail node and adjust K so that it lies within the range (K % count).
4. Identify the new head of the rotated linked list by finding the (count-K)th node.
5. Update the connections:
   - Set the previous node’s next pointer to NULL (new tail).
   - Connect the old tail node to the old head.
   - Update the head pointer to the new head.
6. Print the rotated linked list.

Time Complexity:
- Creating the linked list: O(N)
- Finding the length of the list: O(N)
- Rotating the list: O(N)
- Printing the list: O(N)
- Overall: O(N)

Space Complexity:
- O(N) due to recursion stack for creating the linked list.
*/

/*
Definition of a single node in the linked list.
Each node contains:
- An integer data value
- A pointer to the next node in the list
*/
class Node {
    public:
    int data;   // Stores the integer value of the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize the node with a given value
    Node(int value) {
        this->next = NULL;
        this->data = value;
    }
};

/*
Function: CreateLinkedListFromEnd
Recursively creates a linked list from an array.

Parameters:
- arr[]: Input array of integers
- index: Current index in the array
- size: Total size of the array

Returns:
- Pointer to the head of the linked list
*/
Node *CreateLinkedListFromEnd(int arr[], int index, int size) {
    if (index == size) {
        return NULL; // Base case: If index reaches size, return NULL
    }

    // Create a new node for the current array element
    Node *temp = new Node(arr[index]);

    // Recursively call for the next element in the array
    temp->next = CreateLinkedListFromEnd(arr, index + 1, size);

    return temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}; // Input array
    int n = size(arr); // Size of the array

    Node *Head = NULL; 
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    if (Head == NULL) {
        return 0; // If the list is empty, return
    }
    
    Node *temp = Head, *tail = NULL;
    Node *prev = NULL, *curr = Head;
    int k = 2; // Number of positions to rotate the linked list
    int count = 1; // Counter to count total nodes

    /*
    Find the total number of nodes in the linked list
    and identify the last (tail) node.
    */
    while (temp->next) {
        temp = temp->next;
        count++;
    }
    tail = temp; // The last node in the original list

    /*
    Handling edge cases:
    - If k is a multiple of count, rotating has no effect.
    - If count is 0 (empty list), exit.
    */
    k = k % count; 
    if (k == 0 || count == 0) {
        return 0;
    }

    /*
    Find the (count - k)th node, which will be the new tail
    after rotation. The next node will be the new head.
    */
    curr = Head;
    count -= k;
    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    /*
    Update the linked list:
    - Set the new tail’s next pointer to NULL.
    - Connect the old tail to the old head.
    - Update Head pointer to the new head.
    */
    prev->next = NULL;
    tail->next = Head;
    Head = curr;

    // Print the rotated linked list
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}