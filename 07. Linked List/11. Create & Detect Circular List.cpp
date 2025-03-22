/*
Example Diagram:

Step 1: Creating a linked list from an array [1, 2, 3, 4, 5, 6]

   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

Step 2: Creating a loop at position 4 (1-based index)

   1 -> 2 -> 3 -> 4 -> 5 -> 6
                ^         |
                |         v
                -----------

Step 3: Detecting the loop and finding its length

   - Using Floyd's cycle-finding algorithm
   - Slow and fast pointers detect the cycle
   - Loop length is calculated once the cycle is detected
*/

#include <iostream>
using namespace std;

/*
Problem Statement:
1. Create a singly linked list using recursion.
2. Create a loop in the linked list at a given position.
3. Detect whether a loop exists.
4. Find the length of the loop if it exists.

Time Complexity:
- Creating list: O(N)
- Loop detection: O(N)
- Loop length calculation: O(N)
- Overall: O(N)

Space Complexity:
- O(1) (constant extra space used)
*/

// Node definition
class Node {
public:
    int data;
    Node *next;

    // Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

/*
Function: CreateLinkedListFromEnd
Recursively creates a singly linked list.

Parameters:
- arr[]: Input array.
- index: Current index in the array.
- size: Total elements in the array.

Returns:
- Head pointer of the created linked list.
*/
Node *CreateLinkedListFromEnd(int arr[], int index, int size) {
    if (index == size) return NULL;

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedListFromEnd(arr, index + 1, size);
    return temp;
}

/*
Function: CreateLoop
Creates a loop in the linked list at a given position.

Parameters:
- Head: Pointer to the head of the linked list.
- position: 1-based position where the loop should be created.

Returns:
- Nothing (modifies list in place).
*/
void CreateLoop(Node *Head, int position) {
    if (!Head || position <= 0) return;

    Node *temp = Head, *positionNode = NULL;
    int count = 1;

    // Find the node at the given position
    while (temp->next) {
        if (count == position) {
            positionNode = temp;
        }
        temp = temp->next;
        count++;
    }

    // Link the last node to the position node
    temp->next = positionNode;
}

/*
Function: DetectLoop
Detects if a loop exists in the linked list.

Parameters:
- Head: Pointer to the head of the linked list.

Returns:
- true if a loop is found, false otherwise.
*/
bool DetectLoop(Node *Head) {
    Node *slow = Head, *fast = Head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true; // Loop detected
        }
    }
    return false; // No loop
}

/*
Function: DetectLoopWithLength
Finds the length of the loop if a loop exists.

Parameters:
- Head: Pointer to the head of the linked list.

Returns:
- Length of the loop if found, else 0.
*/
int DetectLoopWithLength(Node *Head) {
    Node *slow = Head, *fast = Head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Loop detected, now calculate its length
            int count = 1;
            Node *temp = slow->next;
            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0; // No loop
}

/*
Function: PrintList
Safely prints the linked list up to `maxNodes` elements to prevent infinite loops.

Parameters:
- Head: Pointer to the head of the list.
- maxNodes: Maximum number of nodes to print (for safety).
*/
void PrintList(Node *Head, int maxNodes = 20) {
    Node *temp = Head;
    int count = 0;
    
    while (temp && count < maxNodes) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << (count == maxNodes ? "..." : "") << endl;
}

// Main driver function
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = size(arr);

    Node *Head = CreateLinkedListFromEnd(arr, 0, n);

    // Creating a loop at position 4 (1-based index)
    CreateLoop(Head, 4);

    // Detecting the loop
    if (DetectLoop(Head)) {
        cout << "Loop detected in the linked list." << endl;
        int loop_length = DetectLoopWithLength(Head);
        cout << "Length of the loop: " << loop_length << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Uncommenting this would cause an infinite loop if a cycle exists
    // PrintList(Head);

    return 0;
}
