#include <iostream>
using namespace std;


/*
===========================================================================================
🌳 Problem: Minimum Distance Between BST Nodes
🔗 Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

🎯 Objective:
Given a Binary Search Tree (BST), find the minimum difference between the values of any two different nodes. The values are guaranteed to be unique, and the BST property (left < root < right) always holds.

🕒 Time Complexity: O(n)
- Each node is visited exactly once using an in-order traversal.
- n = number of nodes in the tree.

🧠 Space Complexity: O(h)
- h = height of the tree due to recursive call stack.
- In the worst case (skewed tree), h = n.

===========================================================================================
🧭 Step-by-Step Explanation:

1️⃣ Build the Binary Tree:
- The `tree()` function takes input from the user recursively.
- Input format:
  - Enter an integer value.
  - If the value is `-1`, it means there is no node (i.e., NULL).
  - After each value, you are prompted to enter the left and right children.
- This builds a binary tree structure manually for testing.

2️⃣ Core Function: `minDist()`
- Performs an **in-order traversal** of the BST (left → root → right).
- Since it's a BST, this traversal will visit the nodes in **sorted order**.
- During traversal:
  - Keep track of the **previous visited node** using `prev`.
  - At each step, calculate the difference between current node and previous node.
  - Update `ans` if this difference is smaller than the previous smallest.

3️⃣ Final Output:
- After the traversal, `ans` will contain the minimum difference between any two nodes.

===========================================================================================
🧠 BST Property Reminder:

In a BST:
- Left Subtree has smaller values
- Right Subtree has greater values

So an **in-order traversal** gives values in ascending order.

For example:
      4
     / \
    2   6
   / \
  1   3

In-order traversal: 1 → 2 → 3 → 4 → 6

Differences: 
- (2-1) = 1  
- (3-2) = 1  
- (4-3) = 1  
- (6-4) = 2  
Minimum = 1

===========================================================================================
📊 Visual Example:

Consider the following tree built from user input:

Input: 4 2 1 -1 -1 3 -1 -1 6 -1 -1

Resulting Tree:
            4
          /   \
        2       6
      /   \
     1     3

In-order traversal:
        1 → 2 → 3 → 4 → 6

Traversal steps and updates:
- Start with `prev = INT_MIN`, `ans = INT_MAX`
- Visit 1 → nothing to compare
- Visit 2 → ans = min(INT_MAX, 2 - 1) = 1
- Visit 3 → ans = min(1, 3 - 2) = 1
- Visit 4 → ans = min(1, 4 - 3) = 1
- Visit 6 → ans = min(1, 6 - 4) = 1

✅ Final answer: 1

===========================================================================================
✅ Best Practices:
- Always use **in-order traversal** for sorted node access in BST.
- Use `INT_MIN` and `INT_MAX` to initialize comparisons safely.
- Keep recursive logic clean and tail-recursive where possible for large trees.
===========================================================================================
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


void minDist(Node *root, int &prev, int &ans){
    if(!root){
        return;
    }

    minDist(root->left, prev, ans);
    if(prev != INT_MIN){
        ans = min(ans, root->data - prev);
    }

    prev = root->data;
    minDist(root->right, prev, ans);
}


int main(){
    cout<<"Enter the root Node: ";
    Node *root = tree();

    int prev = INT_MIN;
    int ans = INT_MAX;

    minDist(root, prev, ans);
}