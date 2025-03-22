/*
Example:
Given Linked List:  1 -> 2 -> 3 -> 4 -> 5 -> NULL

Reverse using different methods:
1. Using a vector:
   Step 1: Store values: [1, 2, 3, 4, 5]
   Step 2: Assign in reverse order: 5 -> 4 -> 3 -> 2 -> 1 -> NULL

2. Using pointers (iterative):
   Step 1: Reverse links one by one:
       1 -> NULL
       2 -> 1 -> NULL
       3 -> 2 -> 1 -> NULL
       4 -> 3 -> 2 -> 1 -> NULL
       5 -> 4 -> 3 -> 2 -> 1 -> NULL

3. Using recursion:
   Step 1: Recursively reach the last node
   Step 2: Reverse links while returning
   Step 3: Final reversed list: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
*/

#include <iostream>
#include <vector>
using namespace std;

// A single node
class Node{
    public:

    int data;
    Node *next;

    Node(int value){
        this->next = NULL;
        this->data = value;
    }
};

/*
Problem Statement:
Implement a linked list and provide different methods to reverse it.

Approach:
1. Use recursion to create a linked list from the end.
2. Reverse the linked list using three different methods:
   - ReverseList: Using a vector to store and update values.
   - ReverseListWithPointersAlso: Using pointers (iterative approach).
   - ReverseListWithPointersAlsoWithRecurrsion: Using recursion and pointers.
3. Traverse the list and print the values.

Time Complexity:
- CreateLinkedListFromEnd: O(n) (Each recursive call inserts one element)
- ReverseList: O(n) (Iterating and updating values)
- ReverseListWithPointersAlso: O(n) (Iterative reversal)
- ReverseListWithPointersAlsoWithRecurrsion: O(n) (Recursive reversal)

Space Complexity:
- CreateLinkedListFromEnd: O(n) (Recursive calls)
- ReverseList: O(n) (Extra vector storage)
- ReverseListWithPointersAlso: O(1) (In-place reversal)
- ReverseListWithPointersAlsoWithRecurrsion: O(n) (Recursive stack)
*/

// Recursively create a linked list by inserting elements at the end
Node * CreateLinkedListFromEnd(int arr[], int index, int size){
    if(index == size){
        return NULL; // Base case: when all elements are inserted
    }

    Node *temp = new Node(arr[index]);
    temp->next = CreateLinkedListFromEnd(arr, index+1, size); // Recursively build list
    return temp;
}

// Reverse linked list using a vector to store values
Node * ReverseList(Node *head){
    vector<int> ans;
    Node *temp = head;
    while (temp){
        ans.push_back(temp->data); // Store values
        temp = temp->next;
    }

    temp = head;
    int size = ans.size() - 1;
    while(temp){
        temp->data = ans[size--]; // Reverse values in place
        temp = temp->next;
    }

    return head;
}

// Reverse linked list using pointer manipulation (iterative approach)
Node * ReverseListWithPointersAlso(Node *head){
    Node *curr = head, *prev = NULL, *future = NULL;
    
    while(curr){
        future = curr->next; // Store next node
        curr->next = prev;   // Reverse link
        prev = curr;         // Move prev forward
        curr = future;       // Move curr forward
    }
    head = prev;
    return head;
}

// Reverse linked list using recursion and pointers
Node * ReverseListWithPointersAlsoWithRecurrsion(Node *curr, Node *prev){
    if (curr == NULL){
        return prev; // Base case: return new head
    }

    Node *future = curr->next; // Store next node
    curr->next = prev;         // Reverse link
    return ReverseListWithPointersAlsoWithRecurrsion(future, curr); // Recursive call
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = size(arr);

    Node *Head = NULL;
    Head = CreateLinkedListFromEnd(arr, 0, n);

    // Head = ReverseList(Head);
    Head = ReverseListWithPointersAlso(Head);
    // Head = ReverseListWithPointersAlsoWithRecurrsion(Head, NULL);

    // Traversing and printing the reversed linked list
    while(Head){
        cout<<Head->data<<" ";
        Head = Head->next;
    }
}