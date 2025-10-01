#include <iostream>
using namespace std;

/*
===============================================================================
🧠 Problem: Deletion in an AVL Tree  
🔗 Link: https://www.geeksforgeeks.org/problems/avl-tree-deletion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

📌 Objective:
To **delete a node from an AVL tree** such that the **tree remains height-balanced**.  
AVL Tree is a self-balancing Binary Search Tree (BST). After each deletion, 
the balance factor of every node is checked, and **rotations** are applied 
if the tree becomes unbalanced.

===============================================================================
⏱️ Time Complexity:
- **O(log N)** for deletion in a balanced AVL tree.
- This includes finding the node, deleting it, and balancing the tree.

💾 Space Complexity:
- **O(h)** auxiliary space, due to recursion stack (where h = height of tree).

===============================================================================
🌳 What is an AVL Tree?
An AVL Tree is a **Binary Search Tree** that ensures **balance at every node**.
Balance Factor = Height(left subtree) - Height(right subtree)

👉 Balance Factor values:
- -1, 0, 1 ➝ Tree is balanced
- < -1 or > 1 ➝ Tree is unbalanced → Needs rotation

===============================================================================
🔁 Rotations to Balance the Tree:

After deletion, there are **4 cases** to fix unbalance using tree rotations:

1️⃣ **Left-Left (LL) Case**:
    - Balance > 1 AND left child’s balance ≥ 0
    - ✅ Perform **Right Rotation**

      Before:               After:
          z                  y
         /                  / \
        y      →           x   z
       /
      x

2️⃣ **Right-Right (RR) Case**:
    - Balance < -1 AND right child’s balance ≤ 0
    - ✅ Perform **Left Rotation**

      Before:              After:
      z                      y
       \                    / \
        y     →            z   x
         \
          x

3️⃣ **Left-Right (LR) Case**:
    - Balance > 1 AND left child’s balance < 0
    - ✅ First **Left Rotate left child**, then **Right Rotate current node**

      Before:               After:
         z                   x
        /      →           / \
       y                  y   z
        \
         x

4️⃣ **Right-Left (RL) Case**:
    - Balance < -1 AND right child’s balance > 0
    - ✅ First **Right Rotate right child**, then **Left Rotate current node**

      Before:              After:
      z                      x
       \      →            / \
        y                 z   y
       /
      x

===============================================================================
🧩 Step-by-Step Deletion Logic in AVL Tree:

1. 🔍 **Search for the node** to be deleted using BST rules:
   - If key < root, go left
   - If key > root, go right
   - If key == root → this is the node to delete

2. ⚒️ **Delete the node**:
   - If it’s a **leaf node** → just remove it.
   - If it has **one child** → replace node with its child.
   - If it has **two children**:
     - Replace the node’s value with the **smallest value in its right subtree** (called inorder successor).
     - Delete that smallest node from the right subtree.

3. 🔄 **Update the height** of the current node.

4. ⚖️ **Check the balance factor**:
   - If unbalanced, apply one of the 4 rotation cases above.

===============================================================================
🌱 Inorder Traversal:
After all operations, an **inorder traversal** is performed to print the elements in sorted order.

===============================================================================
📊 Example:

Insert these values:
10, 30, 50, 20, 5, 60, 25, 40

Tree (before deletion):
                30
              /    \
            10      50
           /  \     / \
          5   20  40  60
               \
               25

Delete: 20

After deletion:
20 is replaced with 25, and rotations are applied if needed to maintain balance.

===============================================================================
*/


class Node{
    public:
    int data;
    int height;
    Node * left, *right;

    Node(int value){
        data = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node *root){
    if(!root){
        return 0;
    }
    return root->height;
}

int getBalance(Node *root){
    return getHeight(root->left) - getHeight(root->right);
}

Node * leftRotation(Node *root){
    Node *child = root->right;
    Node *leftChild = child->left;

    // attach root node, left to the child
    child->left = root;
    // attach leftchild, right to the root
    root->right = leftChild;

    // adjust height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    // because child is now the root node
    return child;
}

Node * rightRotation(Node *root){
    Node *child = root->left;
    Node *rightChild = child->right;

    // attach root node, right to the child
    child->right = root;
    // attach rightchild, left to the child
    root->left = rightChild;

    // adjust height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    // because child is now the root node
    return child;
}

Node * insert(Node *root, int key){
    if(!root){
        return new Node(key);
    }

    // insert key
    if(key < root->data){
        root->left = insert(root->left, key);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
    }
    // if key equals to root, then skip it
    // duplicate elements are not allowed
    else{
        return root;
    }

    // update root height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // check from which side tree is unbalanced
    // if value is greater than 1 than its left unbalanced
    // if is lower than -1 than its right unbalnaced 
    // else its balanced
    int balance = getBalance(root);

    // unbalanced tree
    // left left unbalanced
    if(balance > 1 && root->left->data > key){
        return rightRotation(root);
    }

    // right right unbalanced
    else if(balance < -1 && root->right->data < key){
        return leftRotation(root);
    }

    // left right unbalanced
    else if(balance > 1 && root->left->data < key){
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // right left unbalanced
    else if(balance < -1 && root->right->data > key){
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    // balanced tree
    else{
        return root;
    }

}


Node * deleteNode(Node *root, int key){
    if(!root){
        return NULL;
    }

    // go to left part
    if(root->data > key){
        root->left = deleteNode(root->left, key);
    }
    // go to right part
    else if(root->data < key){
        root->right = deleteNode(root->right, key);
    }
    // found the node to delete
    else{
        // leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // single child exists
        else if(root->left && !root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exists
        else{
            // we prefer to go to right part and find the smallest node
            // which will found on the left most part and then replace its value with root
            Node *curr = root->right;
            // loop through till left node exists
            while(curr->left){
                curr = curr->left;
            }

            // replace the root node's value with smallest node's value
            root->data = curr->data;
            
            // now execute function call to delete this smallest node
            root->right = deleteNode(root->right, curr->data);
        }
    }

    // start balancing tree if its unbalanced

    // update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // get balance
    int balance = getBalance(root);

    // left part
    if(balance > 1){
        // here we have to check which rotation should follow LL or LR 
        // if balance is positive follow LL 
        if(getBalance(root->left) >= 0){
            return rightRotation(root);
        }
        // else follow LR
        else{
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    //right part
    else if(balance < -1){
        // here we have to check which rotation should follow RR or RL
        // if balance is lower than equals to 0 follow RR
        if(getBalance(root->right) <= 0){
            return leftRotation(root);
        }
        // else follow RL
        else{
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    // tree is balanced
    else{
        return root;
    }
}


void inorder(Node *root){
    if(!root){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node * root = NULL;

    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 60);
    root = insert(root, 25);
    root = insert(root, 40);

    root = deleteNode(root, 20);
    inorder(root);

}


