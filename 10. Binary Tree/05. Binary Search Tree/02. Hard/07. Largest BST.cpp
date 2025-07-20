#include <iostream>
using namespace std;

/*
======================================================================================================================
🧠 Problem: **Largest BST in a Binary Tree**  
🔗 Link: https://www.geeksforgeeks.org/problems/largest-bst/1  
👨‍💻 Difficulty: Medium  
🎯 Goal: Given a binary tree (not necessarily a BST), find the size of the **largest subtree** that is also a BST.

----------------------------------------------------------------------------------------------------------------------
🕰️ Time Complexity: O(N)  
📦 Space Complexity: O(N)  
Where N is the number of nodes in the binary tree.  
- Each node is visited once, and recursive calls are made for left and right subtrees.

----------------------------------------------------------------------------------------------------------------------
✅ Step-by-Step Approach (with Explanation):

1. **Understand the Goal**:  
   We are given a Binary Tree, and we need to identify the largest subtree that satisfies BST properties:
   - Left subtree nodes must be **less than** the current node's value.
   - Right subtree nodes must be **greater than** the current node's value.
   - Both left and right subtrees must also be BSTs.

2. **What we need to return at each node**:  
   For each subtree (rooted at any node), we must determine:
   - Whether it's a valid BST.
   - Its size (number of nodes).
   - Its minimum and maximum values (for BST validity check).

3. **Use a helper class (`Box`)** to return multiple values from recursive calls:
   - `bst`: whether the subtree is a BST.
   - `size`: size of the current subtree.
   - `min` and `max`: help validate BST property with parent.

4. **Recursive Strategy**:
   - If it's a leaf node, it's a BST of size 1.
   - If it has one child (left or right), verify BST conditions and return updated Box.
   - If it has both children:
     - Check if left subtree is BST and `left.max < root.data`.
     - Check if right subtree is BST and `right.min > root.data`.
     - If both are valid → current subtree is also BST.
     - Else → return a Box with `bst = false`.

5. **Update the global maximum (`total_size`)** whenever a valid larger BST is found.

----------------------------------------------------------------------------------------------------------------------
📊 Visual Example and Diagram:

Consider the following binary tree:

```

```
       50
      /  \
    30    60
   / \    / \
 5   20  45  70
              / \
            65  80
```

```

Here:
- Subtree rooted at node `60` is a **valid BST** of size 5: [60, 45, 70, 65, 80]
- So the largest BST subtree has size = 5

The recursive calls go like this:
- Start from leaves: 5, 20, 45, 65, 80 — each is BST of size 1.
- Combine left and right at 70: valid BST of size 3.
- Combine 45 and 70 at 60: valid BST of size 5.
- But at root 50: left child 30 is invalid (30 has 20 > 30), so 50 is NOT BST.
→ Return max BST size found so far → **5**

----------------------------------------------------------------------------------------------------------------------
✅ Best Practices and Industry Standards:
- Bundle multiple return values in a class/struct (`Box`) for clean recursion.
- Always handle leaf/base cases first.
- Use global variables (`total_size`) for tracking optimal results efficiently.
- Ensure left-right bounds (`min`, `max`) are passed and updated accurately.

======================================================================================================================
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

// class to bundle the return values
class Box{
    public:
    bool bst;
    int size;
    int min, max;

    Box(int data){
        bst = 1;
        size = 1;
        min = data;
        max = data;
    }
};


Box *find(Node *root, int &total_size){

    // handle leaf node
    if(!root->left && !root->right){
        return new Box(root->data);
    }

    // handle if only left part is available
    else if(root->left && !root->right){
        Box *head = find(root->left, total_size);
        
        // if left part is bst
        if(head->bst && head->max < root->data){
            head->size++;
            // data is returning from left side 
            // that's why the maximum node for current part is root->data
            head->max = root->data;
            total_size = max(head->size, total_size);
            return head;
        }
        // if its not an bst just make it false and return
        else{
            head->bst = 0;
            return head;
        }
    }

    // handle if only right part is available
    else if(!root->left && root->right){
        Box *head = find(root->right, total_size);

        // if right part is bst
        if(head->bst && head->min > root->data){
            head->size++;
            // data is returning from right side
            // that's why the minimum node for current part is root->data
            head->min = root->data;
            total_size = max(head->size, total_size);
            return head;
        }
        // if not bst
        else{
            head->bst = 0;
            return head;
        }
    }

    // handle if both part is available
    else{
        Box *leftHead = find(root->left, total_size);
        Box *rightHead = find(root->right, total_size);

        // check if both part creates a valid bst
        if(
            (leftHead->bst && leftHead->max < root->data) &&
            (rightHead->bst && rightHead->min > root->data)
        ){
            // create new data to return 
            Box *head = new Box(root->data);
            head->size += leftHead->size + rightHead->size;
            
            // set the min from minimum element of left
            head->min = leftHead->min;
            // set the max from maxmimum element of right
            head->max = rightHead->max;

            total_size = max(head->size, total_size);
            return head;
        }
        // if not bst just return the head of any part
        // we are returning left part 
        else{
            leftHead->bst = 0;
            return leftHead;
        }
    }
}


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    // minimum size of a tree is at least 1
    int total_size = 1;
    find(root, total_size);
    
    cout<<total_size;
}
