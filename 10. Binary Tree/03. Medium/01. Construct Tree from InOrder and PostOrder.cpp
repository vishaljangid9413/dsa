#include <iostream>
using namespace std;


/*
==================================================================================
🌳 Problem Title: Construct Binary Tree from Inorder and Preorder Traversals
🔗 Link: https://www.geeksforgeeks.org/problems/construct-tree-1/1

🧠 Problem Statement:
Given the `inorder[]` and `preorder[]` traversal arrays of a binary tree (with unique elements),
construct and return the root of the original binary tree.

Inorder Traversal:   Left -> Root -> Right  
Preorder Traversal:  Root -> Left -> Right

Your task is to build the binary tree from these two traversals.

----------------------------------------------------------------------------------
⏱ Time Complexity:
O(n²) - because for each node, we perform a linear search (`find_position()`) in the inorder array.

💾 Space Complexity:
O(n) - due to recursion stack and tree node storage.

(Note: This solution can be optimized to O(n) time using a hashmap for faster index lookups in `inorder[]`.)

----------------------------------------------------------------------------------
🔍 Step-by-Step Approach:

Let’s break this into smaller, easy-to-understand steps:

1. **Start from the beginning of the Preorder array** — because preorder starts with the root node.
2. **Use the current element of preorder[] as the root.**
3. **Search for this root's position in the inorder[] array.**
   - All elements **to the left** of the found position in `inorder[]` form the **left subtree**.
   - All elements **to the right** form the **right subtree**.
4. **Recursively** repeat the above steps for left and right subtrees using updated array bounds.
5. Finally, attach the left and right children to the root node and return it.

🧭 Visual Diagram:

Given:
```

inorder\[]   = \[1, 6, 8, 7]
preorder\[]  = \[1, 6, 7, 8]

```

**Step-by-step Tree Construction:**

1. preorder[0] = 1 → Root Node  
   - In inorder[], 1 is at index 0 → Left Subtree: [], Right Subtree: [6, 8, 7]

2. preorder[1] = 6 → Right Child of 1  
   - In inorder[], 6 is at index 1 → Left: [], Right: [8, 7]

3. preorder[2] = 7 → Right Child of 6  
   - In inorder[], 7 is at index 3 → Left: [8], Right: []

4. preorder[3] = 8 → Left Child of 7  
   - In inorder[], 8 is at index 2 → Leaf Node

Final Tree:
```

```
    1
     \
      6
       \
        7
       /
     8
```

```

Each recursive call narrows down the segment of the array to focus only on the left or right subtree.

==================================================================================
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


// this is used to find the position of the target element in given array 
int find_position(int inorder[], int target, int inStart, int inEnd){
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}


// we just have to travarse through preorder but verify the element inorder also 
// whenever we start and find an element first search its position in the inorder 
// after find position devide the array in two parts , and use index to find the current element to look

// for left node->
// array range: start with inStart and end till the position - 1 we find out
// index: increment the index by just 1, because we are travarsing from left to right 
// so just move it by one

// for right node->
// array range: start with the position + 1 and till inEnd 
/// index: increment the index by just 1, because we are travarsing from left to right 
// so just move it by one
// and then simply attach the results with the node and return root node 


Node *build_tree(int inorder[], int preorder[], int inStart, int inEnd, int &index){
    if(inStart > inEnd){
        return NULL;
    }
    Node * root = new Node(preorder[index]);
    int position = find_position(inorder, root->data, inStart, inEnd);
    index++;

    root->left = build_tree(inorder, preorder, inStart, position - 1, index);
    root->right = build_tree(inorder, preorder, position + 1, inEnd, index);
    return root;
}


int main(){
    int inorder[] = {1, 6, 8, 7};
    int preorder[] = {1, 6, 7, 8};

    int n = size(inorder);
    int index = 0;
    build_tree(inorder, preorder, 0, n-1, index);
}

