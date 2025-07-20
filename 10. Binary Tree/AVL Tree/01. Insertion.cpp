#include <iostream>
using namespace std;

/*
-------------------------------------------------------------------
🧠 Problem: AVL Tree Insertion  
🔗 Link: https://www.geeksforgeeks.org/problems/avl-tree-insertion/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

📌 Objective:
Implement insertion in an **AVL Tree**, which is a type of **self-balancing Binary Search Tree (BST)**. After every insertion, we check if the tree becomes unbalanced. If it does, we apply the necessary **rotations** to make it balanced again.

-------------------------------------------------------------------
⏱️ Time Complexity:
- Each insertion takes **O(log N)** time in a balanced AVL tree due to height balancing.

💾 Space Complexity:
- **O(h)** auxiliary stack space used in recursion, where `h` is the height of the tree (O(log N) in balanced AVL trees).

-------------------------------------------------------------------
🌳 What is an AVL Tree?
An AVL tree is a special type of Binary Search Tree where:
- Every node stores its height.
- After each insertion or deletion, the **balance factor** (difference between left and right subtree heights) is checked.
- If a node becomes **unbalanced** (balance factor > 1 or < -1), we restore balance using **tree rotations**.

🧮 Balance Factor = height(left subtree) - height(right subtree)

-------------------------------------------------------------------
📐 ROTATION STRATEGIES (to fix imbalances):

1️⃣ Left-Left (LL) Case:
    New node is inserted into the **left subtree of left child**.
    👉 Perform a **Right Rotation** on the unbalanced node.

      Before:
          z
         /
        y
       /
      x

      After:
        y
       / \
      x   z

2️⃣ Right-Right (RR) Case:
    New node is inserted into the **right subtree of right child**.
    👉 Perform a **Left Rotation** on the unbalanced node.

      Before:
      z
       \
        y
         \
          x

      After:
        y
       / \
      z   x

3️⃣ Left-Right (LR) Case:
    New node is inserted into the **right subtree of left child**.
    👉 Perform a **Left Rotation** on left child, then **Right Rotation** on unbalanced node.

      Before:
          z
         /
        y
         \
          x

      After:
          x
         / \
        y   z

4️⃣ Right-Left (RL) Case:
    New node is inserted into the **left subtree of right child**.
    👉 Perform a **Right Rotation** on right child, then **Left Rotation** on unbalanced node.

      Before:
      z
       \
        y
       /
      x

      After:
        x
       / \
      z   y

-------------------------------------------------------------------
🔍 Step-by-Step Insertion Logic:

1. **Insert node** using regular Binary Search Tree logic (left for smaller, right for greater).
2. After insertion, **update the height** of the current node.
3. **Check balance factor** of the node:
   - If |balance| ≤ 1 → tree is balanced.
   - If |balance| > 1 → tree is unbalanced, so:
     - Identify the type of imbalance (LL, RR, LR, RL).
     - Perform appropriate rotation(s) to restore balance.

4. Rotations are:
   - Simple reattachment of pointers (left/right children).
   - Also update height values post-rotation.

-------------------------------------------------------------------
📊 Example Trace:

Insert in this order: 10 → 30 → 50

Initial Tree:
    10
      \
      30
        \
        50

This is a **Right-Right (RR)** case (unbalanced at 10), so apply **Left Rotation**:
    30
   /  \
  10   50

Balanced now!

Keep repeating for further insertions while maintaining AVL properties.

-------------------------------------------------------------------
🧪 Inorder Traversal:
Used to print the tree in **sorted ascending order** (Left → Root → Right).

-------------------------------------------------------------------
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


// AVL Tree: Its an tree that consits the property of Binary Tree, Binary Search Tree and also it is balanced
// So in every insertion, deletion and any updation process, tree should be balanced
// if its not then we have to balance it 

// rotation strategy
// 1. left left: 
// right rotation with top node 

// 2. right right: 
// left rotation with left node

// 3. left right: 
// left rotation with middle node 
// right rotation with top node 

// 4. right left:
// right rotation with middle Node
// left rotation with top node 


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

    inorder(root);

}


