#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
📌 Problem: Maximum Path Sum Between Two Leaf Nodes
--------------------------------------------------------------------------------

🔗 Problem Link:  
GeeksforGeeks – https://www.geeksforgeeks.org/problems/maximum-path-sum/1

🎯 Objective:
Given a binary tree, find the **maximum path sum between two leaf nodes**.  
The path must **start and end at two different leaf nodes**, and it must **pass through their Lowest Common Ancestor (LCA)**.

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Time Complexity: **O(N)**  
- We visit each node exactly once in a post-order DFS.

✅ Space Complexity: **O(H)**  
- H = height of the tree → due to recursion stack (worst-case: skewed tree → O(N))

--------------------------------------------------------------------------------
🪜 Step-by-Step Approach:

1. **Understand "Special Nodes"**:
   - Special nodes are **leaf nodes** (nodes with no left or right children).
   - The valid path must start and end at **two leaf nodes**.

2. **Traversal Strategy**:
   - Use a **recursive post-order traversal**.
   - For each node, recursively calculate the maximum root-to-leaf path sums for its left and right subtrees.

3. **Compute Maximum Path Sum**:
   - At any node with **both left and right children**, a potential **leaf-to-leaf path** can be:
     ```
     left_sum + root->data + right_sum
     ```
     Update global max if this sum is greater.

4. **Return Value to Parent**:
   - To its parent, each node returns:
     ```
     root->data + max(left, right)
     ```
     Because the parent only needs one path to extend.

5. **Edge Case**:
   - If the tree has only one leaf (like skewed left or right trees), we can't form a valid leaf-to-leaf path.
   - In that case, the **maximum root-to-leaf sum** becomes the valid answer.

--------------------------------------------------------------------------------
🧠 Visual Diagram:

Example Tree:
````

```
    10
   /  \
 -2    7
 / \
8  -4
```

```

Leaf-to-leaf path with maximum sum:
```

8 → -2 → 10 → 7
Sum = 8 + (-2) + 10 + 7 = **23**

```

What Happens:
- Node -2:
  - Left leaf = 8
  - Right leaf = -4
  - pathSum = 8 + (-2) + (-4) = 2 (not max)
- Node 10:
  - Left sum = 6 (from -2)
  - Right sum = 7
  - pathSum = 6 + 10 + 7 = **23** ✅

--------------------------------------------------------------------------------
✅ Best Practices:

- Always update the global `sum` **only** when both left and right children are present. This ensures you're measuring **leaf-to-leaf** paths.
- Return root-to-leaf sum to parent since parent can only continue one direction.
- Handle edge case where only one child exists (skewed trees).

--------------------------------------------------------------------------------
📎 Interview Tip:

This is a **classic recursive tree DP** question. A similar variant asks for the **maximum path sum between any two nodes** (not just leaves).  
Make sure you know the difference in constraints!

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

int findPath(Node *root, int &sum){
    if(!root){
        return 0;
    }

    // a leaf node
    if(!root->left && !root->right){
        return root->data;
    }

    int left = findPath(root->left, sum);
    int right = findPath(root->right, sum);

    if(root->left && root->right){
        sum = max(sum, root->data + left + right);
        return root->data + max(left, right);
    }

    // edge case don't find sum in this case
    if(root->left){
        return root->data + left;
    }

    if(root->right){
        return root->data + right;
    }
}

int main(){
    cout<<"Enter the root Node: ";
    Node *root = tree();

    int sum = INT_MIN;
    int maxPath = findPath(root, sum);

    // if root is not a special node
    if(root->left && root->right){
        cout<< sum;
    }
    // and if root is special node, 
    // because at this time sum is int_min so the actual value should be root->data
    else{
        cout<< max(sum, maxPath);
    }
}
