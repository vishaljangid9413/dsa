#include <iostream>
using namespace std;


/*
-----------------------------------------------------------------------------------------
🟩 Problem: Print BST Elements in Given Range  
🔗 Source: https://www.geeksforgeeks.org/problems/print-bst-elements-in-given-range/1?page=1&difficulty%5B%5D=0&category%5B%5D=Binary%2520Search%2520Tree&sortBy=submissions

📌 Problem Statement:
You're given a **Binary Search Tree (BST)** and two integer values `low` and `high`.  
Your task is to **print all the node values that lie within the given range** `[low, high]` in **sorted (ascending) order**.

✔️ Note: The BST property is important here:
- Left child < Parent < Right child

-----------------------------------------------------------------------------------------

⏱️ Time Complexity:
- Best Case (Balanced Tree): **O(log N)** for traversing nodes outside the range + **O(K)** for the K nodes in range  
- Worst Case (Skewed Tree): **O(N)**

💾 Space Complexity:
- **O(K)** for the result vector + **O(H)** for recursion stack (where H is tree height)

-----------------------------------------------------------------------------------------

🔍 Step-by-Step Approach:

1. **Tree Input Construction**:
   The `tree()` function uses recursion to build a binary tree from user input.  
   - `-1` denotes a NULL (no child).
   - The function prompts the user to enter values for left and right child nodes.

2. **Finding Nodes in Range**:
   The function `find()` recursively searches the BST:
   
   ➤ If current node’s value is **less than both `low` and `high`**, search in the **right subtree**  
   ➤ If it's **greater than both**, search in the **left subtree**  
   ➤ If the value lies **within the range**, apply **in-order traversal**:
      - Traverse left subtree  
      - Visit (store) the current node  
      - Traverse right subtree  
   This ensures the result is **sorted** because in-order traversal of BST gives sorted order.

-----------------------------------------------------------------------------------------

📊 Visualization Example:

Let’s say the tree is:

```

```
           15
         /    \
       10      20
      /  \    /  \
     5   12  18  25
```

```

Range: `low = 10`, `high = 20`  
Expected Output (in sorted order): `10 12 15 18 20`

✅ In-order traversal will naturally visit:
→ [5] [10] [12] [15] [18] [20] [25]  
From which only values between 10 and 20 are picked.

-----------------------------------------------------------------------------------------

🎯 Best Practices Followed:
- In-order traversal used for sorted output
- Efficient range checks to skip unnecessary subtrees
- Avoids unnecessary recursive calls (prunes tree)

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


void find(Node *root, vector<int> &ans, int low, int high){
    if(!root){
        return;
    }

    // go for left part
    if(root->data > low && root->data > high){
        find(root->left, ans, low, high);
    }
    // go for right part
    else if(root->data < low && root->data < high){
        find(root->right, ans, low, high);
    }
    // node find in range
    else{
        // to find values in sorted order use inorder travarsal 

        // first left part
        find(root->left, ans, low, high);
        // store value
        ans.push_back(root->data);
        //right part 
        find(root->right, ans, low, high);
    }
}

int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    int low = 4;
    int high = 24;
    vector<int> ans;
    find(root, ans, low, high);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
