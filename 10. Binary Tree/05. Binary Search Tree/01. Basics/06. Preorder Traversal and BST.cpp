#include <iostream>
using namespace std;

/*
Problem: Validate Preorder Traversal of a Binary Search Tree (BST)
Link: https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1?page=1&difficulty%5B%5D=1&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

---------------------------------------------------------------------------------------
🧠 Problem Statement:
You're given an array that represents the **preorder traversal** of a binary search tree (BST). Your task is to determine whether this preorder traversal can actually represent a valid BST.

Preorder traversal means:  
- Visit **Root**, then **Left Subtree**, then **Right Subtree**

A valid BST follows this rule:
- Left subtree values < root
- Right subtree values > root

Return 1 (true) if it can represent a BST, else return 0 (false).

---------------------------------------------------------------------------------------
⏱️ Time Complexity:
- **O(N)** where N is the number of nodes (length of preorder array).  
  Each node is visited once, and range checking is constant time.

🧠 Space Complexity:
- **O(N)** in the worst case for recursion stack, especially if the BST is skewed.

---------------------------------------------------------------------------------------
🪜 Step-by-Step Logic:

1. Start with index 0 of the `preOrder` array.
2. Use **recursive boundaries** defined by `lower` and `upper` to simulate BST properties:
   - For the left subtree, values must be within `[lower, current_value)`
   - For the right subtree, values must be within `(current_value, upper]`
3. At each step:
   - Check if `preOrder[index]` is out of the allowed range → if yes, return (invalid path).
   - Otherwise, move the index forward and make recursive calls for left and right subtrees using updated bounds.
4. Finally, after recursion, if the entire array has been traversed (`index == n`), the preorder is valid.

---------------------------------------------------------------------------------------
📊 Diagram (Example):

Let’s take `preOrder = {10, 5, 1, 7, 40, 50}`

Valid BST:
```

```
     10
    /  \
   5   40
  / \    \
 1   7    50
```

```

Traversal: Root (10) → Left Subtree (5 → 1 → 7) → Right Subtree (40 → 50)

At each recursive call, value must fit within its valid range:
- For node 5 → range = [INT_MIN, 10]
- For node 1 → range = [INT_MIN, 5]
- For node 7 → range = [5, 10]
- For node 40 → range = [10, INT_MAX]
- For node 50 → range = [40, INT_MAX]

If any value breaks these bounds, the sequence is invalid.

---------------------------------------------------------------------------------------
🎯 Important:
- The function is purely checking validity of the sequence with **range constraints**, not building the tree.
- The global `index` helps track the next unprocessed node in the preorder sequence.
*/

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void is_preorder(vector<int> preOrder, int &index, int lower, int upper, int n){
    if(
        index >= n || 
        (preOrder[index] < lower || preOrder[index] > upper)
    ){
        return;
    }

    int value = preOrder[index++];
    // range for left part
    is_preorder(preOrder, index, lower, value, n);
    // range for right part
    is_preorder(preOrder, index, value, upper, n);
}

int main(){
    vector<int>preOrder = {2, 4, 3};
    int n = 3;
    int index = 0;

    // range variables
    int lower = INT_MIN;
    int upper = INT_MAX;
    is_preorder(preOrder, index, lower, upper, n);
}