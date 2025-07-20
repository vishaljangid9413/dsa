#include <iostream>
using namespace std;

/*
==================================================================================================================
💡 PROBLEM NAME: Mirror Tree  
🔗 PROBLEM LINK: https://www.geeksforgeeks.org/problems/mirror-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions  

📝 PROBLEM STATEMENT:
Given a binary tree, convert it into its mirror tree.
A mirror of a binary tree is another tree with left and right children of all non-leaf nodes swapped.

Example:
Input Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Output (Mirrored Tree):
        1
       / \
      3   2
     /   / \
    6   5   4

📈 TIME COMPLEXITY: O(N)
- We visit every node exactly once to perform the swapping.
- N is the number of nodes in the tree.

🧠 SPACE COMPLEXITY: O(H)
- Due to recursion, the call stack can go as deep as the height H of the tree.
- In worst-case (skewed tree), H = N.

🔍 STEP-BY-STEP EXPLANATION:
1. We start with the root node of the binary tree.
2. At each node:
   - Swap its left and right children.
3. Recursively repeat this process for:
   - Left subtree
   - Right subtree
4. This recursive traversal ensures all nodes are visited and their children swapped.

🎯 FUNCTIONAL OVERVIEW:
- `Node` class: Defines a tree node with a value and pointers to left/right children.
- `tree()` function: Takes input from user and builds the binary tree using recursion.
- `mirror()` function: Core logic to convert the binary tree into its mirror form.
- `main()` function: Initializes the root node, builds the tree, and then calls `mirror()` on it.

📊 VISUALIZATION:

            Original Tree                     Mirrored Tree
                 1                                 1
               /   \                             /   \
              2     3       ─────►              3     2
             / \     \                         /     / \
            4   5     6                       6     5   4

For each node:
➡ Swap `node->left` and `node->right`.
➡ Continue recursively for both children.

==================================================================================================================
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

void mirror(Node * root){
    if(root == NULL){
        return;
    }

    // swap the childs
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // do same thing with both the childs
    mirror(root->left);
    mirror(root->right);
}

int main(){
    // create a tree first
    cout<<"Create First Tree"<<endl;
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();
 
    mirror(root);
}