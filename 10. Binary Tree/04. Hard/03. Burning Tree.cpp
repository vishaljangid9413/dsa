#include <iostream>
using namespace std;


/*
=====================================================================================
🔥 Problem Name: Burning Tree
🔗 Problem Link: https://www.geeksforgeeks.org/problems/burning-tree/1

📌 Problem Statement:
You're given a binary tree and a **target node** from which a fire starts. 
The fire spreads to adjacent nodes (i.e., parent and children) in **1 second**.
You must compute the **total time taken** to burn the entire tree.

🔥 Fire spreads to:
- Left child
- Right child
- Parent (this is the tricky part because we don't normally store parent pointers)

=====================================================================================
📊 Time and Space Complexity:

- 🕒 Time Complexity: **O(n)**  
  Every node is visited once either to check height or fire spread.

- 🧠 Space Complexity: **O(n)**  
  Due to recursive calls and height calculation, especially for skewed trees.

=====================================================================================
🪜 Step-by-Step Approach:

🔹 Step 1: Recursive Burning Simulation
- Traverse every node using recursion.
- If a subtree contains the **target node**, return a **negative value** to indicate how far the fire has traveled from that subtree.
- Otherwise, return the height of that subtree (a positive value).

🔹 Step 2: Differentiating Fire vs Height
- Burn Time: Represented by **negative integers**
- Tree Height: Represented by **positive integers**
- This way we can **distinguish between a node that is burning** and one that just contributes to height calculation.

🔹 Step 3: Calculating Time to Reach All Nodes
- When a burning node is found (i.e., return is negative), we calculate how far the fire must travel to reach nodes in the opposite subtree (left or right).
- We store the maximum of all such calculated times in the `timer`.

🔹 Step 4: Calculate Subtree Height from Target Node
- After the fire reaches the target node, the subtree **below** that node burns too.
- We find the height of the subtree rooted at the target and subtract 1 (as the target itself burns at time = 0).

🔹 Step 5: Final Result
- The result is the **maximum** of:
  - `timer`: Time to reach all nodes outside the target’s subtree (upward and sideways)
  - `height`: Time to burn all nodes in the target’s subtree (downward)

=====================================================================================
📊 Example Tree Diagram:

              1
            /   \
           2     3
         /  \     \
        4    5     6
                   /
                  7

Let target = 2

🔥 Fire spreads like this:

Time = 0: 2 (target node burns)  
Time = 1: 4, 5, 1  
Time = 2: 3  
Time = 3: 6  
Time = 4: 7

🕒 Total time = 4 seconds

=====================================================================================
📌 Diagram of Burning Flow:

                       1
                     /   \
                 🔥2       3
               /    \       \
            🔥4     🔥5     🔥6
                            /
                         🔥7

Time progresses as we move up, sideways, and downward from the target node.

=====================================================================================
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


int burnTime(Node * root, int &timer, int target){
    if(!root){
        return 0;
    }

    // because burning start from this node 
    // so it returns the burning time taken by this node in negative
    if (root->data == target){
        return -1;
    }

    int left = burnTime(root->left, timer, target);
    int right = burnTime(root->right, timer, target);

    // if left part is burning returns the burn time
    if(left < 0){
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    // if right part is burning
    if(right < 0){
        timer = max(timer, left + abs(right));
        return right - 1;
    }

    // else if any node is not burning returns the height of the tree
    return 1 + max(left, right);
}

void find(Node *root, int target, Node *& burnNode){
    if(!root){
        return;
    }

    if(root->data == target){
        burnNode = root;
        return;
    }

    find(root->left, target, burnNode);
    find(root->right, target, burnNode);
}

int findHeight(Node *root){
    if(!root){
        return 0;
    }

    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int main(){
    cout<<"Enter the root Node: ";
    Node *root = tree();
    int target = 2;

    int timer = 0;
    burnTime(root, timer, target);

    // now we have to find the height of target tree
    // to find the total time taken by complete tree to burn 

    // first find the target 
    Node *targetNode = NULL;
    find(root, target, targetNode);

    // find height and remove itself;
    int height = findHeight(targetNode) - 1;

    // if hieght is greater or total time is greater
    cout<< max(timer, height);
}