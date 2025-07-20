#include <iostream>
using namespace std;


// Top View of Binary Tree
// Here we have to find all the elements that can be visible from the top of tree 
// Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

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



// To find the **top view** of a binary tree, 
// we need to identify all the nodes that are **visible when the tree is viewed from above**. 
// In simpler terms, for each horizontal distance (also called a "column") from the root, 
// we should only include the **first node encountered** when doing a level order traversal.
// To achieve this, we follow a structured approach that involves assigning a horizontal distance or "number" to each node, starting from the root:

// 1. **Numbering Nodes (Horizontal Distance):**

//    * Start from the root node and assign it a horizontal distance (HD) of `0`.
//    * For the **left child**, the HD becomes `current - 1`.
//    * For the **right child**, the HD becomes `current + 1`.
//    * Continue this process for every node using **level order traversal** (BFS).

// 2. **Tracking Range of HDs:**

//    * During traversal, keep track of the **minimum** and **maximum** HDs. These represent the leftmost and rightmost columns visible in the top view.
//    * These values help us determine the final size of our answer vector.

// 3. **Adjusting HDs for Array Indexing:**

//    * Since HDs can be negative, we shift all HDs by `-1 * (min HD)` so that the root (original HD = 0) maps to a valid array index.
//    * For example, if the minimum HD is `-4`, we shift everything by `+4`. Now, HD `-4` becomes index `0`, and HD `0` becomes index `4`.

// 4. **Handling Duplicates (Same HD):**

//    * Multiple nodes can have the same HD, but for the **top view**, 
//     we only care about the **first node** encountered at each HD during level order traversal (i.e., the one at the **highest level**).
//    * To track this, we use a helper vector or map to record whether an HD has already been filled.

// 5. **Using Queues for BFS:**

//    * Use two queues:

//      * One for holding the actual node pointers.
//      * Another for holding the HDs of each node.
//    * Traverse the tree level by level, and for each node, 
//     check if its HD is already filled in the answer vector. If not, insert its value.

// 6. **Final Answer:**

//    * After BFS completes, the answer vector will contain the top-view nodes in the correct left-to-right order.

// ---

// ### 💡 Example Summary:

// For this tree:

// ```
//        1
//      /   \
//     2     3
//      \   / \
//       4 5   6
// ```

// * HD values:

//   * Node 1 → 0
//   * Node 2 → -1
//   * Node 3 → +1
//   * Node 4 → 0 (conflict with 1, but we already took 1 as it's higher level)
//   * Node 5 → 0 (ignored)
//   * Node 6 → +2

// * Top view: `2, 1, 3, 6`



// this gives the left and right side of our range
void findRange(Node *root, int position, int &left, int &right){
    if (root == NULL){
        return;
    }

    left = min(left, position);
    right = max(right, position);

    findRange(root->left, position - 1, left, right);
    findRange(root->right, position + 1, left, right);
}

int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    int left = 0, right = 0;
    int started_position = 0;
    findRange(root, started_position, left, right);

    //holds the answer
    vector<int>ans(right - left + 1);
    // represent that the index is already occupied
    vector<bool>filled(right - left + 1, 0);
    // holds node on every level
    queue<Node *>q;
    // holds correct index of every node
    queue<int> index;

    q.push(root);
    index.push(-1 * left);
    
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        int position = index.front();
        index.pop();

        // if we check for filled position 
        // and only pass that nodes who appears first time
        // then its find Top View of Binary Tree
        if(!filled[position]){
            filled[position] = 1;
            ans[position] = temp->data;
        }

        // And if we just keep override the values with new values 
        // and do not check any condition, it stores those nodes 
        // whose are visible from bottom, 
        // then it found the bottom view of binary tree 

        // ans[position] = temp->data;

        if(temp->left){
            q.push(temp->left);
            index.push(position - 1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(position + 1);
        }
    }


    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}   