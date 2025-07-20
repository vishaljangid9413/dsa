#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
Problem: Constructing a Binary Tree in C++ using Two Methods
--------------------------------------------------------------------------------

📌 Problem Statement:
This code demonstrates two standard ways to construct a binary tree in C++:
1. Level-wise construction (`first_method`) using a queue and breadth-first traversal.
2. Recursive pre-order construction (`second_method`) based on depth-first traversal.

The binary tree is built from user input. A value of `-1` denotes a `NULL` node.
This is often asked in interviews and seen in platforms like LeetCode, GFG, etc.

🔗 Reference: Basic binary tree construction problem
(GFG Practice) https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

--------------------------------------------------------------------------------
⏱️ Time Complexity:

1. `first_method` (Level-wise):
    - O(N) where N is the number of nodes
    - Each node is visited exactly once during insertion.

2. `second_method` (Recursive Pre-order):
    - O(N) where N is the number of nodes
    - Each node is visited during recursive construction.

🧠 Space Complexity:

1. `first_method`:
    - O(N) for the queue used during level-wise construction

2. `second_method`:
    - O(H) due to the recursive call stack where H is the height of the tree
    - Worst case (skewed tree): O(N), Best case (balanced tree): O(log N)

--------------------------------------------------------------------------------
🪜 Step-by-Step Approach:

✅ `first_method` (Level-order Tree Construction)
- Step 1: Ask user to input the root node value.
- Step 2: Use a queue to process nodes in breadth-first order.
- Step 3: For each node, ask for its left and right child values.
  - If input is not -1, create the node and enqueue it.
- Step 4: Repeat until queue is empty.

✅ `second_method` (Recursive Tree Construction)
- Step 1: Ask user to input the root node value.
- Step 2: If value is -1, return NULL (base case).
- Step 3: Recursively repeat for left and right children.
- Step 4: Return root node after both children are constructed.

--------------------------------------------------------------------------------
🖼️ Visual Diagram:

Let’s say the user inputs the following values (pre-order):

```

Input Sequence for `second_method`:
1
/&#x20;
2   3
/   /&#x20;
4   -1  5

Input Order (via console):
1 → 2 → 4 → -1 → -1 → -1 → 3 → -1 → 5 → -1 → -1

Final Tree Structure:

```
      1
     / \
    2   3
   /     \
  4       5
```

```

📌 Notes:
- `first_method` is useful for level-order problems like inserting nodes at specific levels.
- `second_method` mirrors the structure of many recursion-based tree problems (like DFS, serialization, etc.)

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

// creating a binary tree 

// levelwise
void first_method(){
    queue<Node *>q;
    int left, right;

    int x;
    cout<<"Enter the root element: ";
    cin>>x;

    Node *root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        cout<<"Enter the left child of "<<temp->data<<" : "; 
        cin>>left;
        if(left != -1){
            temp->left = new Node(left);
            q.push(temp->left);
        }

        cout<<"Enter the right child of "<<temp->data<<" : "; 
        cin>>right;
        if(right != -1){
            temp->right = new Node(right);
            q.push(temp->right);
        }
    }
}


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
    temp->right = tree(); // cretaing right node and storing its address to the parent
    return temp;
}

void second_method(){
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();
}


int main(){
    // first_method()
    second_method();
}