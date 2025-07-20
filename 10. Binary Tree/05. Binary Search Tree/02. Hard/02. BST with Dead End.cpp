#include <iostream>
using namespace std;

/*
====================================================================================
🟩 Problem Name: Check Whether BST Contains a Dead End
🔗 Problem Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

📝 Problem Statement:
You are given a **Binary Search Tree (BST)**. You need to determine whether the BST contains a **dead end**.

🔍 Definition of a Dead End:
A **dead end** is a leaf node (a node with no children) such that **no more nodes can be inserted** in the BST at that position while preserving the BST property.

➡️ Example:
Let's say we have the following BST:
```

```
    8
   / \
  4   9
 /
2
 \
  3
```

```
In the above BST:
- `3` is a leaf node.
- Range for inserting any child of `3` is `(2, 4)`. But since `2` and `4` are already used or invalid (in BST rules), no new node can be inserted.
- So, `3` is a **dead end**.

====================================================================================
⏱️ Time and Space Complexity:

✔️ Time Complexity: O(N)
- We traverse each node **once**, and do constant-time work per node.

✔️ Space Complexity: O(H)
- Due to **recursion stack** in DFS traversal.
- `H` is the height of the tree. Worst case (unbalanced) = O(N), Best case (balanced) = O(log N)

====================================================================================
🚶 Step-by-Step Approach:

1. We use a **recursive function `find()`** to check every node of the tree.
2. For each node, we keep track of the **valid range** `(low, high)` in which a node's value should lie.
    - For root, the range is (1, INT_MAX)
    - For left child: range becomes (low, root->data)
    - For right child: range becomes (root->data, high)
3. If the current node is a **leaf node** (no left or right child), we check:
    - Is it a dead end? i.e., `root->data - low == 1 && high - root->data == 1`
    - If both sides of the value are blocked (only 1 space on each side), no child can be inserted.
4. Recursively check left and right subtree.
5. If any leaf satisfies the dead-end condition, return `true`.

====================================================================================
📊 Diagram to Visualize Logic Flow:

          Input BST Example:
                  8
                 / \
                4   9
               /
              2
               \
                3

           Low-High Ranges during Recursion:

           ┌────────────┐
           │  Node 8    │  Range: (1, ∞)
           └────────────┘
                 ↓
           ┌────────────┐
           │  Node 4    │  Range: (1, 8)
           └────────────┘
                 ↓
           ┌────────────┐
           │  Node 2    │  Range: (1, 4)
           └────────────┘
                 ↓
           ┌────────────┐
           │  Node 3    │  Range: (2, 4)
           └────────────┘

        🔴 Node 3 is a leaf. Its left range = (2), right range = (4),
        but inserting values 2 or 4 would violate BST, so this is a dead end.

====================================================================================
💡 Note:
- The trick here is using **range constraints** to simulate the BST insert condition.
- This is a common technique used in BST problems to track valid insert locations.

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


bool find(Node *root, int low, int high){
    if(!root){
        return 0;
    }

    // find leaf node
    if(!root->left && !root->right){
        // check that the node is dead end or not
        // if the diff between data & low and high & data is equals to 1
        if(root->data - low == 1 && high - root->data == 1){
            return 1;
        }else{
            return 0;
        }
    }

    // return the remaining node response
    return find(root->left, low, root->data) || find(root->right, root->data, high);
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    int low = 0;
    int high = INT_MAX;
    bool is_end = find(root, low, high);
    cout<<is_end;

}
