#include <iostream>
using namespace std;


/*
----------------------------------------------------------------------
🧠 Problem Statement:
Construct a Binary Search Tree (BST) from a given preorder traversal.

🔗 Problem Link:
LeetCode - Construct Binary Search Tree from Preorder Traversal:
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

🎯 Objective:
Given an array representing the preorder traversal of a Binary Search Tree (BST), the goal is to reconstruct the BST from it.

📊 Time and Space Complexity:
- Time Complexity: O(n), where n is the number of elements in the preorder array.
  - Each element is inserted exactly once in the tree.
- Space Complexity: O(n), due to recursion stack and memory allocation for nodes.

📘 Step-by-Step Explanation:

1. **BST Basics Recap**:
   - In a BST:
     - Left subtree contains nodes less than the root.
     - Right subtree contains nodes greater than the root.

2. **Preorder Traversal**:
   - Preorder traversal visits nodes in the order: Root ➝ Left ➝ Right.
   - Using this order, we can rebuild the BST by placing each element into its correct position.

3. **Recursive Construction Using Bounds**:
   - We maintain a running index `index` to track the current element in the preorder list.
   - For each element:
     - If it's within the current valid range (`lower < element < upper`), it is a valid node.
     - Construct a new node.
     - Recursively assign its left child with an updated upper bound as the current node's value.
     - Recursively assign its right child with a lower bound as the current node's value.
   - If an element is not in the valid range, return `NULL` (not part of this subtree).

📊 Example:
For input `preOrder = [8, 5, 1, 7, 10, 12]`

Step-by-step Tree Building:
```

```
           8
         /   \
       5      10
     /  \       \
    1    7       12
```

```

Preorder Traversal:
```

Visit 8 ➝ Go left to 5 ➝ Go left to 1 ➝ No more left ➝ Go right to 7 ➝ Backtrack ➝ Go right to 10 ➝ Go right to 12
\=> Output: 8 5 1 7 10 12

```

📊 Diagram of Recursive Range Update:
```

Function Call Tree with Range (lower, upper):

build\_tree(\[8,5,1,7,10,12], 0, -∞, ∞)
│
├── Node(8)
│   ├── build\_tree(..., -∞, 8)
│   │   └── Node(5)
│   │       ├── build\_tree(..., -∞, 5)
│   │       │   └── Node(1)
│   │       └── build\_tree(..., 5, 8)
│   │           └── Node(7)
│   └── build\_tree(..., 8, ∞)
│       └── Node(10)
│           └── build\_tree(..., 10, ∞)
│               └── Node(12)

```

✅ Best Practices:
- Always use boundary checks (`lower`, `upper`) to enforce BST rules.
- Pass index by reference to maintain its state across recursive calls.
- Use `INT_MIN` and `INT_MAX` from `limits.h` to define the global range.

----------------------------------------------------------------------
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


void preTravarsal(Node *root){
    if(!root){
        return;
    }

    cout<<root->data<<" ";
    preTravarsal(root->left);
    preTravarsal(root->right);
}

Node *build_tree(vector<int> preOrder, int &index, int lower, int upper){
    if(
        index >= preOrder.size() || 
        (preOrder[index] < lower || preOrder[index] > upper)
    ){  
        return NULL;
    }

    Node *root = new Node(preOrder[index++]);
    // range for left part
    root->left = build_tree(preOrder, index, lower, root->data);
    // range for right part
    root->right = build_tree(preOrder, index, root->data, upper);

    return root;
}

int main(){
    vector<int>preOrder = {8,5,1,7,10,12};
    int index = 0;

    // range variables
    int lower = INT_MIN;
    int upper = INT_MAX;
    Node *root = build_tree(preOrder, index, lower, upper);
    preTravarsal(root);
}
