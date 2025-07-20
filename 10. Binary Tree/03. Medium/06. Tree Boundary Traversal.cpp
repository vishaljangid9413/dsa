#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
📌 Problem: Boundary Traversal of Binary Tree
--------------------------------------------------------------------------------

🔗 Problem Link:  
GeeksforGeeks – https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

🎯 Objective:
Given a binary tree, print its boundary traversal in **anti-clockwise direction** starting from the root.

Boundary traversal includes:
1. **Left boundary (excluding leaf nodes)**
2. **All leaf nodes (left to right)**
3. **Right boundary (excluding leaf nodes) — in reverse order**

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Time Complexity: **O(N)**  
- Each node is visited once while traversing left boundary, leaves, and right boundary.

✅ Space Complexity: **O(N)**  
- In the worst case (like a skewed tree), recursive calls and result array can take O(N) space.

--------------------------------------------------------------------------------
🪜 Step-by-Step Approach:

We divide the traversal into three parts, each handled by a separate helper function.

🔹 1. `leftBoundary()`:
- Traverse the tree from the root's left child down to the bottom.
- Add only boundary nodes (not leaf nodes).
- Prioritize left child; if left doesn’t exist, use the right child.

🔹 2. `leafNode()`:
- Recursively traverse the entire tree.
- Add nodes that have no left or right children (i.e., leaf nodes).
- Includes leaf nodes from both left and right subtrees.

🔹 3. `rightBoundary()`:
- Traverse from the root’s right child down to the bottom.
- Skip leaf nodes.
- Prioritize right child; if not present, go left.
- Since we need to print in **bottom-up** order, we push node values **after recursion**.

🔹 Main Function:
- Start by adding the root node to the result.
- Then call the above three functions in order:
  - Left boundary → leaf nodes → right boundary

--------------------------------------------------------------------------------
🧠 Visual Diagram:

Let’s consider this example tree:

```

```
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
        \    
         8
```

Boundary traversal:
→ Left boundary: 2 → 4
→ Leaf nodes: 4, 5, 8, 7
→ Right boundary (bottom-up): 3

Result: 1 2 4 5 8 7 3

```

Traversal Order Breakdown:
```

Step 1: Add root:                 \[1]
Step 2: Add left boundary:        \[1, 2, 4]
Step 3: Add leaf nodes:           \[1, 2, 4, 5, 8, 7]
Step 4: Add right boundary (rev): \[1, 2, 4, 5, 8, 7, 3]

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
    temp->right = tree(); // cretaing right node and storing its address to the parent
    return temp;
}

void leftBoundary(Node *root, vector<int> &ans){
    if(!root || (!root->left && !root->right)){
        return;
    }

    ans.push_back(root->data);
    
    // give priority to left node 
    // if the current node do not have left node then go to right node
    if(root->left){
        leftBoundary(root->left, ans);
    }else{
        leftBoundary(root->right, ans);
    }
}

void leafNode(Node *root, vector<int> &ans){
    if(!root){
        return;
    }

    if(!root->left && !root->right){
        ans.push_back(root->data);
    }

    leafNode(root->left, ans);
    leafNode(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans){
    if(!root || (!root->left && !root->right)){
        return;
    }

    // give priority to right node 
    // if right node does not exist then go to left node 
    if(root->right){
        rightBoundary(root->right, ans);
    }else{
        rightBoundary(root->left, ans);
    }

    // and we have to print right boundary element in reverse order 
    // so for it we have to push the node elements in ans only 
    // when the recurrsive array is returning 
    // this will add element in reverse order 
    ans.push_back(root->data);
}


int main(){
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    vector<int>ans;

    // add root node first 
    ans.push_back(root->data);

    if(root->left || root->right){
        leftBoundary(root->left, ans);
        leafNode(root, ans);
        rightBoundary(root->right, ans);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}