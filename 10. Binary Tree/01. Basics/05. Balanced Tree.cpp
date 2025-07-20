#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
Problem: Check if a Binary Tree is Height-Balanced
--------------------------------------------------------------------------------

📌 Problem Statement:
Given a binary tree, determine whether it is *height-balanced*. A binary tree is 
considered height-balanced if, for **every node**, the height difference between 
its left and right subtrees is **at most 1**. 
This means allowed height differences are: -1, 0, or 1.

🔗 Problem Link:
GeeksforGeeks – Check for Balanced Tree  
https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

--------------------------------------------------------------------------------
⏱️ Time Complexity:

- `O(N)` where N is the number of nodes in the tree.
    - Each node is visited exactly once to compute the height and check balance.

🧠 Space Complexity:

- `O(H)` where H is the height of the tree (due to the recursive call stack).
    - Worst case: O(N) if the tree is skewed.
    - Best case: O(log N) if the tree is balanced.

--------------------------------------------------------------------------------
🪜 Step-by-Step Explanation:

1. The binary tree is constructed using recursive pre-order traversal.
    - The user is asked to enter node values.
    - A value of `-1` represents a NULL (empty) node.

2. The function `height()` recursively calculates the height of each subtree.
    - At each node, it computes:
        - The height of the left subtree.
        - The height of the right subtree.

3. The difference between the left and right subtree heights is checked:
    - If `abs(left - right) > 1`, the tree is marked as invalid using a boolean flag `valid`.

4. The main function prints whether the binary tree is balanced.

--------------------------------------------------------------------------------
🖼️ Visual Diagram:

Balanced Binary Tree Example:
```

```
      1
     / \
    2   3
   / \
  4   5
```

Left height of root = 2 (via node 2 → 4/5)
Right height of root = 1 (via node 3)
|2 - 1| = 1 → ✅ Balanced

```

Unbalanced Binary Tree Example:
```

```
      1
     /
    2
   /
  3
```

Left height = 2
Right height = 0
|2 - 0| = 2 → ❌ Not Balanced

```
--------------------------------------------------------------------------------
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

    Node *temp = new Node(x);
    cout<<"Enter the left child of "<<x<<": ";
    temp->left = tree(); // creating left node and storing to its parent
    cout<<"Enter the right child of "<<x<<": ";
    temp->right = tree(); // creating right node and storing its address to the parent
    return temp;
}


int height(Node *root, bool &valid){
    if(!root){
        return 0;
    }

    int left = height(root->left, valid);
    int right = height(root->right, valid);

    if(abs(left - right) > 1){
        valid = 0;
    }

    return 1 + max(left, right);
}

int main(){
    cout<<"Enter the root Node: ";

    Node * root = tree();
    bool valid = 1;

    height(root, valid);
    cout<<"Is Valid Tree: "<<(valid == 1 ? "True":"False");
}

