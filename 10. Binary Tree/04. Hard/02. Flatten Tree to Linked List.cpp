#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
📌 Problem: Flatten Binary Tree to Linked List
--------------------------------------------------------------------------------

🔗 Problem Link:  
GeeksforGeeks – https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

🎯 Objective:
Given a binary tree, flatten it to a linked list **in-place**.  
The flattened tree should look like a singly linked list using the tree’s right pointers and must follow the **pre-order traversal**.

🛠️ Rules:
- Every node's right child should point to the next node in pre-order.
- Every node's left child should be NULL.
- You are not allowed to use extra memory (in-place solution only).

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Time Complexity: **O(N)**  
- Each node is visited exactly once while restructuring the tree.

✅ Space Complexity: **O(1)**  
- No extra space is used beyond pointers (in-place operation).

--------------------------------------------------------------------------------
🪜 Step-by-Step Explanation:

We aim to transform this tree:

```

```
     1
   /   \
  2     5
 / \     \
3   4     6
```

```

Into this "linked list" structure using only right pointers:

```

1 -> 2 -> 3 -> 4 -> 5 -> 6

```

🔹 Key Idea:
- At each node:
  1. If the node has a left child:
     - Find the rightmost node (predecessor) of this left subtree.
     - Point that rightmost node’s right pointer to the current node’s right child.
     - Move the left subtree to the right.
     - Set the left pointer to NULL (since we only use right pointers).
  2. Move to the right child and repeat the process.

📌 This approach uses **Morris Traversal-style** logic — threading the tree without recursion or a stack.

--------------------------------------------------------------------------------
🧠 ASCII Diagram (Before and After Flattening):

Original Tree:
```

```
    1
   / \
  2   5
 / \   \
3   4   6
```

```

Flattened Tree (using right pointers only):
```

1 -> 2 -> 3 -> 4 -> 5 -> 6

```

Transformation Example:
- Node 1 has left child 2 → find rightmost node in 2’s subtree (i.e., 4)
- Link 4’s right to 1’s right (5)
- Move 2 to the right of 1 and nullify 1’s left

Repeat this until the entire tree is flattened.

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



// Here we have to convert a tree into a linked list 
// means every node points to its next node 
// but a tree node consits two child nodes so we prefer the right node 
// so we just connect every node to the right node 
// so for it first we check if the left doesn't exist 
// go to right node its simple 
// but if left node exist, then create a temp node that point the left node 
// and move it till it reach to the leaf node and then leaf node will 
// point to the right node of the root node 
// and then delete the link of root node with its right node 
// and point the root right node to the left node and delete the root left link
// because we have to travarse in sorted manner so directly pointing to the root right node 
// is not sorted and correct linking
// so do this process till the root become null


int main(){
    cout<<"Enter the root Node: ";
    Node *ans = tree();

    Node * root = ans;    
    while(root){
        if (!root->left){
            root = root->right;
        }else{
            Node *current = root->left;

            while(current->right){
                current = current->right;
            }

            // link the right leaf node with the root's right child
            current->right = root->right;
            // now points the root's right link to left child to mantain sorting
            root->right = root->left;
            // and remove the linking of left because we only prefer right link pointin 
            root->left = NULL;
            // move the root to right side 
            root = root->right;
        }
    }

    while(ans->right){
        cout<<ans->data<<" ";
        ans = ans->right;
    }
}