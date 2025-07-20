#include <iostream>
using namespace std;


/*
=====================================================================================
🌲 Problem Set: Binary Search Tree (BST) Operations
📌 Covers:
   1. Insertion in BST 🔗 https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/
   2. Searching in BST 🔗 https://www.geeksforgeeks.org/problems/search-a-node-in-bst/
   3. Deletion from BST 🔗 https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/

=====================================================================================
🔍 Problem 1: Insertion in BST
🕒 Time Complexity: O(n) in worst-case (skewed tree), O(log n) in average case
🧠 Space Complexity: O(n) recursive call stack

👣 Approach:
- Start from the root.
- If the new value is smaller → go to the left child.
- If the new value is larger → go to the right child.
- Repeat until a `NULL` is found, then insert the node there.

📘 Example:
Insert: 6, 3, 17, 5  
Resulting Tree:
            6
          /   \
         3    17
          \
           5

=====================================================================================
🔍 Problem 2: Search in BST
🕒 Time Complexity: O(n) in worst-case, O(log n) on average
🧠 Space Complexity: O(n) due to recursion stack

👣 Approach:
- At each node:
  - If node's value == target → return `true`
  - If target < node → go left
  - If target > node → go right
- If you reach NULL → element doesn't exist.

📘 Example:
Search for: 5  
Path: 6 → 3 → 5 ✔️

=====================================================================================
🔍 Problem 3: Deletion in BST
🕒 Time Complexity: O(n)
🧠 Space Complexity: O(n)

🧩 Deletion Cases:
Case 1: Node has **no children** → Simply delete it  
Case 2: Node has **one child** → Replace node with its only child  
Case 3: Node has **two children** → Replace with **in-order predecessor**  
        (rightmost node of left subtree)

👣 Step-by-Step Logic:
1. Traverse to the node to delete.
2. Handle the 3 cases:
   - No child → delete directly.
   - One child → link child with parent.
   - Two children:
     a. Go to left subtree.
     b. Find the **maximum value** node (rightmost).
     c. Replace root with that node.
     d. Reconnect children appropriately.

🧠 Edge Case:
- If the rightmost node of the left subtree (in-order predecessor) has a left child,
  it should be reconnected to its parent before replacement.

📘 Example Deletion:

Original Tree:
            6
          /   \
         3    17
          \     \
           5     20

Delete: 17  
- In-order predecessor = 14 (if exists), else direct child used

Resulting Tree:
            6
          /   \
         3     20
          \
           5

=====================================================================================
📊 Tree Visual Guide:

Initial BST (from array {6, 3, 17, 5, 11, 8, 2, 1, 20, 14}):

                          6
                       /     \
                    3         17
                  /  \       /   \
                2    5    11     20
               /         \  
             1            8
                            \
                            14

🧨 Deleting node with value 17:
- Node 17 has two children: 11 and 20
- In-order predecessor: rightmost of left subtree (11 → 14)
- Replace 17 with 14, adjust links accordingly

Final Tree:

                          6
                       /     \
                    3         14
                  /  \       /   \
                2    5    11     20
               /         \  
             1            8

=====================================================================================
📌 Summary of Best Practices:
- Always handle all three deletion cases separately for clarity.
- Carefully manage pointers when moving nodes to preserve BST properties.
- For replacement during deletion, prefer in-order predecessor or successor for validity.
- Use recursive logic where possible for clean, elegant code.

=====================================================================================
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

void inorderTravarsal(Node *root){
    if(!root){
        return;
    }

    inorderTravarsal(root->left);
    cout<<root->data;
    inorderTravarsal(root->right);
}

Node * insertNode(Node *root, int target){
    if(!root){
        return new Node(target);
    }

    if(root->data > target){
        root->left = insertNode(root->left, target);
    }else{
        root->right = insertNode(root->right, target);
    }

    return root;
}


// time complexity = O(n^2)
// space complexity = O(n)
// Link: https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1?page=1&difficulty%5B%5D=0&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions
Node * insertion(int arr[], int n){
    Node *root = NULL;

    for(int i=0;i<n;i++){
        root = insertNode(root, arr[i]);
    }

    // inorderTravarsal(root);
    return root;
}


// time complexity = O(n);
// space complexity = O(n);
// Link: https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions
bool search(Node *root, int target){
    if(!root){
        return 0;
    }
    if(root->data == target){
        return 1;
    }

    if(root->data > target){
        return search(root->left, target);
    }else{
        return search(root->right, target);
    }
}


// time complexity = O(N)
// space complexity = O(N)
// Link: https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1?page=1&difficulty%5B%5D=1&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions
Node *deleteNode(Node *root, int target){
    if(!root){
        return NULL;
    }

    // check for left side of tree
    if(root->data > target){
        root->left = deleteNode(root->left, target);
        return root;
    }
    // check for right side of tree
    else if(root->data < target){
        root->right = deleteNode(root->right, target);
        return root;
    }
    // intiate the delete mechanism, if target find
    else{
        // no child exists
        if(!root->left && !root->right){
            // delete the child node and return null 
            // because node do not have any child to return 
            delete root;
            return NULL;
        }

        // one child exists
        // left child exists
        else if(!root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right cihld exists
        else if(!root->left){
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // both child exists
        else{
            // if both child exists then we have to find that child 
            // who is perfect to replace the current node, means if child is greater 
            // than nodes of left part and smaller than the nodes of right part 
            // for this, we prefer to search in left part, in left part we have to search the biggest element 
            // and biggest element always find in the right most node of the tree 
            // so we just iterate to that rightmost node, and point the left child of rightmost node 
            // to the its parent if the left child exists, and then replace the child with the root accordingly 

            Node *parent = root;
            Node *child = root->left;

            while(child->right){
                parent = child;
                child = child->right;
            }

            // here we have edge case that if the parent and root is same
            // then we have to handle them 
            if(root == parent){
                // we just have to point the right child of child to right child of root
                // because we have to replace the biggest child of left side with the deleting root node 
                // its simple, child is the left part of root, and there is also a right part of root
                // and we have to delete the root, so suppose from now child is new root, but child also have to 
                // connect with the right part of root, so root will be free and we can delete the root 
                child->right = root->right;
                delete root;
                return child;
            }
            // here we have travarsed through the right most child of left sub tree
            // so we have to replace this right most node with the replacable node
            // but we have to also concern about this node's child, it can't have any right child
            // because its a right most node, so maybe it consits a left child, so first we have to connect 
            // its left child with its parent, so it will be free, and once its free 
            // then we can connect the replacable nodes' left and right child with this right most node 
            // so the replacable node will be free and we can able to delete it
            else{
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main(){
    int arr[] = {6, 3, 17, 5, 11, 8, 2, 1, 20, 14};
    int n = size(arr);

    // insert element
    Node *root = insertion(arr, n);

    // search element
    // int target = 8;
    // bool hasElement = search(root, target);

    // delete node
    int target = 17;
    root = deleteNode(root, target);
    inorderTravarsal(root);
}