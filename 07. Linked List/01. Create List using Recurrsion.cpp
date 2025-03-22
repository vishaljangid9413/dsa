/*
Example Diagram:

Insertion at the Beginning (Recursion):
------------------------------------
Input Array: [1, 2, 3, 4, 5]

Step-by-Step Insertion:
1 -> NULL
2 -> 1 -> NULL
3 -> 2 -> 1 -> NULL
4 -> 3 -> 2 -> 1 -> NULL
5 -> 4 -> 3 -> 2 -> 1 -> NULL

Insertion at the End (Recursion):
--------------------------------
Input Array: [1, 2, 3, 4, 5]

Step-by-Step Insertion:
NULL
1 -> NULL
1 -> 2 -> NULL
1 -> 2 -> 3 -> NULL
1 -> 2 -> 3 -> 4 -> NULL
1 -> 2 -> 3 -> 4 -> 5 -> NULL

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
Implement a linked list using recursion. The linked list should be created from both the beginning and the end.

Approach:
1. Use recursion to insert elements at the front (CreateLinkedListFromBeginning).
2. Use recursion to insert elements at the end (CreateLinkedListFromEnd).
3. Traverse the list and print the values.

Time Complexity:
- CreateLinkedListFromBeginning: O(n) (Each recursive call inserts one element at the front)
- CreateLinkedListFromEnd: O(n^2) (Each recursive call iterates to the last node, making it inefficient)
- Traversal: O(n)

Space Complexity:
- O(n) due to recursive calls in CreateLinkedListFromBeginning and CreateLinkedListFromEnd.
*/

// Recursively create a linked list by inserting elements at the front
Node * CreateLinkedListFromBeginning(Node *Head, int arr[], int index, int size){
    if(index == size){
        return Head; // Base case: when all elements are inserted
    }

    Node *temp = new Node(arr[index]);
    temp->next = Head; // Insert at the front
    return CreateLinkedListFromBeginning(temp, arr, index+1, size);
}

// Recursively create a linked list by inserting elements at the end
Node * CreateLinkedListFromEnd(Node *Head, Node *curr, int arr[], int index, int size){
    if(index >= size){
        return Head; // Base case: when all elements are inserted
    }

    if(Head == NULL){
        curr = new Node(arr[index]);
        Head = curr;
    }else{
        while(curr->next){
            curr = curr->next; // Traverse to the last node
        }
        curr->next = new Node(arr[index]); // Insert at the end
    }
    return CreateLinkedListFromEnd(Head, curr, arr, index+1, size);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = size(arr);
    
    Node *Head = NULL;
    Head = CreateLinkedListFromBeginning(Head, arr, 0, n);
    Head = CreateLinkedListFromEnd(Head, Head, arr, 0, n);

    // Traversing and printing the linked list
    for(int i=0;i<5;i++){
        cout<<Head->data<<" ";
        Head = Head->next;
    }
}