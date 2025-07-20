#include <iostream>
using namespace std;


/*
-----------------------------------------------------------------------------------------
🟩 Problem Title: Merge Two BSTs  
📝 Problem Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1  
💡 Problem Statement:
Given two Binary Search Trees (BSTs), merge them into a sorted list of all the elements 
from both trees.

-----------------------------------------------------------------------------------------
⏱️ Time Complexity:
- Inorder traversal of both trees: O(N + M), where N and M are the number of nodes in each tree.
- Merging two sorted arrays: O(N + M)
- Total: O(N + M)

📦 Space Complexity:
- Storing inorder of both trees: O(N + M)
- Output array: O(N + M)
- Recursive call stack: O(H1 + H2), where H1 and H2 are the heights of the two trees (in worst case, O(N + M))

-----------------------------------------------------------------------------------------
🧠 Step-by-Step Explanation:

1. **Input the Trees**:
   The user builds two BSTs using recursive input. `-1` indicates a NULL child.

2. **Inorder Traversal**:
   - We perform an inorder traversal on both BSTs.  
   - Since BSTs give sorted values in inorder, we get two sorted arrays.

3. **Merge Two Sorted Arrays**:
   - We use the **two-pointer technique** to merge both sorted arrays into a single sorted list.

4. **Output**:
   - Print the final merged sorted list.

-----------------------------------------------------------------------------------------
📊 Visual Diagram (ASCII Art):

           Tree 1                   Tree 2
             3                        4
            / \                      / \
           1   5                    2   6

🔁 Inorder Traversal:
   Tree 1 → [1, 3, 5]
   Tree 2 → [2, 4, 6]

🔗 Merge Step:
   [1, 3, 5]
 + [2, 4, 6]
 = [1, 2, 3, 4, 5, 6]

📌 Final Output:
   Sorted merged list of both BSTs.

-----------------------------------------------------------------------------------------
✅ Best Practices and Industry Standards:
- Always prefer **inorder traversal** for BSTs when sorted data is needed.
- Use **two-pointer merging** instead of combining and sorting later (better performance).
- Avoid modifying the original tree structures unless necessary.
- Handle NULL/empty input trees gracefully in production-level code.

-----------------------------------------------------------------------------------------
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

void findInorder(Node *root, vector<int>&inorder){
    if(!root){
        return;
    }

    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}

int main(){
    cout<<"Enter the root Node: ";
    Node * root1 = tree();

    cout<<"Enter the root Node: ";
    Node * root2 = tree();

    // find inorder for both trees
    vector<int>inorder1;
    vector<int>inorder2;

    findInorder(root1, inorder1);
    findInorder(root2, inorder2);


    // merge inorders in sorted form 
    vector<int>ans;
    int i = 0, j = 0;
    while(i < inorder1.size() && j < inorder2.size()){
        if(inorder1[i] < inorder2[j]){
            ans.push_back(inorder1[i++]);
        }else{
            ans.push_back(inorder2[j++]);
        }
    }

    // add remaining elements
    while(i < inorder1.size()){
        ans.push_back(inorder1[i++]);
    }
    
    while(j < inorder2.size()){
        ans.push_back(inorder2[j++]);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
