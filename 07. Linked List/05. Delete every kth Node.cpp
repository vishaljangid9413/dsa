/*
Example:
Input: arr[] = {1, 2, 3, 4, 5, 6}, K = 2

Step 1: Create a linked list from the array
1 -> 2 -> 3 -> 4 -> 5 -> 6

Step 2: Delete every K-th node (every 2nd node)
After deleting node 2:
1 -> 3 -> 4 -> 5 -> 6

After deleting node 4:
1 -> 3 -> 5 -> 6

After deleting node 6:
1 -> 3 -> 5

Final Output: 1 -> 3 -> 5
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given an array of integers, first create a linked list from the array.
Then, delete every K-th node from the linked list.

Approach:
1. Create a linked list from the given array using recursion.
2. Traverse the linked list while keeping track of node positions.
3. If the current node is the K-th node, remove it from the list.
4. Continue the traversal and repeat the process.

Time Complexity:
- Creating the linked list: O(N)
- Deleting every K-th node: O(N)
- Overall: O(N)

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

    int kth = 2; // K-th node to be deleted
    int count = 1; // Counter to track the position of nodes

    Node *Head = NULL; 
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    Node *curr = Head, *prev = NULL;

    // Special case: If kth = 1, delete the entire linked list
    if (kth == 1) {
        Head = NULL;
    }

    /*
    Traverse the linked list and delete every K-th node
    - Keep track of the count
    - If count == kth, delete the current node
    */
    while (curr) {
        if (count == kth) {
            prev->next = curr->next; // Remove the K-th node from the list
            delete curr; // Free memory
            curr = prev->next; // Move to the next node
            count = 1; // Reset count after deletion
        } else {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }

    // Print the modified linked list
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}
