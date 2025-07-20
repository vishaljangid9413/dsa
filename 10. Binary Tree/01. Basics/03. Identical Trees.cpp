#include <iostream>
using namespace std;



/*
--------------------------------------------------------------------------------
🧠 Problem Name: Determine if Two Binary Trees are Identical  
🔗 Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions  
--------------------------------------------------------------------------------

📌 Problem Statement:
You are given the root nodes of two binary trees. The task is to check if both trees are **identical**.  
Two binary trees are considered identical if:
- Both trees are structurally the same (same shape and arrangement)
- All corresponding nodes have the same value

This is a common interview problem used to test recursion, tree traversal, and base condition understanding.

--------------------------------------------------------------------------------
⏱️ Time and Space Complexity:

✅ Time Complexity: O(N)  
Where N is the total number of nodes in either of the trees.  
Each node is visited **once** for comparison.

✅ Space Complexity: O(H)  
Where H is the height of the tree.  
Due to recursion, the maximum space used will be the **call stack** in the worst case:
- Skewed tree (all nodes one-sided): O(N)
- Balanced tree: O(log N)

--------------------------------------------------------------------------------
🪜 Step-by-Step Logic of `identical(Node* r1, Node* r2)`:

1. **Base Case 1**:  
   If both nodes are `NULL`, return `true`.  
   ➤ This means both trees end at the same structure.

2. **Base Case 2**:  
   If one is `NULL` and the other is not, return `false`.  
   ➤ Structure mismatch.

3. **Compare Node Values**:  
   If both nodes are not `NULL`, check if their `data` values are equal.  
   ➤ If not, return `false`.

4. **Recursive Comparison**:  
   - Check if left children of both trees are identical.
   - Then check if right children are identical.
   - Return true only if both left and right subtrees are identical.

--------------------------------------------------------------------------------
🖼️ Example and Diagram:

Let’s say Tree 1 and Tree 2 are:

                Tree 1                          Tree 2
                 1                                1
               /   \                            /   \
              2     3                          2     3
             /                              /
            4                              4

Pre-order input for both trees (using -1 for NULL):
```

Input for Tree 1:
1
2
4
-1 -1
-1
3
-1 -1

Input for Tree 2:
1
2
4
-1 -1
-1
3
-1 -1

```

🧪 Both trees:
- Have same structure ✔️
- Have same values in all nodes ✔️
✅ Output: Trees are **Identical**

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


bool identical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return 1;
    }

    if((!r1 && r2) || (r1 && !r2)){
        return 0;
    }

    if(r1->data != r2->data){
        return 0;
    }

    return identical(r1->left, r2->left) && identical(r1->right, r2->right);
}


int main(){
    // create a tree first
    cout<<"Create First Tree"<<endl;
    cout<<"Enter the root Node: ";
    Node *root1; 
    root1 = tree();
    
    cout<<endl;
    
    cout<<"Create Second Tree"<<endl;
    cout<<"Enter the root Node: ";
    Node *root2; 
    root2 = tree();
    
    cout<<endl;
    cout<<"Is identical: "<<identical(root1, root2);
    
}