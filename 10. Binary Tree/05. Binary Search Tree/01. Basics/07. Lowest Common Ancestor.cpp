#include <iostream>
using namespace std;

/*
---------------------------------------------------------------
🟩 Problem Statement:
---------------------------------------------------------------
🔹 Problem Name: Lowest Common Ancestor in a Binary Search Tree (BST)
🔹 Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

Given a Binary Search Tree (BST) and two nodes `n1` and `n2`, the task is to find their **Lowest Common Ancestor (LCA)**.
The LCA of two nodes `n1` and `n2` is defined as the deepest node in the BST that has both `n1` and `n2` as descendants 
(where a node can be a descendant of itself).

---------------------------------------------------------------
🟦 Time and Space Complexity:
---------------------------------------------------------------
🔸 Time Complexity: O(h)
    - Where `h` is the height of the BST. In the worst case, h = N (for skewed trees); 
      in average cases for balanced BSTs, h = log(N).
🔸 Space Complexity: O(h)
    - Due to the recursion call stack. Tail recursion might be optimized, but generally O(h).

---------------------------------------------------------------
🟨 Step-by-Step Approach:
---------------------------------------------------------------
✅ 1. **Base Case**:
    - If the current root is NULL, return NULL (end of the tree reached).

✅ 2. **Comparison Logic**:
    - Since it's a BST, all values in the left subtree of a node are smaller than the node,
      and all values in the right subtree are larger.

    🔸 If both `n1` and `n2` have values **less than** `root->data`, LCA must be in the **left** subtree.
    🔸 If both `n1` and `n2` have values **greater than** `root->data`, LCA must be in the **right** subtree.
    🔸 If one of `n1` or `n2` is on the left and the other on the right (or one equals the root),
       then the **current root** is their **Lowest Common Ancestor**.

✅ 3. **Recursively** apply the same logic until the correct root is found.

---------------------------------------------------------------
🟥 Visual Diagram:
---------------------------------------------------------------
Example Tree:
                 20
               /    \
             10      30
            /  \    /  \
           5   15  25  35

Suppose n1 = 5, n2 = 15

Step-by-step:
    - Start at root = 20
    - Both 5 and 15 are < 20 → go left to 10
    - 5 < 10 and 15 > 10 → split path → LCA = 10 ✅

Another Example:
Suppose n1 = 5, n2 = 30

Step-by-step:
    - Start at root = 20
    - 5 < 20 and 30 > 20 → split path → LCA = 20 ✅

---------------------------------------------------------------
🟦 Additional Notes:
---------------------------------------------------------------
- This logic leverages the BST property to avoid traversing the entire tree.
- It's important to use node pointers (not just values) to properly apply recursion.
- If this were a normal binary tree (not a BST), a completely different approach (postorder traversal) would be needed.

---------------------------------------------------------------
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


Node *lca(Node *root, Node *n1, Node *n2){
    if(!root){
        return NULL;
    }

    // go for left part 
    if(root->data > n1->data && root->data > n2->data){
        return lca(root->left, n1, n2);
    }else if(root->data < n1->data && root->data < n2->data){
        return lca(root->right, n1, n2);
    }else{
        return root;
    }
}

int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    Node *n1;
    Node *n2;

    // we can't test it here because we don't have pointer memory of n1 and n2
    lca(root, n1, n2);
}
