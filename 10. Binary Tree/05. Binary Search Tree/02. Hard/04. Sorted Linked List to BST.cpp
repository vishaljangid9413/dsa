#include <iostream>
using namespace std;


/*
=======================================================================
🟩 Problem Name:
Sorted Linked List to Balanced BST

🧠 Problem Link:
https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1?page=1&difficulty[]=2&category[]=Binary%20Search%20Tree&sortBy=submissions

🎯 Problem Statement:
You are given a **sorted singly linked list**. Your task is to convert this linked list into a **balanced Binary Search Tree (BST)**. A balanced BST is one where the difference in height between the left and right subtrees is at most 1 for every node.

✅ Objective:
Convert the sorted linked list into a balanced BST such that the in-order traversal of the BST gives back the original sorted order.

🧠 Key Insight:
The **middle element** of the sorted list should be the **root** of the BST. Then, recursively apply the same logic on the left and right halves of the list to build the left and right subtrees, respectively. This ensures the tree remains balanced.

📈 Time Complexity:
- **O(n)**: Each element is visited exactly once during the linked list to vector conversion and once during tree construction.

📦 Space Complexity:
- **O(n)**: For storing the list into a vector.
- **O(h)**: Stack space used by recursion during tree construction (where `h` is the height of the BST ≈ log(n)).

⚙️ Step-by-Step Approach:

1. **Convert Linked List to Vector:**
   - Traverse the linked list and insert each value into a vector.
   - This simplifies access using index positions, which is required to find the middle element quickly.

2. **Build Tree Recursively:**
   - Find the **middle index** of the vector (or subvector).
   - Create a new tree node with the middle element as its value.
   - Recursively repeat the process for the left sub-array and the right sub-array to form the left and right subtrees.

3. **Preorder Traversal:**
   - Used here to verify the structure of the final BST.

📊 Diagram to Visualize the Logic:

Let the sorted linked list be:  
`1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7`

Convert to array:  
`[1, 2, 3, 4, 5, 6, 7]`

Construct BST recursively:
```

```
        4
      /   \
     2     6
    / \   / \
   1   3 5   7
```

```
- Step 1: Mid of [1..7] is 4 → root node
- Step 2: Mid of [1..3] is 2 → left child
- Step 3: Mid of [5..7] is 6 → right child
- Recursively apply the same logic to build full tree

This approach guarantees that the height of the BST is minimal and well-balanced.

📌 Note:
In competitive programming, converting linked list to array before constructing BST is a common simplification technique due to the sequential access nature of linked lists.
=======================================================================
*/

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class LNode {
    public:
    int data;   // Stores the integer value of the node
    LNode *next; // Pointer to the next node in the list

    // Constructor to initialize the node with a given value
    LNode(int value) {
        this->next = NULL;
        this->data = value;
    }
};

// create a linked list
LNode *CreateLinkedListFromEnd(int arr[], int index, int size) {
    if (index == size) {
        return NULL; // Base case: If index reaches size, return NULL
    }

    // Create a new node for the current array element
    LNode *temp = new LNode(arr[index]);

    // Recursively call for the next element in the array
    temp->next = CreateLinkedListFromEnd(arr, index + 1, size);

    return temp;
}

// create a tree
Node * tree(){
    int x;
    cin>>x;
    if(x == -1){
        return NULL;
    }

    Node *root = new Node(x);
    cout<<"Enter left child of "<<root->data<<": ";
    root->left = tree();
    cout<<"Enter right child of "<<root->data<<": ";
    root->right = tree();
    return root;
}

// Link: https://www.geeksforgeeks.org/problems/sorted-list-to-bst/1?page=1&difficulty[]=2&category[]=Binary%20Search%20Tree&sortBy=submissions
// We have given a sorted linked list, we have to create a balanced BST with it 
// So first we will convert ll to array, and build a tree with 
// find middle and devide strategy 

// time complexity = O(n)
// space complexity = O(n)/O(h)


Node *buildTree(vector<int>inorder, int start, int end){
    if(start > end){
        return NULL;
    }

    // we have odd number of elements and find middle
    // in this problem we should consider the rounded number 
    // ex: if we got 1.5 middle then we should consider 2 not 1
    // to solve this we just have to add +1 this will handle odd and even both condition 

    int mid = start + (end - start + 1)/2;

    Node *root = new Node(inorder[mid]);
    root->left = buildTree(inorder, start, mid - 1);
    root->right = buildTree(inorder, mid + 1, end);
    return root;
}

void preorderTravarsal(Node *root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    preorderTravarsal(root->left);
    preorderTravarsal(root->right);
}

int main(){
    // we don't have any predefined list so we just start with array 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Input array
    int n = size(arr); // Size of the array

    LNode *Head = NULL; 
    Head = CreateLinkedListFromEnd(arr, 0, n); // Create the linked list

    // now convert this list into vector
    vector<int>inorder;

    while(Head){
        inorder.push_back(Head->data);
        Head = Head->next;
    }

    // now create tree
    Node *root = buildTree(inorder, 0, n - 1);
    preorderTravarsal(root);

}
