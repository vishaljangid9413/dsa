/*
Example Diagram:

Given an array: [1, 2, 3, 4, 5, 6]
The linked list will be created as:

    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

Finding the middle:
- Approach 1 (Using Length):
  1 -> 2 -> 3 -> [4] -> 5 -> 6 -> NULL
  Middle node is 4 (0-based index 3)

- Approach 2 (Using Two Pointers):
  Slow and Fast pointer traversal:
  Step 1: slow=1, fast=1
  Step 2: slow=2, fast=3
  Step 3: slow=3, fast=5
  Step 4: slow=4, fast=NULL (end reached)
  Middle node is 4
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given an array of integers, first create a linked list from the array.
Then, find the middle node of the linked list using two different approaches:
1. Finding the middle using the total length of the linked list.
2. Finding the middle in a single traversal using two pointers.

Approach 1 (Using Total Length):
1. Traverse the linked list to calculate its total length.
2. Traverse again up to the middle position.
3. Print the middle node.

Approach 2 (Using Two Pointers - Floyd's Algorithm):
1. Use two pointers: a slow pointer (moves one step) and a fast pointer (moves two steps).
2. When the fast pointer reaches the end, the slow pointer will be at the middle.
3. Print the middle node.

Time Complexity:
- Creating the linked list: O(N)
- Finding middle using length: O(N) + O(N) = O(N)
- Finding middle using two pointers: O(N)
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

/*
Function: FindMiddle
Finds the middle node using total length in two passes.

Parameters:
- head: Pointer to the head of the linked list

Approach:
1. First traversal to count the total number of nodes.
2. Second traversal to reach the middle node.
3. Print the middle node's address and value.
*/
void FindMiddle(Node *head) {
    Node *temp = head;
    int count = 0;

    // Step 1: Find the total length of the linked list
    while (temp) {
        temp = temp->next;
        count++;
    }

    // Step 2: Move to the middle node
    temp = head;
    count /= 2; // Middle index

    while (count--) {
        temp = temp->next;
    }

    cout << "Middle Node (Using Length): " << temp << " " << temp->data << endl;
}

/*
Function: FindMiddleInSingleTriverse
Finds the middle node using two pointers in a single traversal.

Parameters:
- head: Pointer to the head of the linked list

Approach:
1. Use two pointers: slow (moves one step) and fast (moves two steps).
2. When the fast pointer reaches the end, slow will be at the middle.
3. Print the middle node's address and value.
*/
void FindMiddleInSingleTriverse(Node *head) {
    Node *slow = head, *fast = head;

    // Traverse the list with slow moving one step and fast moving two steps
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle Node (Using Two Pointers): " << slow << " " << slow->data << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6}; // Input array
    int n = size(arr); // Size of the array

    Node *Head = NULL; 
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    // Finding the middle node using both approaches
    FindMiddle(Head);
    // FindMiddleInSingleTriverse(Head); // Uncomment to use the optimized approach

    // Printing the linked list
    for (int i = 0; i < n; i++) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}
