#include <iostream>
using namespace std;


/******************************************************************************************
Problem:
---------
✅ **Problem Name:** Sum of k smallest elements in BST  
🔗 **Problem Link:** https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1?page=1&difficulty[]=0&category[]=Binary%20Search%20Tree&sortBy=submissions  
📌 **Objective:** Given a Binary Search Tree (BST) and an integer `k`, find the sum of the k smallest elements in the BST.

-------------------------------------------------------------------------------------------
Time and Space Complexity:
--------------------------
⏱ **Time Complexity:** O(n) in the worst case, where `n` is the number of nodes in the BST.  
We may need to visit up to all `n` nodes to get the k smallest if `k` is close to `n`.

🗂 **Space Complexity:** O(h) where `h` is the height of the tree (for the recursive call stack).
- For a balanced BST, h = log(n).
- For a skewed tree, h = n.

-------------------------------------------------------------------------------------------
Approach and Logic:
--------------------
🧠 **Core Idea:**  
In a Binary Search Tree (BST), **inorder traversal** gives the nodes in **sorted (ascending)** order.  
To get the k smallest elements, we can perform an inorder traversal and:
1. Keep a counter `k` to track how many smallest elements we still need.
2. Keep a cumulative sum of the nodes we visit until `k` becomes zero.

🪜 **Step-by-Step Algorithm:**  
1. Start from the root.
2. Traverse the left subtree recursively (which contains smaller values).
3. If `k > 0`, add the current node's value to the sum and decrement `k`.
4. If `k == 0`, we stop further traversal (optimization).
5. Traverse the right subtree.

📘 **Example:**  
Consider the following BST and k = 3:

```

```
      5
     / \
    3   7
   / \
  2   4
 /
1
```

Inorder Traversal: \[1, 2, 3, 4, 5, 7]
k = 3 smallest elements: 1 + 2 + 3 = 6

```

🌲 **Visualization of BST:**
```

```
            5
          /   \
        3       7
      /   \
    2       4
  /
1
```

Inorder Sequence (left-root-right): 1 → 2 → 3 → 4 → 5 → 7
We take first 3: \[1, 2, 3] → Sum = 6

```

-------------------------------------------------------------------------------------------
Best Practices & Notes:
------------------------
✅ Use inorder traversal when dealing with sorted elements in a BST.  
✅ Early stopping when `k == 0` saves unnecessary computation.  
✅ Avoid global variables—pass them by reference for clean recursive handling.  
✅ This technique can be adapted to similar problems like finding the k-th smallest/largest element.

******************************************************************************************/

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


void find_sum(Node *root, int &k, int &sum){
    if(!root){
        return;
    }
    find_sum(root->left, k, sum);

    if(k > 0){
        sum = sum + root->data;
        k--;
    }else{
        return;
    }

    find_sum(root->right, k, sum);
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    int sum = 0;
    int k = 3;
    find_sum(root, k, sum);

    cout<<sum;
}
