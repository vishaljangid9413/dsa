#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
🧩 Problem: Check if Two Nodes are Cousins in a Binary Tree
--------------------------------------------------------------------------------

📌 Problem Description:
Given a binary tree and two distinct nodes, determine whether they are *cousins*.
Two nodes are cousins if:
1. They are on the same level in the tree (same depth).
2. They have **different parents**.

🔗 Problem Source:
GeeksForGeeks – [Check if two nodes are cousins](https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1?page=2&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions)

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

- Time Complexity: **O(N)**  
  We traverse every node once using level-order traversal (BFS), where N = number of nodes.

- Space Complexity: **O(N)**  
  We use a queue to store nodes at each level during traversal.

--------------------------------------------------------------------------------
🪜 Step-by-Step Logic:

1. Input two node values: `x` and `y` (hardcoded here as `5` and `4`).
2. Edge Cases:
   - Return false if the root is NULL, or if `x` and `y` are the same, or if any of them is the root.
3. Use **level-order traversal** (BFS) with a queue:
   - At each level:
     - Check if `x` and `y` are found on this level.
     - Also, check if `x` and `y` are children of the same parent → If yes, **they are not cousins**.
     - If both are found on the same level and not siblings, return true.
4. If traversal ends without satisfying cousin conditions, return false.

--------------------------------------------------------------------------------
📊 Diagram Explanation:

Consider the tree input:

```

```
       1
     /   \
    2     3
   /     / \
  4     5   6
```

```

Here:
- Node 4 is at level 2, parent = 2
- Node 5 is at level 2, parent = 3

🧾 Are they cousins?
- Same level ✔️
- Different parents ✔️
✅ **Yes, they are cousins.**

Now consider:

```

```
       1
     /   \
    2     3
   / \     
  4   5    
```

```

Nodes 4 and 5:
- Same parent ❌ (both under node 2)
❌ Not cousins

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


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    int x = 5, y = 4;
    if (!root || x == y || root->data == x || root->data == y) return false;

    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        bool found_x = false, found_y = false;

        
        for(int i=0;i<n;i++){
            Node *current = q.front();
            q.pop();

            // find if both nodes have same parent
            if(current->left && current->right){
                int left_val = current->left->data;
                int right_val = current->right->data;

                if(
                    (left_val == x && right_val == y) ||
                    (left_val == y && right_val == x)
                ){
                    cout<<"Cousine: false";
                    return;
                }
            }

            if(current->left){
                if(current->left->data == x) found_x = true;
                if(current->left->data == y) found_y = true;
                q.push(current->left);
            }

            if(current->right){
                if(current->right->data == x) found_x = true;
                if(current->right->data == y) found_y = true;
                q.push(current->right);
            }
        }
        if(found_x && found_y){
            cout<<"Cousine: true";
            return;
        }
    }

}