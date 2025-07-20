#include<iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
📌 Problem: Construct Binary Tree from Inorder and Postorder Traversal
--------------------------------------------------------------------------------

🔗 Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
💡 Type: Tree Construction, Recursion, Divide & Conquer
🎯 Goal: Reconstruct a unique binary tree from given inorder and postorder traversal arrays.

--------------------------------------------------------------------------------
🧠 Concept:

Inorder (L → Root → R) and Postorder (L → R → Root) traversals are two different
ways to traverse a binary tree. Given both traversals of the **same** tree,
we can **reconstruct the original binary tree**.

### Example:
Given:
- Inorder   = [4, 8, 2, 5, 1, 6, 3, 7]
- Postorder = [8, 4, 5, 2, 6, 7, 3, 1]

The tree formed from these traversals is:

                     1
                   /   \
                 2       3
               /  \     / \
              4    5   6   7
                \
                 8

--------------------------------------------------------------------------------
⏱️ Time Complexity:
- `O(N^2)` in the worst case because we perform a linear search (`find()`) to locate the root in the inorder array for every node.
  - `N` nodes × `O(N)` search each = `O(N^2)`
- Can be optimized to `O(N)` using a hash map to store inorder indices (not done here).

🧠 Space Complexity:
- `O(H)` for recursive call stack, where `H` is the height of the tree (can go up to `O(N)` in skewed trees).
- Extra `O(1)` space apart from recursion.

--------------------------------------------------------------------------------
🪜 Step-by-Step Approach (Beginner-friendly Explanation):

1. **Understand the Traversals**:
   - The **last** element in postorder is always the **root** of the current subtree.
   - The inorder array splits into **left subtree** and **right subtree** around the root.

2. **Recursive Strategy**:
   - Maintain an index pointing to the current root in the postorder array (starting from the end).
   - Create a new node with the value at that index.
   - Find this value in the inorder array. This gives you the boundary between left and right subtrees.
   - First, recursively build the **right subtree** (because postorder is L → R → Root).
   - Then, recursively build the **left subtree**.
   - Decrease the postorder index after placing each node.

3. **Base Case**:
   - If `inStart > inEnd`, return `NULL` as there's no subtree to build.

--------------------------------------------------------------------------------
🖼️ Diagram: Visual Representation of Recursive Tree Construction

Input:
- Inorder   = [4, 8, 2, 5, 1, 6, 3, 7]
- Postorder = [8, 4, 5, 2, 6, 7, 3, 1]

Construction Flow (Reverse Postorder):

1. `index = 7 → 1` → Root
2. Find 1 in inorder → `position = 4`
   - Left Subtree → inorder[0..3]
   - Right Subtree → inorder[5..7]

⬇ Recursive Breakdown:

```

```
      1
    /   \
 (L)     (R)
2         3
```

/ \       /&#x20;
4   5     6   7

8

```

Traversal splits happen recursively at each step:
- For Node 2 → inorder[0..3] → left of 1
- For Node 3 → inorder[5..7] → right of 1
- and so on...


--------------------------------------------------------------------------------
*/

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int find(vector<int>inorder, int target, int inStart, int inEnd){
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}


Node* build_tree(vector<int>inorder, vector<int>postorder, int inStart, int inEnd, int &index){
    if(inStart > inEnd){
        return NULL;
    }
    Node * root = new Node(postorder[index]);
    int position = find(inorder, root->data, inStart, inEnd);

    index--;
    root->right = build_tree(inorder, postorder, position + 1, inEnd, index);
    root->left = build_tree(inorder, postorder, inStart, position - 1, index);
    return root;
}


int main(){
    vector<int>inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int>postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    int n = postorder.size();
    int index = n -1;
    build_tree(inorder, postorder, 0, n-1, index);
}