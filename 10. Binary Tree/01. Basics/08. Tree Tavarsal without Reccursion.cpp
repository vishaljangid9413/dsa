#include <iostream>
using namespace std;


/*
===========================================================================================================================
🔹 Problem Title: Tree Traversal using Stack (Iterative Preorder, Inorder, Postorder Traversals)
🔹 Source/Reference: Based on common binary tree traversal problems asked in interviews (e.g., LeetCode, GeeksForGeeks)
🔹 Problem Statement:
    Implement iterative (non-recursive) versions of Preorder, Inorder, and Postorder traversal of a binary tree 
    using a stack instead of recursion.

===========================================================================================================================
🔸 Time and Space Complexity:

1. Preorder Traversal:
   - Time Complexity: O(n)
   - Space Complexity: O(n) [due to the use of a stack]

2. Postorder Traversal:
   - Time Complexity: O(n)
   - Space Complexity: O(n)

3. Inorder Traversal:
   - Time Complexity: O(n)
   - Space Complexity: O(n)

Here, *n* is the number of nodes in the binary tree.

===========================================================================================================================
🔸 Step-by-Step Explanation:

First, the user constructs a binary tree interactively:
- A node is created for each value entered.
- If the input is -1, it means the node is `NULL`.

Then, three traversal functions are defined:
1. **Preorder Traversal (Node → Left → Right):**
   - Start by pushing the root to the stack.
   - While the stack is not empty:
     - Pop the top node and add its data to the result.
     - Push its right child (if any), then left child (if any).
   - This ensures that the left child is processed before the right one.

2. **Postorder Traversal (Left → Right → Node):**
   - Similar to preorder but push left before right and reverse the result at the end.

3. **Inorder Traversal (Left → Node → Right):**
   - A bit tricky using one stack. Here, two stacks are used:
     - One for nodes.
     - One to track visit counts.
   - If a node is visited once, it's processed (data added to result).
   - Otherwise:
     - Push its right child, the current node again (with visit count updated), and then its left child.
   - This helps simulate the recursive call stack.

===========================================================================================================================
🔸 Diagram (Tree Structure + Traversal Flow Example):

Example Input:
Enter the root Node: 1  
Enter the left child of 1: 2  
Enter the left child of 2: -1  
Enter the right child of 2: -1  
Enter the right child of 1: 3  
Enter the left child of 3: -1  
Enter the right child of 3: -1

🧠 Tree Constructed:
        1
       / \
      2   3

🧭 Traversals:

1. Preorder:     1 2 3  
2. Inorder:      2 1 3  
3. Postorder:    2 3 1  

📌 Stack Simulation for Inorder (Left → Node → Right):

    ┌─────┐      ┌─────┐      ┌─────┐      ┌─────┐
    │  1  │◄─────│  2  │◄─────│null │◄─────│Backtrack
    └─────┘      └─────┘      └─────┘      └─────┘
     Stack→      Visit Left     Visit        Push node into result after left


===========================================================================================================================
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


void pre_order(Node *root){
    vector<int>ans;
    stack<Node *>st;
    st.push(root);

    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if(temp->right){
            st.push(temp->right);
        }

        if(temp->left){
            st.push(temp->left);
        }
    }

    cout<<"Pre Order: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}


void post_order(Node *root){
    vector<int> ans;
    stack<Node *>st;
    st.push(root);

    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if(temp->left){
            st.push(temp->left);
        }

        if(temp->right){
            st.push(temp->right);
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<"Post Order: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}


void in_order(Node *root){
    vector<int>ans;
    stack<Node *>st;
    stack<int> visit;

    st.push(root);
    visit.push(0);

    while(!st.empty()){
        Node *temp = st.top();
        st.pop();

        int node_visit = visit.top();
        visit.pop();

        // if node_visit has value 1 means 
        // so it means its already pushed in stack 2 times and 
        // now we popped out this node and add in ans vector 
        if(node_visit == 1){
            ans.push_back(temp->data);
        }else{
            if(temp->right){
                st.push(temp->right);
                visit.push(0);
            }

            st.push(temp);
            visit.push(1);

            if(temp->left){
                st.push(temp->left);
                visit.push(0);
            }
        }
    }

    cout<<"In Order: ";
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    // pre_order(root);
    // post_order(root);
    in_order(root);
}