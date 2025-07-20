#include<iostream>
using namespace std;

/*
===============================================================================
🧠 Problem Name: Check Tree Traversal
🔗 Problem Link: https://www.geeksforgeeks.org/problems/check-tree-traversal--141628/1

📌 Problem Statement:
You are given three arrays: `preorder`, `inorder`, and `postorder` traversals of a binary tree. 
Your task is to check if these three arrays represent the same binary tree. That is, 
can we construct the same binary tree from (preorder + inorder) and (inorder + postorder)? 
If yes, return true (1); otherwise, return false (0).

===============================================================================
📊 Time & Space Complexity:

1. 🔁 `buildPre` and `buildPost`:
   - Time Complexity: O(n²) in the worst case (due to linear search in the `find()` function).
   - Space Complexity: O(n) due to recursive call stack and node allocations.

2. ✅ `identical` (tree comparison):
   - Time Complexity: O(n), where n is the number of nodes.
   - Space Complexity: O(h), where h is the height of the tree (recursion depth).

===============================================================================
🧩 Step-by-Step Approach:

1. 🏗️ Build the Binary Tree from Preorder and Inorder:
   - Preorder gives the root first. We use it to identify the current node.
   - Inorder helps divide the tree into left and right subtrees.
   - Recurse on left and right using adjusted boundaries in inorder.

2. 🏗️ Build the Binary Tree from Postorder and Inorder:
   - Postorder gives the root last. So, we move backwards.
   - Similar to above, use inorder to divide into left and right.

3. 🔍 Compare Both Trees:
   - Traverse both trees simultaneously.
   - At each node, check:
     - If both are NULL → continue.
     - If one is NULL → return false.
     - If values differ → return false.
   - Recursively check left and right subtrees.

4. 🧪 Output Result:
   - If the trees are identical, print `1` (true), else `0` (false).

===============================================================================
🧠 Tree Traversal Basics Recap:

- **Inorder (L, Root, R)**: Left → Root → Right
- **Preorder (Root, L, R)**: Root → Left → Right
- **Postorder (L, R, Root)**: Left → Right → Root

===============================================================================
📊 Visualization of the Tree Built from the Given Traversals:

Given:
Preorder:   [1, 2, 4, 5, 3]  
Inorder:    [4, 2, 5, 1, 3]  
Postorder:  [4, 5, 2, 3, 1]  

➡️ Tree constructed:

                1
              /   \
            2       3
          /   \
         4     5

⬇️ How this matches:
- Preorder starts with 1 → root is 1
- Inorder splits into [4, 2, 5] | 1 | [3] → left and right subtrees
- Postorder ends with 1 → confirms root
- Rest of traversals align if constructed correctly

===============================================================================
🧪 Example Walkthrough (Input):

    Preorder   = [1, 2, 4, 5, 3]
    Inorder    = [4, 2, 5, 1, 3]
    Postorder  = [4, 5, 2, 3, 1]

Output:
    1 (true)

Because both trees constructed from (pre+in) and (in+post) are identical.

===============================================================================
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


int find(int treeorder[], int target, int start, int end){
    for(int i=start;i<=end;i++){
        if(treeorder[i] == target){
            return i;
        }
    }
    return -1;
}

Node * buildPre(int preorder[], int inorder[], int start, int end, int &index){
    if(start > end){
        return NULL;
    }
    
    Node * root = new Node(preorder[index]);
    int position = find(inorder, root->data, start, end);
    if(position == -1){
        return NULL;
    }
    index++;
    root->left = buildPre(preorder, inorder, start, position - 1, index);
    root->right = buildPre(preorder, inorder, position + 1, end, index);
    return root;
}

Node * buildPost(int inorder[], int postorder[], int start, int end, int &index){
    if(start > end){
        return NULL;
    }
    
    Node * root = new Node(postorder[index]);
    int position = find(inorder, root->data, start, end);
    
    if(position == -1){
        return NULL;
    }
    index--;
    
    root->right = buildPost(inorder, postorder, position + 1, end, index);
    root->left = buildPost(inorder, postorder, start, position - 1, index);
    return root;
    
}

bool identical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    
    if((!r1 && r2) || (r1 && !r2)){
        return 0;
    }
    
    if(r1->data != r2->data){
        return 0;
    }
    
    return identical(r1->left, r2->left) && identical(r1->right, r2->right);
}
  
// Here, we have to first create the tree from (preorder and inorder )
// and (inorder and postorder), then compare them if they are identical or not 


int main(){
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[] = {4, 2, 5, 1, 3};
    int postorder[] = {4, 5, 2, 3, 1};

    int n = size(preorder);
    int preIndex = 0;
    int postIndex = n - 1;

    Node* preTree = buildPre(preorder, inorder, 0, n - 1, preIndex);
    Node* postTree = buildPost(inorder, postorder, 0, n - 1, postIndex);
    
    cout<< identical(preTree, postTree);
}