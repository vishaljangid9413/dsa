/*
Example Diagram:

Input Linked Lists:

5 -> 10 -> 19 -> 28
|    |     |     |
7    20    22    35
|          |     |
8          50    40
|                |
30               45

Flattened Output:

5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given 'k' linked lists where each node has two pointers:
1. `next` → points to the next list horizontally.
2. `bottom` → points to another linked list vertically.
The goal is to flatten all lists into a single sorted list using `bottom` pointers.

Approach:
1. Use Merge Sort to divide the `k` linked lists and merge them recursively.
2. Merge lists using a helper function (`merge()`), which merges two sorted linked lists.
3. `mergesort()` applies divide & conquer on the `k` lists.

Time Complexity:
- O(N log K), where N is the total number of nodes and K is the number of linked lists.

Space Complexity:
- O(1), as we modify the existing list in-place.
*/

// Definition of Node
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

// Function to merge two sorted linked lists using bottom pointers
Node* merge(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->bottom = head1;
            head1 = head1->bottom;
        } else {
            tail->bottom = head2;
            head2 = head2->bottom;
        }
        tail = tail->bottom;
    }

    // Attach remaining nodes if any
    if (head1) tail->bottom = head1;
    if (head2) tail->bottom = head2;

    Node* newHead = dummy->bottom;
    delete dummy;  // Free the dummy node to prevent memory leaks
    return newHead;
}

// Function to sort the linked list array using merge sort
void mergesort(vector<Node*>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    // Sort left half
    mergesort(arr, start, mid);
    // Sort right half
    mergesort(arr, mid + 1, end);

    // Merge two sorted halves
    arr[start] = merge(arr[start], arr[mid + 1]);
}

// Function to print the flattened linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    // Creating multiple linked lists
    vector<Node*> arr;

    // First vertical list: 5 -> 7 -> 8 -> 30
    Node* list1 = new Node(5);
    list1->bottom = new Node(7);
    list1->bottom->bottom = new Node(8);
    list1->bottom->bottom->bottom = new Node(30);
    arr.push_back(list1);

    // Second vertical list: 10 -> 20
    Node* list2 = new Node(10);
    list2->bottom = new Node(20);
    arr.push_back(list2);

    // Third vertical list: 19 -> 22 -> 50
    Node* list3 = new Node(19);
    list3->bottom = new Node(22);
    list3->bottom->bottom = new Node(50);
    arr.push_back(list3);

    // Fourth vertical list: 28 -> 35 -> 40 -> 45
    Node* list4 = new Node(28);
    list4->bottom = new Node(35);
    list4->bottom->bottom = new Node(40);
    list4->bottom->bottom->bottom = new Node(45);
    arr.push_back(list4);

    // Sort and merge the lists
    int k = arr.size();
    mergesort(arr, 0, k - 1);

    // Print the final flattened list
    cout << "Flattened List: ";
    printList(arr[0]);

    return 0;
}
