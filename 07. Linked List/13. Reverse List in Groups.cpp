/*
Example Diagram:

Original Linked List (k = 3):
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

After reversing every group of k nodes:
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8

- Groups of 3 nodes are reversed.
- The last group (7 -> 8) has less than k nodes, so it remains unchanged.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given a singly linked list, reverse every group of 'k' nodes. 
If the remaining nodes are less than 'k', keep them as they are.

Approach:
1. Traverse the linked list while reversing groups of 'k' nodes.
2. Use three pointers: 
   - `prev` to track the previous node,
   - `curr` to track the current node,
   - `future` to track the next node.
3. Reverse the pointers within each group of `k` nodes.
4. Maintain a dummy node at the beginning to simplify edge cases.
5. After reversing a group, update the first node of the previous group to point to the reversed head.
6. If there are remaining nodes that are less than `k`, they are not reversed.

Time Complexity:
- O(N), where N is the number of nodes in the linked list. Each node is visited once.

Space Complexity:
- O(1), as we only use a few additional pointers and no extra memory is allocated apart from the input linked list.
*/

// A single node structure for the linked list
class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        this->next = NULL;
        this->data = value;
    }
};

// Recursively creates a linked list from an array
Node *CreateLinkedList(int arr[], int index, int size) {
    if (index == size) {
        return NULL;
    };

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedList(arr, index + 1, size);
    return temp;
}

// Function to reverse every group of 'k' nodes in the linked list
Node *ReverseList(Node *Head, int k) {
    Node *second, *prev, *curr, *future;

    // Create a temporary dummy node to simplify edge cases
    Node *first = new Node(0);
    first->next = Head;
    Head = first;

    while (first->next) {
        second = first->next;  // Start of the group
        prev = first;
        curr = first->next;
        int x = k;

        // Reverse the group of 'k' nodes or until the end of the list
        while (x && curr) {
            future = curr->next;  // Store next node
            curr->next = prev;  // Reverse link
            prev = curr;
            curr = future;
            x--;
        }

        // Connect the reversed segment back to the main list
        first->next = prev;  // Connect previous segment to the new head of reversed group
        second->next = curr;  // Connect last node of reversed group to the remaining list
        first = second;  // Move 'first' pointer to the next group
    }

    // Remove the temporary dummy node
    first = Head;
    Head = Head->next;
    delete first;

    return Head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};  // Given linked list
    int n = size(arr);
    int k = 7;  // Group size for reversal

    Node *Head = CreateLinkedList(arr, 0, n);
    Head = ReverseList(Head, k);

    // Print the modified linked list
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}
