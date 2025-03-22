/*
Example Diagram:

List 1:       1 -> 2 -> 3 -> 6
List 2:       2 -> 4 -> 5 -> 7 -> 8
-----------------------------------
Merged List:  1 -> 2 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8

The diagram illustrates:
1. Creating two sorted linked lists from arrays.
2. Merging the two lists into a single sorted linked list.
*/

#include <iostream>
using namespace std;

/*
Problem Statement:
1. Create a singly linked list using recursion.
2. Merge two sorted linked lists into a single sorted list.

Time Complexity:
- Creating lists: O(N + M)
- Merging lists: O(N + M)
- Printing lists: O(N + M)
- Overall: O(N + M)

Space Complexity:
- O(N + M) for storing N + M elements in the merged list.
*/

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
Function: CreateList
Creates a singly linked list recursively.

Parameters:
- arr[]: Input array.
- index: Current index in the array.
- size: Number of elements.

Returns:
- Pointer to the head of the list.
*/
Node *CreateList(int arr[], int index, int size) {
    if (index == size) {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->next = CreateList(arr, index + 1, size);
    return temp;
}

/*
Function: MergeList
Merges two sorted linked lists into a single sorted linked list.

Parameters:
- head1: Pointer to the first sorted linked list.
- head2: Pointer to the second sorted linked list.

Returns:
- Head of the merged sorted linked list.
*/
Node *MergeList(Node *head1, Node *head2) {
    // If one list is empty, return the other
    if (!head1) return head2;
    if (!head2) return head1;

    // Create a dummy node
    Node *dummy = new Node(0);
    Node *tail = dummy;

    // Merge the lists
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Attach remaining elements
    tail->next = (head1) ? head1 : head2;

    // Store the real head and delete dummy node
    Node *mergedHead = dummy->next;
    delete dummy; // Free memory

    return mergedHead;
}

/*
Function: PrintList
Prints the linked list.

Parameters:
- Head: Pointer to the head of the list.
*/
void PrintList(Node *Head) {
    Node *temp = Head; // Preserve original Head
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 6};
    int arr2[] = {2, 4, 5, 7, 8};

    int n1 = size(arr1);
    int n2 = size(arr2);

    Node *Head1 = CreateList(arr1, 0, n1);
    Node *Head2 = CreateList(arr2, 0, n2);

    cout << "List 1: ";
    PrintList(Head1);

    cout << "List 2: ";
    PrintList(Head2);

    Node *MergedHead = MergeList(Head1, Head2);

    cout << "Merged List: ";
    PrintList(MergedHead);

    return 0;
}
