/*
Example Diagram:

Given array: [1, 2, 3, 4, 5, 6]
Linked List Representation:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Removing the 3rd node from the end:

Step 1: Calculate length (6)
Step 2: Find (6-3 = 3)-th node (0-based index)
Step 3: Remove node at index 3 (Node with value 4)

Modified Linked List:
1 -> 2 -> 3 -> 5 -> 6
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given an array of integers, first create a linked list from the array.
Then, remove the N-th node from the end of the linked list and print the modified list.

Approach:
1. Create a linked list from the given array using recursion.
2. Determine the length of the linked list by traversing it.
3. Find the (Length - N)-th node by traversing again.
4. Adjust the pointers to remove the N-th node from the end.
5. Print the updated linked list.

Time Complexity:
- Creating the linked list: O(N) (recursive function traverses the array)
- Calculating length of the linked list: O(N)
- Finding the node to delete: O(N)
- Overall: O(N) + O(N) + O(N) = O(N)

Space Complexity:
- O(N) due to recursion stack (creating the linked list)
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

    int nth = 3; // Position of the node to be deleted from the end
    int count = 0; // Variable to store the total length of the linked list

    Node *Head = NULL; // Head pointer of the linked list
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    Node *temp = Head, *curr = Head, *prev = NULL;

    // Step 1: Calculate the total length of the linked list
    while (temp) {
        count++;
        temp = temp->next;
    }

    // Step 2: Find the (Length - N)-th node (zero-based index)
    count -= nth; // Convert nth from end to zero-based index from start
    while (count--) {
        prev = curr;
        curr = curr->next;
    }

    // Step 3: Delete the node
    if (prev) {
        prev->next = curr->next; // Skip the current node
    } else {
        Head = curr->next; // If deleting the first node, update the head
    }

    delete curr; // Free memory of the deleted node

    // Step 4: Print the modified linked list
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}
