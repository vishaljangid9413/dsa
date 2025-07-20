
#include <iostream>
using namespace std;



/*
--------------------------------------------------------------------------------
📌 Problem: Print Binary Tree in Vertical Order
--------------------------------------------------------------------------------

🔗 Problem Link:  
GeeksforGeeks – https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

🎯 Objective:
Given a binary tree, print it in vertical order. Vertical order of a binary tree means printing nodes that lie in the same vertical line together, from top to bottom and from leftmost vertical to rightmost vertical.

For example:

If input tree is:
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
                \  
                 8

Then vertical order traversal would be:
→ Vertical -2: [4]  
→ Vertical -1: [2]  
→ Vertical  0: [1, 5, 6]  
→ Vertical +1: [3]  
→ Vertical +2: [7]  
→ Vertical +3: [8]  

So the final output:  
**4 2 1 5 6 3 7 8**

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Time Complexity: **O(N)**  
- Each node is visited once during range finding and once during level order traversal.

✅ Space Complexity: **O(N)**  
- Space used by the queue for BFS traversal and the output storage vector.

--------------------------------------------------------------------------------
🪜 Step-by-Step Approach:

🔹 Step 1: Construct Binary Tree from user input using a recursive method.  
  - -1 denotes a `NULL` node.
  - Pre-order traversal is used (root → left → right).

🔹 Step 2: Compute the leftmost and rightmost horizontal indexes using recursion (`findRange()`):
  - Treat the root node as index 0.
  - Going left decreases index by 1; going right increases it by 1.
  - This helps us allocate just enough space to hold all vertical lines in an array.

🔹 Step 3: Perform BFS (level-order traversal) with an index-tracking queue:
  - Each node is pushed into the `queue<Node*>` with its corresponding vertical index.
  - An index array is also maintained (`queue<int> index`) that represents the horizontal index for each node.
  - When we dequeue a node, we insert it in the result vector at the corresponding index (offset by -left to make indices non-negative).

🔹 Step 4: Return and print the resulting 2D vector which contains nodes grouped by their vertical positions.

--------------------------------------------------------------------------------
🧠 Data Structure Diagram:

Let’s say we input the following tree:

Input (pre-order with -1 as NULL):  
`1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 8 -1 -1`

Constructed Tree:
```

```
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
                \
                 8
```

```

Horizontal Index Mapping:
```

Index -2:       4
Index -1:     2
Index  0:   1, 5, 6
Index +1:     3
Index +2:       7
Index +3:         8

```

So the final 2D output will be:
```

\[
\[4],
\[2],
\[1, 5, 6],
\[3],
\[7],
\[8]
]

```
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


void findRange(Node *root, int position, int &left, int &right){
    if(root == NULL){
        return;
    }

    left = min(position, left);
    right = max(position, right);

    findRange(root->left, position - 1, left, right);
    findRange(root->right, position + 1, left, right);
}

vector<vector<int>> verticalOrder(Node * root){
    int left = 0, right = 0;
    findRange(root, 0, left, right);

    vector<vector<int>>ans;
    queue<Node *>q;
    queue<int>index;

    q.push(root);
    index.push(left * -1);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        int curr_index = index.front();
        index.pop();

        ans[curr_index].push_back(temp->data);

        if(temp->left){
            q.push(temp->left);
            index.push(curr_index-1);
        }

        if(temp->right){
            q.push(temp->right);
            index.push(curr_index + 1);
        }
    }
    return ans;
}


int main(){
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    vector<vector<int>>ans = verticalOrder(root);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}