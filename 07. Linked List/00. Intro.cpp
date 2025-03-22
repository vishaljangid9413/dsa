#include <iostream>
#include <vector>
using namespace std;

// Problem Statement:
// Implement a singly linked list with operations to insert elements at the front, insert at the end,
// insert at a specific position, delete a node at a specific position, and iterate through the list.

// Approach:
// 1. Use a class `Node` to represent each node in the linked list.
// 2. Implement insertion at the front by adjusting the head pointer.
// 3. Implement insertion at the end by finding the tail and appending the new node.
// 4. Implement insertion at a given position by traversing the list to the desired index.
// 5. Implement deletion by adjusting pointers to skip the target node.
// 6. Implement iteration to print the list.

// Time Complexity:
// - Insertion at the front: O(1)
// - Insertion at the end: O(N) (finding tail takes O(N) initially)
// - Insertion at a specific position: O(N) (traversing to the position)
// - Deletion at a specific position: O(N) (traversing to the position)
// - Iterating through the list: O(N)

// Space Complexity: O(N) (for storing N nodes in the linked list)

// Definition of a single node
class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        this->next = NULL;
        this->data = value;
    }
};

// Function to insert elements at the front of the linked list
Node * insert_element_at_front(int arr[], Node *head){
    // Iterating through the array and inserting each element at the front
    for(int i=0; i<4; i++){
        if (head == NULL){
            head = new Node(arr[i]); // Creating head if list is empty
        }else{
            Node *temp = new Node(arr[i]);
            temp->next = head;
            head = temp; // Moving head to new node
        }
    }
    return head;
}

// Function to insert elements at the end of the linked list
Node * insert_element_at_end(int arr[], Node *head){
    Node * tail = head;

    // Finding the tail (last node) of the existing list
    if(tail){
        while(tail->next){
           tail = tail->next;
        }
    }

    // Iterating through the array and inserting elements at the end
    for(int i=0; i<4; i++){
        if(head == NULL){
            head = new Node(arr[i]);
            tail = head;
        }else{
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }
    return head;
}

// Function to insert a node at a specific position in the linked list
Node * insert_node(int x, int value, Node * head){
    if(head == NULL){
        return head;
    }
    
    Node * new_node = new Node(value);
    
    // If inserting at the first position
    if(x == 1){
        new_node->next = head;
        head = new_node;
    }else{
        Node *temp = head; 
        Node *prev;

        x--; // Adjust position for 0-based index
        while(x--){
            prev = temp;
            temp = temp->next;    
        }
        prev->next = new_node;
        prev->next->next = temp;
    }
    return head;
}

// Function to delete a node at a specific position
Node * delete_node(int x, Node * head){
    if(head == NULL){
        return head;
    }

    Node * curr = head;
    Node * prev = NULL;

    // If deleting the first node
    if(x == 1){
        head = curr->next;
        delete curr;
    }else{
        // Traversing to the node before the target node
        while(--x){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
    return head;
}

// Function to iterate through the linked list and print its elements
void iterate_list(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data << " "; // Printing node data
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the linked list operations
int main(){
    int arr[] = {4, 5, 6, 7};
    Node *Head = NULL;

    // Insert elements at the end
    Head = insert_element_at_end(arr, Head);

    // Insert element at a particular position
    // int x = 3;
    // int value = 40;
    // Head = insert_node(x, value, Head);

    // Delete element at a particular position
    int x= 3;
    Head = delete_node(x, Head);

    // Print the linked list
    iterate_list(Head);
}
