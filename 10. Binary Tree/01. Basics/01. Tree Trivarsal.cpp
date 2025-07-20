#include <iostream>
using namespace std;


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


// Tree trivarsal:
// 1. Pre-order: RootNode Left Right 
// 2. In-Order: Left RootNode Right 
// 3. Post-Order: Left Right RootNode 

// as you can see in every method left and right nodes remain same 
// only Root Node will move

// *Important Tip: 🔹 Traversal Shortcut Tips (Pre-order, In-order, Post-order)
// Use these intuitive rules to identify tree traversal order just by visualizing the structure.

// 1. Pre-order: Just start from root node and move forward to left then right 
// without skipping any node just g o node by node, and whichever node you encounter 
// first time just print it 
// 2. In-order: do the same thing like pre-order but this time whichever node you encounter 
// second time just print it, and also if any node do not have left child or only have right child
// or do not have any child, also consider that node encounter as second encounter 
// 3. Post-order: do the same thing like pre-order but this time whichever node you think that this node 
// will only encounter last time, means you don't encounter this node again while travarsal, just print that node 
// and whichever node encounter first time or second time or whatever time you have to skip 
// you have to check that with the current node this is my last encounter or not



// Link: https://www.geeksforgeeks.org/problems/preorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void pre_order(Node *root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

// Link: https://www.geeksforgeeks.org/problems/inorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void in_order(Node *root){
    if(root == NULL){
        return;
    }

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

// Link: https://www.geeksforgeeks.org/problems/postorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions
void post_order(Node *root){
    if(root == NULL){
        return;
    }

    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

// Level Order Tree traversal
void level_order(Node *root){
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();

        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}


// Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions
// Each level elements contains in a single vector and stores all vectors in a single vector
vector<vector<int>> level_order_vector_return(Node *root){
    vector<vector<int>> ans;
    queue<Node *>q;
    q.push(root);

    while(!q.empty()){
        int q_size = q.size();
        vector<int> curr_vector;

        for(int i=0;i<q_size;i++){
            Node *curr_node = q.front();
            q.pop();

            curr_vector.push_back(curr_node->data);

            if(curr_node->left != NULL){
                q.push(curr_node->left);
            }
            if(curr_node->right != NULL){
                q.push(curr_node->right);
            }
        }
        ans.push_back(curr_vector);
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    // create a tree first
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    cout<<"Pre Order: ";
    pre_order(root);
    
    cout<<endl<<"In Order: ";
    in_order(root);

    cout<<endl<<"Post Order: ";
    post_order(root);

    cout<<endl<<"Level Order: ";
    level_order(root);

    cout<<endl<<"Level Order vector return: ";
    level_order_vector_return(root);
}

