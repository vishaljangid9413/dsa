#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------------------------------
💡 Problem Name: Fix Two Nodes of a BST  
🔗 Problem Link: https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1?page=1&difficulty%5B%5D=2&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

🧩 Problem Statement:
You're given a Binary Search Tree (BST), but two of its nodes have been swapped by mistake. 
You need to fix the tree by swapping the two wrong nodes back to restore the correct BST structure, 
*without* changing the overall structure of the tree.

📌 Note:  
- In a correct BST, an **inorder traversal** should give elements in **sorted order**.
- If two elements are swapped, this order breaks in at most two places.
- Your task is to find the two incorrect nodes and swap them back.

--------------------------------------------------------------------------------------------------------

⏱️ Time Complexity:
- `O(n)` where n is the number of nodes in the BST. Every node is visited once using Morris Traversal.

🧠 Space Complexity:
- `O(1)` → Because we're using **Morris Traversal**, which does not require recursion or a stack.

--------------------------------------------------------------------------------------------------------

🔍 Step-by-Step Approach:

1. **Inorder Traversal Observation**:
   - Inorder traversal of a BST should return sorted values.
   - If two nodes are misplaced, the sorted order will break at **one or two points**.

2. **Morris Traversal (Threaded Binary Tree)**:
   - Traverse the BST **inorder without using extra space**.
   - Temporarily modify the tree structure by making threads between nodes.
   - This avoids using recursion or an explicit stack.

3. **Detect the Incorrect Nodes**:
   - During Morris Inorder traversal, compare the current node (`present`) with the previous node (`last`).
   - If `last->data > present->data`, it violates BST property:
     - First such violation: store `first = last` and `second = present`
     - Second violation (if it exists): update only `second = present`

4. **Fix the Tree**:
   - After traversal, swap the values of `first` and `second` to fix the BST.

--------------------------------------------------------------------------------------------------------

📊 Visualization Diagram of Morris Traversal and Violation Detection:

Let's say BST was:

          10
         /  \
        5   20
           /
         [8]

This is incorrect: 8 is on the right of 10, which violates BST rules.

➡ Inorder traversal should be: [5, 10, 8, 20] ❌  
➡ Correct BST should be: [5, 8, 10, 20]

💥 Violation points:
- 10 > 8 ⇒ First wrong pair → `first = 10`, `second = 8`

🛠️ Swap:
- Swap values of `10` and `8`, fix the BST.

Final structure becomes:

          8
         /  \
        5   20
           /
         10

✅ Inorder: [5, 8, 10, 20] (Correct)

--------------------------------------------------------------------------------------------------------

🧠 Key Concepts Used:
- Binary Search Tree property
- Inorder traversal
- Morris traversal (O(1) space)
- Threading in binary trees (temporary links)
--------------------------------------------------------------------------------------------------------
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


void trav(Node *root){
    if(!root){
        return;
    }

    trav(root->left);
    cout<<root->data<<" ";
    trav(root->right);
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();
    Node * rootCopy = root;

    Node *curr = NULL;
    Node *present = NULL, *last = NULL;
    // defective nodes
    Node *first = NULL, *second = NULL;

    // using morris travarsal
    while(root){
        // check if left node exists
        // if not then go to right node
        if(!root->left){

            // find the defected nodes
            last = present;
            present = root;
            // check if last exists
            // and last is greater than persent, it means the data is not sorted
            if(last && last->data > present->data){
                // if first not exists update it
                if(!first){
                    first = last;
                }
                second = present;
            }

            // go to the right part
            root = root->right;
        }else{
            curr = root->left;

            // go to rightest element till its not null or 
            // it is not equals to root node 
            while(curr->right && curr->right != root){
                curr = curr->right;
            }

            // Left subtree not traversad
            // if node is equals to NULL
            // it means we have to connect it to the root node 
            if(!curr->right){
                curr->right = root;
                root = root->left;
            }

            // Left subtree is already traversed
            // if node is already connected to root, go to right part 
            else{
                // disconnect the node with root
                curr->right = NULL;

                // find the defected nodes
                last = present;
                present = root;
                // check if last exists
                // and last is greater than persent, it means the data is not sorted
                if(last && last->data > present->data){
                    // if first not exists update it
                    if(!first){
                        first = last;
                    }
                    second = present;
                }

                root = root->right;
            }
        }
    }

    // now swap the defective nodes to fix the BST
    int num = first->data;
    first->data = second->data;
    second->data = num;

    trav(rootCopy);
}
