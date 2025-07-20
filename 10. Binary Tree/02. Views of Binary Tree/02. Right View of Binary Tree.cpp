#include <iostream>
using namespace std;


/*
============================================
🧠 PROBLEM: Right View of Binary Tree
--------------------------------------------
Given a binary tree, return the nodes that are visible when the tree is viewed from the right side. 
For each level (depth) of the tree, you should return the rightmost node.

📍Link: 
https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

============================================
⏱ TIME AND SPACE COMPLEXITY
--------------------------------------------
1. Level Order Approach (using a queue):
   - Time Complexity: O(n), where n = number of nodes
   - Space Complexity: O(n), for the queue used in level order traversal

2. Recursion Approach (Right-First DFS):
   - Time Complexity: O(n)
   - Space Complexity: O(h), where h = height of the tree (recursive call stack)

============================================
🪜 STEP-BY-STEP EXPLANATION
--------------------------------------------

👨‍🏫 GOAL:
From each level of the binary tree, we want to **capture the node that is furthest to the right**.

------------------------------------------------------------
🔧 Method 1: Level Order Traversal (BFS using Queue)
------------------------------------------------------------
1. Traverse the tree level by level using a queue (BFS).
2. At each level, capture the **last node** before moving to the next level.
3. This last node is the rightmost node visible from the right side.

🧠 Example:
        1
       / \
      2   3
     /     \
    4       5

👉 Level-wise traversal:  
Level 0: 1 → Rightmost = 1  
Level 1: 2, 3 → Rightmost = 3  
Level 2: 4, 5 → Rightmost = 5  
✅ Output: [1, 3, 5]

------------------------------------------------------------
🔧 Method 2: Recursion (Right → Left DFS)
------------------------------------------------------------
1. Start from the root, and use **Right → Left** recursive traversal.
2. Use a vector to store the first node encountered at each level.
3. If the current level equals the size of the result vector, it means the current node is the first one seen at this level, hence it's the rightmost.

🧠 Why Right to Left?
Because we want the rightmost node at each level. If we go Left → Right, we’d get the left view.

============================================
📊 ASCII TREE DIAGRAM (for visual learners)
--------------------------------------------

Sample Tree:
             10
           /    \
         20      30
        /  \       \
      40   50      60
                      \
                      70

🔍 Level Order Right View:
Level 0 → 10  
Level 1 → 30  
Level 2 → 60  
Level 3 → 70  
✅ Output: [10, 30, 60, 70]

🔍 Recursive Right View (Right → Left DFS):
- Visit 10 (level 0, ans = [10])
- Go Right → 30 (level 1, ans = [10, 30])
- Go Right → 60 (level 2, ans = [10, 30, 60])
- Go Right → 70 (level 3, ans = [10, 30, 60, 70])
- Remaining left nodes are skipped because level already visited

============================================
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
        ans.push_back(q.back()->data);
        
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
// and here we are using different travarsal,, Node -> Right -> Left
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

    using_recurrsion(root->right, level+1, ans);
    using_recurrsion(root->left, level+1, ans);
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