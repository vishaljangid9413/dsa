/*
Example Diagram:

Input:
List1:  4 -> 5 -> 3 -> 6  (Represents 4536)
List2:       2 -> 4 -> 5  (Represents  245)

Step 1: Reverse both lists
List1:  6 -> 3 -> 5 -> 4  (Now represents 6354)
List2:  5 -> 4 -> 2        (Now represents 542)

Step 2: Add corresponding digits with carry
  6  3  5  4
+    5  4  2
--------------
  6  8  9  6

Step 3: Reverse the result to get final sum
Output: 6 -> 9 -> 8 -> 6  (Represents 6986)
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
Given two numbers represented as linked lists, where each node contains a single digit, add the two numbers and return the result as a linked list.
The digits are stored in forward order (most significant digit first), but we can only traverse the list forward.

Approach:
1. Reverse both linked lists to make addition easier, as we can now process digits from least significant to most significant.
2. Traverse both linked lists, summing the corresponding digits along with any carry from the previous addition.
3. If one list is longer, continue adding its remaining digits.
4. If a carry remains after processing both lists, add a new node for it.
5. Reverse the result list to restore the correct order.

Time Complexity:
- Creating the linked lists: O(N + M) where N and M are the lengths of the input lists.
- Reversing the linked lists: O(N) + O(M).
- Adding the lists: O(max(N, M)).
- Reversing the result list: O(max(N, M)).
- Overall: O(N + M).

Space Complexity:
- O(max(N, M)) for the result linked list.
- O(1) additional space (ignoring recursion stack).
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

// Reverses a linked list recursively
Node *ReverseList(Node *prev, Node *curr) {
    if (curr == NULL) {
        return prev;  // Base case: return the new head of the reversed list
    }
    Node *future = curr->next;  // Store next node
    curr->next = prev;  // Reverse the link
    return ReverseList(curr, future);  // Move to the next node
}

// Adds two linked lists representing numbers
Node *AddList(Node *head1, Node *head2) {
    Node *temp1 = head1, *temp2 = head2;

    // Create a temporary node to store the sum
    Node *Head = new Node(0);
    Node *tail = Head;
    int carry = 0;

    // Traverse both linked lists and sum corresponding nodes
    while (temp1 && temp2) {
        int sum = temp1->data + temp2->data + carry;
        carry = sum / 10;  // Carry for next sum
        tail->next = new Node(sum % 10);  // Store the last digit
        tail = tail->next;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // If the first list is longer, continue summing
    while (temp1) {
        int sum = temp1->data + carry;
        carry = sum / 10;
        tail->next = new Node(sum % 10);
        tail = tail->next;
        temp1 = temp1->next;
    }

    // If the second list is longer, continue summing
    while (temp2) {
        int sum = temp2->data + carry;
        carry = sum / 10;
        tail->next = new Node(sum % 10);
        tail = tail->next;
        temp2 = temp2->next;
    }

    // If there is a remaining carry, create a new node for it
    while (carry) {
        tail->next = new Node(carry % 10);
        tail = tail->next;
        carry /= 10;
    }

    // Remove the temporary node and reverse the result list
    tail = Head;
    Head = Head->next;
    delete tail;

    Head = ReverseList(NULL, Head);  // Restore the correct order
    return Head;
}

int main() {
    int arr1[] = {4, 5, 3, 6};  // Represents number 4536
    int arr2[] = {2, 4, 5};     // Represents number 245
    int n1 = size(arr1);
    int n2 = size(arr2);

    Node *head1 = NULL, *head2 = NULL;
    head1 = CreateLinkedList(arr1, 0, n1);
    head2 = CreateLinkedList(arr2, 0, n2);

    // Reverse lists before performing addition
    head1 = ReverseList(NULL, head1);
    head2 = ReverseList(NULL, head2);

    // Add both numbers represented as linked lists
    Node *Head = AddList(head1, head2);

    // Print the result linked list
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
}
