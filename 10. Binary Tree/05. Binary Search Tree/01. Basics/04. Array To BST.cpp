#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------------
🟩 Problem Name: Convert Sorted Array to Balanced BST  
🔗 Link: https://www.geeksforgeeks.org/problems/array-to-bst4443/1

🧠 Problem Statement:
You are given a sorted array (in increasing order), and your task is to convert it into a **Balanced Binary Search Tree (BST)**.
A **balanced BST** is a tree where the depth (height) of the left and right subtrees of every node differ by at most 1.

Example:
Input  : [1, 2, 3, 4]
Output : A balanced BST like:
         2
        / \
       1   3
              \
               4

✅ Goal: Use a recursive strategy to build a balanced BST from a sorted array.

--------------------------------------------------------------------------------------
⏱ Time and Space Complexity:

Time Complexity:  O(N)
- Each element is processed exactly once to insert it into the tree.

Space Complexity: O(log N) (Recursive Stack)
- For a balanced tree, the recursive depth is proportional to the height of the tree, which is log N in the best case.

--------------------------------------------------------------------------------------
🧩 Step-by-Step Approach (Divide and Conquer):

1. We are given a sorted array.
2. Choose the **middle element** of the current array segment as the root.
3. Recursively:
   - Build the **left subtree** using the left half of the array (start to mid - 1).
   - Build the **right subtree** using the right half of the array (mid + 1 to end).
4. This ensures both sides of the tree grow equally, keeping it **balanced**.

This is a **classic use-case of divide-and-conquer** where we break the problem into smaller balanced subproblems.

--------------------------------------------------------------------------------------
📊 Diagram (Visual Explanation):

Example Array: [1, 2, 3, 4]

Step-by-Step Construction:
----------------------------------
1. Full Array:        [1, 2, 3, 4]
   Middle:                 ↑
                          (2) ➝ root

2. Left Subarray:   [1]       → becomes left child
   Middle:             ↑
                      (1)

3. Right Subarray:     [3, 4]
   Middle:                 ↑
                          (3) ➝ becomes right child
                                 \
                                  4 → becomes right child of 3

Final Tree:
            2
           / \
          1   3
                 \
                  4

📌 Note: 
- This tree is balanced because the height difference between left and right subtrees of every node is ≤ 1.
- We do NOT modify or sort the array—it must already be sorted for this strategy to work correctly.

--------------------------------------------------------------------------------------
💡 Best Practice Notes:
- Always prefer using the middle index `(start + end) / 2` to keep the tree balanced.
- Use **preorder traversal** if you want to validate or print the tree structure after building.
- This approach is often used in **interview questions** to test recursion and binary tree understanding.

--------------------------------------------------------------------------------------
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

Node *build_tree(vector<int> arr, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = (start + end)/2;
    Node *root = new Node(arr[mid]);

    root->left = build_tree(arr, start, mid - 1);
    root->right = build_tree(arr, mid + 1, end);
    return root;
}

void preTravarsal(Node *root){
    if(!root){
        return;
    }

    cout<<root->data;
    preTravarsal(root->left);
    preTravarsal(root->right);
}

int main(){
    vector<int>arr = {1, 2, 3, 4};
    Node *root = build_tree(arr, 0, arr.size() - 1);

    preTravarsal(root);
}
