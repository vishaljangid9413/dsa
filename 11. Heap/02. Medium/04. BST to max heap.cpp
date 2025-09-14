#include <iostream>
using namespace std;

/***************************************************************
 Problem Name: Convert BST to Max Heap
 Problem Link: https://www.geeksforgeeks.org/problems/bst-to-max-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions

 ---------------------------------------------------------------
 Problem Statement:
 Given a Binary Search Tree (BST), the task is to convert it into a 
 special type of Max Heap. The conditions are:
   1. The heap property must be satisfied (parent ≥ children).
   2. Additionally, every node’s left subtree must contain values 
      smaller than all the values in its right subtree.

 ---------------------------------------------------------------
 Time Complexity:
   - O(n), where n is the number of nodes in the BST.
     Reason: We perform an inorder traversal (O(n)) to get the sorted 
     sequence of elements and a postorder traversal (O(n)) to 
     reconstruct the heap.
 
 Space Complexity:
   - O(n), due to storing the inorder traversal of the tree.

 ---------------------------------------------------------------
 Step-by-Step Approach:
 1. **Inorder Traversal of BST**:
      - Perform an inorder traversal of the BST.
      - Inorder traversal of a BST always produces a sorted sequence 
        of elements.
      - Example: For BST = [4, 2, 6, 1, 3, 5, 7]
        Inorder Result = [1, 2, 3, 4, 5, 6, 7]

 2. **Postorder Traversal to Assign Values**:
      - Perform a postorder traversal of the BST (Left → Right → Root).
      - While visiting nodes in postorder, assign them values from the 
        sorted `inorder` array (in order).
      - This ensures that:
         - Parent nodes get larger values than children → Max Heap.
         - Left subtree values are always smaller than right subtree values.

 3. **Why This Works**:
      - Inorder gives sorted order (ascending).
      - Postorder ensures we assign the smallest numbers to the 
        deepest nodes first, and the largest numbers to the root last.
      - Hence, the Max Heap property is satisfied.

 ---------------------------------------------------------------
 Visualization:
 
 Example BST:
 
          4
        /   \
       2     6
      / \   / \
     1   3 5   7

 Inorder Traversal = [1, 2, 3, 4, 5, 6, 7]

 Postorder traversal order of nodes = [1, 3, 2, 5, 7, 6, 4]

 Assign inorder values in this postorder sequence:

   Step 1: Node(1) ← 1
   Step 2: Node(3) ← 2
   Step 3: Node(2) ← 3
   Step 4: Node(5) ← 4
   Step 5: Node(7) ← 5
   Step 6: Node(6) ← 6
   Step 7: Node(4) ← 7

 Final Tree (Max Heap with special property):
 
          7
        /   \
       3     6
      / \   / \
     1   2 4   5

 This tree is a Max Heap:
   - Every parent is greater than its children.
   - Left subtree values are smaller than right subtree values.

 ---------------------------------------------------------------
 Key Insight:
   - The problem cleverly combines BST’s inorder property (sorted data)
     with heap’s postorder-based construction to satisfy both heap 
     constraints and the special left < right condition.
***************************************************************/


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

void find_inorder(Node *root, vector<int> &inorder){
    if(!root){
        return;
    }

    find_inorder(root->left, inorder);
    inorder.push_back(root->data);
    find_inorder(root->right, inorder);
}

void convert_to_heap(Node *root, vector<int> &inorder, int &index){
    if(!root){
        return;
    }
    convert_to_heap(root->left, inorder, index);
    convert_to_heap(root->right, inorder, index);
    root->data = inorder[index];
    index++;
}

void post_travars(Node *root){
    if(!root){
        return;
    }

    post_travars(root->left);
    post_travars(root->right);
    cout<<root->data<<" ";
}

int main(){
    cout<<"Enter the root node: ";

    Node *root;
    root = tree();

    // find inorder of tree
    vector<int>inorder;
    find_inorder(root, inorder);

    // covert currnet BST to Max heap
    int index = 0;
    convert_to_heap(root, inorder, index);
    post_travars(root);

}