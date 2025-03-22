/*
Example Diagram:

Creating a singly linked list using recursion:
Input Array: [1, 2, 2, 3, 4, 4, 6]

Recursive Construction:
1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 6 -> NULL

Removing Duplicates:
Original:  1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 6 -> NULL
Modified:  1 -> 2 -> 3 -> 4 -> 6 -> NULL

*/

#include <iostream>
using namespace std;

/*
Problem Statement:
1. Create a singly linked list using recursion.
2. Remove duplicate nodes from a sorted linked list.

Time Complexity:
- Creating list: O(N)
- Removing duplicates: O(N)
- Printing list: O(N)
- Overall: O(N)

Space Complexity:
- O(N) for storing N elements in the list.
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
Function: CreateLinkedListFromEnd
Creates a singly linked list recursively.

Parameters:
- arr[]: Input array.
- index: Current index in the array.
- size: Number of elements.

Returns:
- Pointer to the head of the list.
*/
Node *CreateLinkedListFromEnd(int arr[], int index, int size) {
    if (index == size) {
        return NULL;
    }

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedListFromEnd(arr, index + 1, size);
    return temp;
}

/*
Function: RemoveDuplicates
Removes duplicate nodes from a sorted linked list.

Parameters:
- Head: Pointer to the head of the linked list.

Returns:
- Head of the modified linked list.
*/
Node *RemoveDuplicates(Node *Head) {
    if (Head == NULL || Head->next == NULL) { // Fixed: Used `||` instead of `&&`
        return Head;
    }

    Node *prev = Head, *curr = Head->next;
    while (curr) {
        if (prev->data == curr->data) {
            prev->next = curr->next;
            delete curr; // Free memory
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return Head;
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
    int arr[] = {1, 2, 2, 3, 4, 4, 6};
    int n = size(arr);

    Node *Head = CreateLinkedListFromEnd(arr, 0, n);

    cout << "Original List: ";
    PrintList(Head);

    Head = RemoveDuplicates(Head);

    cout << "List after Removing Duplicates: ";
    PrintList(Head);

    return 0;
}