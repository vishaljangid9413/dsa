/*
Example Diagram:

Given linked list:

    5 -> 10 -> 19 -> 28
    |    |     |     |
    7    20    22    35
    |          |     |
    8          50    40
    |                |
    30               45

Flattened output:

    5 7 8 10 19 20 22 28 30 35 40 45 50
*/

#include <iostream>
using namespace std;

/*
Problem Statement:
Given a linked list where each node contains two pointers:
1. `next` → points to the next list horizontally.
2. `bottom` → points to another linked list vertically.
The goal is to flatten the list into a single sorted list using the `bottom` pointer.

Approach:
1. Use a recursive approach to merge two lists at a time.
2. Merge lists using a helper function (`merge()`), which merges two sorted linked lists.
3. Recursively call the `flatten()` function on the `next` node to merge all lists.

Time Complexity:
- O(N*M), where N is the number of nodes and M is the average length of each vertical list.

Space Complexity:
- O(1), as we are modifying the existing list in-place.
*/

// A single node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->bottom = NULL;
    }
};

// Function to merge two sorted lists using bottom pointers
Node* merge(Node* head1, Node* head2) {
    Node* head = new Node(0); // Temporary dummy node
    Node* tail = head;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->bottom = head1;
            tail = tail->bottom;
            head1 = head1->bottom;
        } else {
            tail->bottom = head2;
            tail = tail->bottom;
            head2 = head2->bottom;
        }
    }

    // Attach remaining nodes if any
    if (head1) {
        tail->bottom = head1;
    } else {
        tail->bottom = head2;
    }

    // Remove temporary dummy node
    tail = head;
    head = head->bottom;
    delete tail;

    return head;
}

// Function to flatten the entire linked list
Node* flatten(Node* root) {
    if (!root || !root->next) return root; // Base case

    // Recursively flatten the rest of the list
    root->next = flatten(root->next);

    // Merge current list with the next flattened list
    root = merge(root, root->next);

    return root;
}

// Function to print the flattened linked list
void printList(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

int main() {

    Node* root = new Node(5);
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);

    root->next = new Node(10);
    root->next->bottom = new Node(20);

    root->next->next = new Node(19);
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);

    root->next->next->next = new Node(28);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);

    // Flatten the list
    root = flatten(root);

    // Print the flattened list
    printList(root);

    return 0;
}
