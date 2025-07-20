#include <iostream>
using namespace std;


/*
====================================================================================
🧠 Topic: Morris Traversal for Inorder, Preorder, and Postorder (No Stack, No Recursion)

📌 Problem Links:
- Inorder Traversal: https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1/
- Preorder Traversal: https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1/
- Postorder Traversal: https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1/

====================================================================================
🎯 Problem Statement:
Perform **Inorder**, **Preorder**, and **Postorder** traversals on a binary tree 
without using recursion or an explicit stack. The key idea is to traverse the tree 
in O(n) time using **O(1) space** using a technique called **Morris Traversal**.

====================================================================================
⏱ Time and Space Complexity:

For All Traversals:
- Time Complexity: **O(n)** (each edge is visited at most twice)
- Space Complexity: **O(1)** (no recursion, no stack — only threaded links)

====================================================================================
🧠 What is Morris Traversal?

Morris Traversal is a technique to traverse a binary tree without using 
recursion or an explicit stack. It modifies the tree structure temporarily by 
creating "threads" (i.e., pointers) from predecessor nodes back to current nodes 
to simulate the call stack.

====================================================================================
🪜 Step-by-Step Approach

🔸 Inorder Traversal (Left → Node → Right):

1. Start at the root.
2. If the current node has no left child:
   - Visit the node (store its value).
   - Move to its right child.
3. If it has a left child:
   - Find the **rightmost node** in its left subtree (predecessor).
   - If predecessor’s right is NULL:
     - Thread it to the current node.
     - Move to the left child.
   - Else:
     - Remove the thread.
     - Visit the current node.
     - Move to the right child.

📈 Diagram:
             1
           /   \
          2     3
         /
        4

➡ Traversal: 4 → 2 → 1 → 3

👀 Threads Formed Temporarily:
- 4.right → 2
- 2.right → 1

---

🔸 Preorder Traversal (Node → Left → Right):

1. Start at root.
2. If no left child:
   - Visit the node.
   - Move to right.
3. If left child exists:
   - Find predecessor.
   - If predecessor’s right is NULL:
     - Visit the node.
     - Thread predecessor to node.
     - Move left.
   - Else:
     - Remove thread and move right.

📈 Diagram:
             1
           /   \
          2     3
         /
        4

➡ Traversal: 1 → 2 → 4 → 3

👀 Threads Formed Temporarily:
- 4.right → 2
- 2.right → 1

---

🔸 Postorder Traversal (Left → Right → Node):

1. Traverse tree **in reverse preorder**: Node → Right → Left
2. Use threaded links **from leftmost** back to current.
3. After collecting all nodes, **reverse the result** to get postorder.

📈 Diagram:
             1
           /   \
          2     3
         / \
        4   5

➡ Reverse Traversal (Node → Right → Left): 1 → 3 → 2 → 5 → 4  
➡ After reversing: 4 → 5 → 2 → 3 → 1 (postorder)

👀 Threads Formed Temporarily:
- 3.left → 1
- 5.left → 2
- 4.left → 5

📌 Why reverse?
In postorder, we want to visit root **after** both subtrees. But Morris-style logic 
is based on visiting root **before** or **between** subtrees. So we reverse the order.

====================================================================================
📚 Summary Table:

| Traversal Type | Visit Position | Threading Used      | Post-processing |
|----------------|----------------|----------------------|------------------|
| Inorder        | After left     | Rightmost of left    | None             |
| Preorder       | Before left    | Rightmost of left    | None             |
| Postorder      | After right    | Leftmost of right    | Reverse result   |

====================================================================================
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



// Inorder Travarsal
// Link: https://www.geeksforgeeks.org/problems/inorder-traversal-iterative/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// Left -> Node -> Right 

// Here we have to find the inorder of give tree, without using any extra space 
// so we can do this using morris travarsal 
// in this we always have to link the right most node of every level to its root node 
// so that we do not need to travarse again the previous node 
// so for first we start with the root node 
// first we check that if the left node is exist or not 
// if its not exist we just store the root node data and move to the right node 
// if its exist then we check that this part is already travarsed or not 
// how we check it we just go the rightest node from the current node 
// if the rightest leaf node is null then it means its not travarsed 
// so just attach this leaf node with the root node and move to the left node

// and if the rightest leaf node is not null and points to the root node then
// its clear that its already travarsed and store the current node data 
// and delete the link and move to the right node 
// follow this process till the node become null and return the ans

vector<int> inorder(Node *root){
    
    vector<int>ans;

    while(root){

        // if root does not have left child 
        // we store it and move to right 
        // this case stores the right child of node 
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }else{
            Node *current = root->left;

            while(current->right && current->right != root){
                current = current->right;
            }

            if(!current->right){
                current->right = root;
                root = root->left;
            }else{
                ans.push_back(root->data);
                current->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}



// Preorder Travarsal
// Link: https://www.geeksforgeeks.org/problems/preorder-traversal-iterative/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// Node -> Left -> Right 

vector<int> preorder(Node *root){
    
    vector<int>ans;

    while(root){

        // if root does not have left child 
        // we store it and move to right 
        // this case stores the right child of node 
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }else{
            Node *current = root->left;

            while(current->right && current->right != root){
                current = current->right;
            }

            // this shows that, this is the first time 
            // we are visiting this node 
            if(current->right == NULL){
                ans.push_back(root->data);
                current->right = root;
                root = root->left;
            }else{
                current->right = NULL;
                root = root->right;
            }
        }
    }
    return ans;
}



// Postorder Travarsal
// Link: https://www.geeksforgeeks.org/problems/postorder-traversal-iterative/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
// Left -> Right -> Node 

// we will use the same approach but with little twick 
// morris algorithm is mainly work in when the Node is in the starting or middle 
// means, Node -> Left -> Right or Left -> Node -> Right 
// but in postorder node is in last so we have to reverse it, Node -> Right -> Left
// now we follow this approach 
// so in regular morris alogrithm we mostly link the right leaf node with the root node 
// but here we link the left leaf node with the root 
// and after completing every node, we just reverse the ans;

vector<int>postorder(Node * root){
    vector<int>ans;

    while(root){
        if(!root->right){
            ans.push_back(root->data);
            root = root->left;
        }else{
            Node * current = root->right;

            while(current->left && current->left != root){
                current = current->left;
            }

            if(current->left == NULL){
                ans.push_back(root->data);
                current->left = root;
                root = root->right;
            }else{
                current->left = NULL;
                root = root->left;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main(){
    cout<<"Enter the root Node: ";
    Node *root = tree();

    vector<int>ans;

    // ans = inorder(root);
    // ans = preorder(root);
    ans = postorder(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}