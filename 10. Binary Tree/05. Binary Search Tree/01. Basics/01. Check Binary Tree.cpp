#include <iostream>
using namespace std;


/***************************************************************************************
Problem: Check if a Binary Tree is a Binary Search Tree (BST)
Link: https://www.geeksforgeeks.org/problems/check-for-bst/1?page=1&difficulty

Overview:
----------
The task is to check whether a given binary tree is a Binary Search Tree (BST) or not.
A Binary Search Tree is a binary tree where the following conditions must hold:
1. The left subtree of a node contains only nodes with keys **less than** the node’s key.
2. The right subtree of a node contains only nodes with keys **greater than** the node’s key.
3. Both the left and right subtrees must also be binary search trees.

Approaches:
-------------
This code provides **two methods** to solve the problem.

📌 Method 1: Using Inorder Traversal Array (Extra Space)
---------------------------------------------------------
1. Inorder traversal of a BST always yields elements in **strictly increasing order**.
2. We perform an inorder traversal and store the result in a vector.
3. We check if the vector is sorted in strictly increasing order.
4. If yes, the tree is a BST. Otherwise, it is not.

- ✅ Time Complexity: O(n)  
- ✅ Space Complexity: O(n) (extra space used for storing inorder traversal)

📌 Method 2: Using Inorder Traversal with a Previous Value Variable (No Extra Space)
-------------------------------------------------------------------------------------
1. Perform a recursive inorder traversal.
2. Keep track of the **previous node’s value** using a variable `prev`.
3. If the current node’s value is **not greater** than the previous one, it’s not a BST.
4. Return false immediately on violation.

- ✅ Time Complexity: O(n)
- ✅ Space Complexity: O(h) for recursion stack (h = height of the tree), no extra array is used

Special Note:
--------------
BST validation must follow **strictly increasing order**, not just non-decreasing. 
This means **duplicates are not allowed** in a valid BST (as per the standard definition used in this problem).

--------------------------------------------------------------------------------------------------
🧠 Simple Diagram to Understand Logic Flow (Method 2):
--------------------------------------------------------------------------------------------------

                       10
                      /  \
                    5     15
                   / \   /  \
                 2   7 12   20

Inorder Traversal ➝ [2, 5, 7, 10, 12, 15, 20] ✔️ Sorted ⇒ Valid BST ✅

Now, imagine a faulty tree:
                       10
                      /  \
                    5     8
                         /
                        12

Inorder Traversal ➝ [5, 10, 12, 8] ❌ Not Sorted ⇒ Not a BST ❌

--------------------------------------------------------------------------------------------------
🪄 Best Practices & Tips:
--------------------------------------------------------------------------------------------------
- Always validate left and right subtrees recursively when checking BST properties.
- Be careful with edge cases like duplicates or INT_MIN/INT_MAX values.
- In production or interviews, prefer the second method due to **space efficiency**.
- Use clear naming and modular functions (`isBST`, `validate`, `inorder`) for clarity.

***********************************************************************************************/


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


// Link: https://www.geeksforgeeks.org/problems/check-for-bst/1?page=1&difficulty
// we just have to check that the current tree is binary tree or not
// so for this we just have to find its inorder travarsal
// if its inorder travarsal is in asending order, that means its a BST 


void findInorder(Node *root, vector<int> &inorder){
    if(!root){
        return;
    }

    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}


// time complexity = O(n)
// space complexity = O(n)
void first_method(Node *root){

    vector<int> inorder;
    findInorder(root, inorder);

    // verify that the values are in ascending order
    bool is_bst = true;

    for(int i=1;i<inorder.size();i++){
        if(inorder[i - 1] >= inorder[i]){
            is_bst = false;
        }
    }
    cout<<is_bst;
}


bool findBST(Node *root, int &prev){
    if(!root){
        return 1;
    }

    bool left = findBST(root->left, prev);
    if(left == 0){
        return 0;
    }

    if(root->data <= prev){
        return 0;
    }
    prev = root->data;

    return findBST(root->right, prev);
}

// time complexity = O(n)
// space complexity = O(n)
// but without extra vector space 
void second_method(Node *root){
    int prev = INT_MIN;
    bool is_bst = findBST(root, prev);
}

int main(){
    cout<<"Enter the root Node: ";
    Node *root = tree();

    first_method(root);
    second_method(root);
}