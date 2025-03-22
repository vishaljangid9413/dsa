/*
Example Diagram:

Given a linked list: 1 -> 2 -> 3 -> 2 -> 1

Step 1: Find the middle of the linked list.
           1 -> 2 -> (3) -> 2 -> 1
                     ^ Middle element

Step 2: Reverse the second half.
           1 -> 2 -> 3    1 <- 2

Step 3: Compare both halves.
          First half:  1 -> 2 -> 3
          Second half: 1 -> 2 -> 3 (Reversed)

Step 4: If all elements match, the list is a palindrome.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given a singly linked list, determine if it is a palindrome.

Approach:
1. Convert the given array into a linked list using recursion.
2. Count the number of nodes in the list.
3. Find the middle of the list and separate the first half from the second half.
4. Reverse the second half of the list.
5. Compare the first half with the reversed second half.
6. If all elements match, return true; otherwise, return false.

Time Complexity:
- Creating the linked list: O(N)
- Finding the length of the list: O(N)
- Reversing the second half: O(N)
- Comparing both halves: O(N)
- Overall: O(N)

Space Complexity:
- O(N) due to recursion stack for creating the linked list.
- O(1) extra space for reversing and comparison.
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
Function: ReverseList
Reverses a given linked list.

Parameters:
- head: Pointer to the head of the linked list

Returns:
- Pointer to the new head of the reversed linked list
*/
Node *ReverseList(Node *head) {
    Node *curr = head, *prev = NULL, *future = NULL;
    
    while (curr) {
        future = curr->next; // Store the next node
        curr->next = prev;   // Reverse the current node’s pointer
        prev = curr;         // Move prev forward
        curr = future;       // Move curr forward
    }
    head = prev; // Update the head to the last node (new head)
    return head;
}

/*
Function: CheckPalindrome
Checks whether the given linked list is a palindrome.

Parameters:
- Head: Pointer to the head of the linked list

Returns:
- true (1) if the linked list is a palindrome
- false (0) otherwise
*/
bool CheckPalindrome(Node *Head) {
    Node *temp = Head, *secondTemp = NULL;
    int count = 0;

    // Find length of the list
    while (temp) {
        temp = temp->next;
        count++;
    }

    // If the list has 0 or 1 element, it is always a palindrome
    if (count < 2) {
        return true;
    }

    // Find the middle of the list and split it
    temp = Head;
    count /= 2; 
    count--;
    while (count--) { // Move temp to the (n/2)th node
        temp = temp->next;
    }

    // Separate the second half of the list
    secondTemp = temp->next;
    temp->next = NULL; // Split the list into two halves

    // Reverse the second half of the list
    secondTemp = ReverseList(secondTemp);

    // Compare the first and reversed second half
    temp = Head;
    while (temp && secondTemp) {
        if (temp->data != secondTemp->data) {
            return false; // Not a palindrome
        }
        temp = temp->next;
        secondTemp = secondTemp->next;
    }

    return true; // The list is a palindrome
}

int main() {
    int arr[] = {1, 2, 3, 2, 1}; // Input linked list
    int n = size(arr);

    Node *Head = NULL;
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    // Check if the list is a palindrome
    if (CheckPalindrome(Head)) {
        cout << "List is a palindrome";
    } else {
        cout << "List is not a palindrome";
    }
}