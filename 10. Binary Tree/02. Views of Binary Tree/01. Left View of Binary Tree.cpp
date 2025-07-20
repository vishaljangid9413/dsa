#include <iostream>
using namespace std;


/*
--------------------------------------------------------------------------------
🟢 Problem: Left View of a Binary Tree
--------------------------------------------------------------------------------

📌 Problem Statement:
Given a binary tree, return the *left view* of it — the set of nodes visible when the tree is viewed from the left side.

In simple terms, the left view contains the first node of each level (starting from the root).

🔗 Problem Link:
GeeksforGeeks - Left View of Binary Tree:  
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

--------------------------------------------------------------------------------
🧠 Time and Space Complexity:

Method 1: `using_level_order` (Level Order Traversal - BFS)
- Time Complexity: **O(N)**, where N = number of nodes (each node is visited once)
- Space Complexity: **O(N)**, due to the queue used for BFS

Method 2: `using_recurrsion` (Pre-order Traversal - DFS)
- Time Complexity: **O(N)**, each node is visited once
- Space Complexity: **O(H)**, where H = height of the tree (recursive call stack)

--------------------------------------------------------------------------------
🪜 Step-by-Step Explanation:

📌 Tree Construction (`tree()` function)
- Recursively build the tree using pre-order input.
- Enter `-1` when a child node is NULL.
- For each node, prompt user for left and right child values.

🌿 Left View using Level Order (`using_level_order` function)
1. Start with a queue, enqueue the root node.
2. For each level:
   - Get the size of the queue (number of nodes at this level).
   - The **first node** in this level (i.e., `q.front()`) is part of the left view.
   - Push this node's value into the result array.
   - Enqueue all left and right children of nodes at this level.

🌿 Left View using Recursion (`using_recurrsion` function)
1. Traverse the tree using **pre-order traversal** (Node → Left → Right).
2. Keep track of the `level` you're visiting.
3. If this is the first node at this level (`level == ans.size()`), add it to the answer.
4. Recurse left first to ensure leftmost nodes are captured before right ones.

--------------------------------------------------------------------------------
📊 Tree Diagram:

Let’s say the user builds the following binary tree from input:

```

Sample Input (Pre-order for tree()):
10
/ &#x20;
5   20
/     &#x20;
3        25

Input via console:
10 → 5 → 3 → -1 → -1 → -1 → 20 → -1 → 25 → -1 → -1

```

🌳 Visual Representation:

            10
           /  \
         5     20
        /        \
      3           25

👁️ Left View Output:  
**10 5 3**

Explanation:  
- Level 0: 10 is visible  
- Level 1: 5 is the first node from the left  
- Level 2: 3 is the first node from the left

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


void using_level_order(Node *root, vector<int> &ans){
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        int q_size = q.size();
        ans.push_back(q.front()->data);
        
        while(q_size--){
            Node *temp = q.front();
            q.pop();

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// we only have to track only those nodes which are appears only first time
// and here we are using the pre-order travarsal,, Node -> Left -> Right
void using_recurrsion(Node *root, int level, vector<int> &ans){
    if(root == NULL){
        return;
    }
    
    // level shows that current node is part of which level
    // so if the node level and the size of ans nodes are equal 
    // then the current node appears first time 
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    using_recurrsion(root->left, level+1, ans);
    using_recurrsion(root->right, level+1, ans);
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();
    vector<int>ans;

    // using_level_order(root, ans);

    int level = 0;
    using_recurrsion(root, level, ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}   