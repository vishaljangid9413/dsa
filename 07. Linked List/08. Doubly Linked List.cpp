/*
Example Diagram:

Input Array: [1, 2, 3, 4, 5]

1. Insertion at the Start:
   5 <-> 4 <-> 3 <-> 2 <-> 1  (Elements are inserted at the front)

2. Insertion at the End:
   1 <-> 2 <-> 3 <-> 4 <-> 5  (Elements are appended at the end)

3. Recursive Creation:
   1 <-> 2 <-> 3 <-> 4 <-> 5  (Elements are recursively linked)
*/

#include <iostream>
using namespace std;

/*
Problem Statement:
Implement a doubly linked list using three different methods:
1. Insertion at the start.
2. Insertion at the end.
3. Recursive creation.

Time Complexity:
- Creating list: O(N)
- Printing list: O(N)
- Overall: O(N)

Space Complexity:
- O(N) for storing N elements in the list.
*/

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

/*
Function: CreateListFromStart
Creates a doubly linked list by inserting elements at the start.

Parameters:
- Head: Pointer to the head of the list.
- arr[]: Input array.
- n: Number of elements.

Returns:
- New head of the doubly linked list.
*/
Node *CreateListFromStart(Node *Head, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        Node *temp = new Node(arr[i]);
        if (Head) {
            temp->next = Head;
            Head->prev = temp;
        }
        Head = temp;
    }
    return Head;
}

/*
Function: CreateListFromEnd
Creates a doubly linked list by appending elements at the end.

Parameters:
- Head: Pointer to the head of the list.
- arr[]: Input array.
- n: Number of elements.

Returns:
- Head of the doubly linked list.
*/
Node *CreateListFromEnd(Node *Head, int arr[], int n) {
    Node *tail = Head;

    // Find the tail if Head exists
    if (Head) {
        while (tail->next) {
            tail = tail->next;
        }
    }

    for (int i = 0; i < n; i++) {
        Node *temp = new Node(arr[i]);
        if (!Head) {
            Head = temp;
            tail = Head;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    return Head;
}

/*
Function: CreateListUsingRecursion
Creates a doubly linked list recursively.

Parameters:
- prev: Pointer to the previous node.
- arr[]: Input array.
- index: Current index in the array.
- n: Number of elements.

Returns:
- Pointer to the head of the list.
*/
Node *CreateListUsingRecursion(Node *prev, int arr[], int index, int n) {
    if (index == n) {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->prev = prev;
    temp->next = CreateListUsingRecursion(temp, arr, index + 1, n);
    return temp;
}

/*
Function: PrintList
Prints the doubly linked list.

Parameters:
- Head: Pointer to the head of the list.
*/
void PrintList(Node *Head) {
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = size(arr);

    Node *Head = NULL;

    // Uncomment one of the following to test different list creation methods:

    // Head = CreateListFromStart(Head, arr, n);
    // Head = CreateListFromEnd(Head, arr, n);
    Head = CreateListUsingRecursion(NULL, arr, 0, n);

    // Print the created linked list
    PrintList(Head);

    return 0;
}