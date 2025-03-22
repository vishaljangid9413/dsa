/*
Example Diagram:

Original Linked List:

    1 -----> 2 -----> 3 -----> 4 -----> 5 -----> NULL
    |        |        |        |        |
    v        v        v        v        v
    3        1        5        3        2   (Random Pointers)

Cloned Linked List:

    1' -----> 2' -----> 3' -----> 4' -----> 5' -----> NULL
    |          |         |         |         |
    v          v         v         v         v
    3'         1'        5'        3'        2'   (Random Pointers)
*/

#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Given a linked list where each node contains a 'next' pointer (to the next node) and a 'random' pointer (pointing to any node in the list or NULL), 
// we need to create a deep copy (clone) of the linked list.

// Approach:
// 1. We have implemented two methods:
//    - First method: Uses extra space to find the corresponding node for setting up the random pointers.
//    - Second method (Optimized): Uses O(1) extra space by interleaving cloned nodes with the original list.

// Time Complexity:
// - First method: O(n^2) due to traversing the list repeatedly to find random pointers.
// - Second method: O(n) since we traverse the list a constant number of times.

// Space Complexity:
// - First method: O(n) due to extra space used for finding random pointers.
// - Second method: O(1) as it does not use additional memory apart from the cloned nodes.

// Definition of a Node with 'next' and 'random' pointers
class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node(int value) {
        this->next = NULL;
        this->random = NULL;
        this->data = value;
    }
};

// FIRST METHOD (Brute force approach with extra space)
// Helper function to find the corresponding node in the cloned list
Node *findrandom(Node *head, Node *cloneHead, Node *x) {
    if (x == NULL) {
        return NULL;
    }

    // Traverse until we reach the required random node
    while (head != x) {
        head = head->next;
        cloneHead = cloneHead->next;
    }

    return cloneHead;
}

// Function to assign random pointers in the cloned list using extra space
void firstmethod(Node *head, Node *cloneHead) {
    Node *temp = head;
    Node *cloneTail = cloneHead;

    while (temp) {
        // Find the corresponding random node in the cloned list
        cloneTail->random = findrandom(head, cloneHead, temp->random);
        cloneTail = cloneTail->next;
        temp = temp->next;
    }
}

// SECOND METHOD (Optimized approach with O(1) extra space)
void secondmethod(Node *head, Node *cloneHead) {
    Node *curr1 = head, *curr2 = cloneHead;
    Node *front1, *front2;

    // Step 1: Interleave cloned nodes with the original list
    while (curr1) {
        front1 = curr1->next;
        front2 = curr2->next;
        curr1->next = curr2;
        curr2->next = front1;
        curr1 = front1;
        curr2 = front2;
    }

    // Step 2: Assign random pointers in the cloned list
    curr1 = head;
    while (curr1) {
        curr2 = curr1->next;
        if (curr1->random) {
            curr2->random = curr1->random->next;
        }
        curr1 = curr2->next;
    }

    // Step 3: Separate the cloned list from the original list
    curr1 = head;
    while (curr1->next) {
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
    }
}

int main() {
    // Creating a linked list with 'next' and 'random' pointers
    // This example assumes the list is already created, with head pointing to the first node.
    Node *head;
    Node *temp = head;

    // Step 1: Clone the linked list without assigning random pointers
    Node *cloneHead = new Node(0);
    Node *cloneTail = cloneHead;
    while (temp) {
        cloneTail->next = new Node(temp->data);
        cloneTail = cloneTail->next;
        temp = temp->next;
    }

    // Step 2: Remove extra dummy node used for cloning
    cloneTail = cloneHead;
    cloneHead = cloneHead->next;
    delete cloneTail;

    // Step 3: Using both methods to assign random pointers
    firstmethod(head, cloneHead); // Brute force method
    secondmethod(head, cloneHead); // Optimized method

    cout << "Ans: " << cloneHead;
}
