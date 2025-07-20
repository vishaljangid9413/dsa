#include <iostream>
using namespace std;

/*
===================================================================================
🧠 Problem Name: Diagonal Traversal of Binary Tree  
🔗 Problem Link: https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1  

📌 Problem Statement:
You are given a binary tree. Your task is to perform **diagonal traversal** of the tree.  
In diagonal traversal, elements are grouped from top-right to bottom-left.  
For example, we move from root to its right child (same diagonal),  
and from any node to its left child (next diagonal).  

👀 Example:
            8
          /   \
        3      10
       / \       \
      1   6       14
         / \     /
        4   7   13

Diagonal Traversal:
→ Diagonal 0: [8, 10, 14]  
→ Diagonal 1: [3, 6, 7, 13]  
→ Diagonal 2: [1, 4]

📊 Output:  
8 10 14  
3 6 7 13  
1 4

===================================================================================
⏱ Time & Space Complexity:

🔁 Time Complexity: **O(n)**  
  - Every node is visited exactly once in recursion.  
  - So total operations = number of nodes = n  

🗃 Space Complexity: **O(n)**  
  - Because we're using a 2D vector to store elements diagonally.
  - Also, the recursion stack takes O(h) space, where h is height of tree.

===================================================================================
🪜 Step-by-Step Explanation:

✔️ Idea:
We traverse the tree recursively and track a `position` number:
- `position = 0` for root
- Move **left → position + 1** (because left goes to next diagonal)
- Move **right → same position** (right stays in the same diagonal)

We store nodes in a `vector<vector<int>> diagonals` using position as the index.

✔️ Step 1: Build the Tree Recursively
- `tree()` function asks the user to input node values.
- If `-1` is entered, it returns NULL (indicates no child).
- This continues to build left and right children recursively.

✔️ Step 2: Find Diagonal Depth (Range)
- Use `findRange()` to compute how many diagonals we may need.
- This updates the maximum diagonal level (`left`) by exploring all left children.

✔️ Step 3: Traverse & Collect Diagonals
- In `diagonalOrder()`, we recursively visit:
  - Right child → same diagonal
  - Left child → next diagonal (position + 1)
- We push node values to the correct index in the diagonals 2D vector.

✔️ Step 4: Print the Result
- Loop over the diagonals vector and print each level's nodes.

===================================================================================
📊 Diagram: Diagonal Traversal Visualization

Example Tree:
                1
              /   \
             2     3
            / \     \
           4   5     6
                  \
                   7

Traversal Flow:

👉 Diagonal 0 (position 0): [1, 3, 6]  
👉 Diagonal 1 (position 1): [2, 5, 7]  
👉 Diagonal 2 (position 2): [4]

          [1]
          /  \
        [2]   [3]
       /  \     \
     [4] [5]     [6]
              \
              [7]

Path Groupings:
- 1 → 3 → 6 are on same diagonal (right chain)
- 2 → 5 → 7 go one level down for each left movement
- 4 is deepest left descendant → last diagonal

===================================================================================
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


void findRange(Node *root, int position, int &left){
    if(root == NULL){
        return;
    }

    left = max(position, left);

    findRange(root->left, position +1, left);
    findRange(root->right, position, left);
}

void diagonalOrder(Node * root, vector<vector<int>> &diagonals, int position){
    if(!root){
        return;
    }

    diagonals[position].push_back(root->data);
    diagonalOrder(root->left, diagonals, position + 1);
    diagonalOrder(root->right, diagonals, position);
}

int main(){
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    int left = 0;
    findRange(root, 0, left);

    vector<vector<int>>diagonals(left + 1);

    int position = 0;
    diagonalOrder(root, diagonals, position);

    for(int i=0;i<diagonals.size();i++){
        for(int j=0;j<diagonals[i].size();j++){
            cout<<diagonals[i][j]<<" ";
        }
        cout<<endl;
    }
}