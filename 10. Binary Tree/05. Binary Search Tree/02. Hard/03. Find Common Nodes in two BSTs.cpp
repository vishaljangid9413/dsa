#include <iostream>
using namespace std;


/*
================================================================================
🔍 Problem: Print Common Nodes in BST
--------------------------------------------------------------------------------
📝 Description:
Given the root nodes of two Binary Search Trees (BSTs), the task is to print all 
the nodes that are common to both BSTs in sorted (in-order) order.

📎 Source:
GeeksForGeeks - https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1?page=1&difficulty%5B%5D=0&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

================================================================================
⏱️ Time and Space Complexity:
--------------------------------------------------------------------------------
- Time Complexity: O(m + n)
  where m and n are the number of nodes in the two BSTs. Each node is visited once.
- Space Complexity: O(h1 + h2)
  where h1 and h2 are the heights of the two BSTs due to the space used by the two stacks.

================================================================================
🧠 Step-by-Step Approach:
--------------------------------------------------------------------------------
1. Perform **simultaneous in-order traversals** of both BSTs using **two stacks**.
2. In-order traversal guarantees that we process elements in **sorted order**.
3. Push all the leftmost nodes of each BST into their respective stacks (`s1` and `s2`).
4. Compare the top elements of both stacks:
   - If equal, it is a common node → add to the result and move both pointers to the right subtree.
   - If one is smaller, move only that pointer (the smaller one) to its right subtree.
5. Repeat this process until one of the stacks becomes empty.
6. This method avoids storing full traversals, keeping the space usage optimal.

================================================================================
📊 Tree Traversal Visualization:
--------------------------------------------------------------------------------
Suppose we have:

        BST1                    BST2
          5                       10
         / \                     /  \
        1   10                 5    15
             \                     /
             15                  10

In-order Traversals:
BST1: [1, 5, 10, 15]
BST2: [5, 10, 15]

🎯 Common Nodes = Intersection = [5, 10, 15]

================================================================================
📌 Stack-based Traversal Visualization:
--------------------------------------------------------------------------------
At any moment, we are doing this:

BST1 Stack (s1): Top = Current Node in BST1
BST2 Stack (s2): Top = Current Node in BST2

Compare:
    s1.top()->data vs s2.top()->data

    - If equal → Save & move both to right subtree
    - If s1 > s2 → Move s2 to its right subtree
    - If s1 < s2 → Move s1 to its right subtree

Repeat until any stack is empty.

================================================================================
📚 Best Practices & Industry Standards:
--------------------------------------------------------------------------------
✅ Always use in-order traversal for sorted data in BSTs.
✅ Using iterative stack-based traversal avoids recursion stack overflow.
✅ Space-efficient design: only necessary nodes are stored in the stack.
✅ Avoid full in-order arrays (e.g., don’t use vectors for full traversal unless needed).

================================================================================
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

    Node *root = new Node(x);
    cout<<"Enter left child of "<<root->data<<": ";
    root->left = tree();
    cout<<"Enter right child of "<<root->data<<": ";
    root->right = tree();
    return root;
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root1 = tree();

    cout<<"Enter the root Node: ";
    Node * root2 = tree();

    vector<int>ans;
    stack<Node*>s1, s2;

    // first iterate through all left elements of root
    while(root1){
        s1.push(root1);
        root1 = root1->left;
    }

    while (root2){
        s2.push(root2);
        root2 = root2->left;
    }

    // now iterate through the stack elements
    while(!s1.empty() && !s2.empty()){

        // check if elements is equal or not
        if(s1.top()->data == s2.top()->data){
            ans.push_back(s1.top()->data);

            // go to right elements
            root1 = s1.top()->right; s1.pop();
            root2 = s2.top()->right; s2.pop();
        }
        // if s1 element is bigger
        else if(s1.top()->data > s2.top()->data){
            root2 = s2.top()->right; s2.pop();
        }
        // if s2 element is bigger
        else if(s1.top()->data < s2.top()->data){
            root1 = s1.top()->right; s1.pop();
        }

        // execute same process
        // iterate through all left elements and insert into stacks
        while(root1){
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2){
            s2.push(root2);
            root2 = root2->left;
        }
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
