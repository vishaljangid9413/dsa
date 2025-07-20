#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
🧠 Problem Name: Compute the Height of a Binary Tree
--------------------------------------------------------------------------------

📌 Problem Statement:
This program allows the user to:
1. Build a binary tree using recursive pre-order traversal input.
2. Compute the **height** (also called the depth) of the constructed binary tree.

➡️ **Height of a Binary Tree** is defined as the number of nodes on the longest
path from the root to a leaf. If a tree is empty, its height is 0.

🔗 Reference:
GeeksforGeeks: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Tree Construction (`tree()`):
- Time Complexity: O(N) — Each node is visited exactly once.
- Space Complexity: O(H) — Due to the recursive call stack (H = height of the tree).

✅ Height Calculation (`height()`):
- Time Complexity: O(N) — Every node is visited once to compute height.
- Space Complexity: O(H) — Due to recursive stack used to traverse from root to leaves.

Where:
- N = total number of nodes in the tree
- H = height of the tree (in worst case, H = N for skewed trees)

--------------------------------------------------------------------------------
🪜 Step-by-Step Explanation:

1. 📥 Input Phase (tree construction using `tree()`):
   - The user is prompted to enter an integer value.
   - If the input is `-1`, it denotes a NULL (no node).
   - Otherwise, create a node with the entered value.
   - Recursively ask for the left and right children of this node.
   - This mimics a **pre-order traversal (Root → Left → Right)** for tree construction.

2. 🌲 Example Input (User):
```

Enter the root Node: 1
Enter the left child of 1: 2
Enter the left child of 2: 4
Enter the left child of 4: -1
Enter the right child of 4: -1
Enter the right child of 2: -1
Enter the right child of 1: 3
Enter the left child of 3: -1
Enter the right child of 3: -1

```

3. 🌳 Tree Built:
```

```
    1
   / \
  2   3
 /
4
```

```

4. 🧮 Height Calculation (`height(root)`):
   - This function uses **post-order recursion**.
   - It returns `1 + max(left height, right height)` for each node.
   - The function recurses down to the leaves and builds the height bottom-up.

5. 🧾 Final Output:
   - In the above tree, the longest path is 1 → 2 → 4, so the height = 3.

--------------------------------------------------------------------------------
🖼️ Diagram: Binary Tree and Height Calculation

                 1
                / \
               2   3
              /
             4

🔍 Heights:
- height(4) = 1
- height(2) = 1 + height(4) = 2
- height(3) = 1
- height(1) = 1 + max(height(2), height(3)) = 1 + max(2,1) = 3


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


int height(Node *root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int main(){
    // create a tree first
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    cout<<height(root);
    
}