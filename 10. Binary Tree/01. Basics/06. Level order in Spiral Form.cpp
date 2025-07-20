#include <iostream>
using namespace std;

/*
Problem Name: Level Order Traversal in Spiral Form (Zigzag Level Order Traversal)
Link: https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

--------------------------------------------------------------------------------------------------------
🧠 Problem Statement:
You are given a binary tree. The task is to print its **level order traversal in spiral form** (also known as **zigzag traversal**).
In normal level order, we print nodes level by level from left to right. But in spiral form, we alternate the direction at each level:
- Level 0: Left → Right
- Level 1: Right → Left
- Level 2: Left → Right
- and so on...

--------------------------------------------------------------------------------------------------------
⏱ Time Complexity:
- O(N), where N is the number of nodes in the tree.
  Each node is visited exactly once.

📦 Space Complexity:
- O(N), due to usage of two stacks (at most N/2 nodes at one level in worst-case for complete binary tree).

--------------------------------------------------------------------------------------------------------
🪜 Step-by-Step Approach:

1. We are doing a level-order traversal, but in a spiral/zigzag way.
2. To do this efficiently, we use two stacks:
   - `lrs` (left-to-right stack)
   - `rls` (right-to-left stack)

3. We start by pushing the root node into the `lrs` stack.
4. Then, in a loop:
   a. While `lrs` is not empty:
      - Pop all elements from `lrs`.
      - For each node, push its **right child first**, then **left child** into `rls`.
      - This ensures the next level gets processed **right to left**.
   b. While `rls` is not empty:
      - Pop all elements from `rls`.
      - For each node, push its **left child first**, then **right child** into `lrs`.
      - This ensures the next level gets processed **left to right**.
5. Continue this alternation until both stacks are empty.
6. Collect the data from each node in the order they are processed and print them.

--------------------------------------------------------------------------------------------------------
📊 Example Binary Tree:

                1
              /   \
            2       3
           / \     / \
          4   5   6   7

🎯 Spiral Order Traversal Output:
Level 0 → Left to Right:         1
Level 1 → Right to Left:         3 2
Level 2 → Left to Right:         4 5 6 7

✅ Final Output: 1 3 2 4 5 6 7

--------------------------------------------------------------------------------------------------------
📈 Diagram Showing Stack Behavior (lrs and rls):

Stack `lrs` (Left-to-Right) → pushes children in: Right ➜ Left  
Stack `rls` (Right-to-Left) → pushes children in: Left ➜ Right  

                Level 0:     [1] → lrs
                Pop 1 from lrs → push right(3), then left(2) into rls

                Level 1:     [3, 2] → rls
                Pop 3 → push left(6), then right(7) into lrs  
                Pop 2 → push left(4), then right(5) into lrs

                Level 2:     [6, 7, 4, 5] → lrs (maintains left-to-right traversal)

--------------------------------------------------------------------------------------------------------
💡 Key Points / Best Practices:
- Avoid pushing next level nodes into the current stack to maintain correct level boundaries.
- Order of child node pushing is *reversed* depending on which stack is being processed.
- Use stacks instead of queues for zigzag level-order traversal due to their LIFO nature.
- Ensure null checks when pushing children to avoid segmentation faults.

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


int main(){
    cout<<"Enter the root Node: ";
    Node * root = tree();

    stack<Node *> lrs; // left to right stack
    stack<Node *> rls; // right to left stack
    vector<int>ans;

    lrs.push(root);

    while(!lrs.empty() || !rls.empty()){
        // first check for left to right stack
        if(!lrs.empty()){
            while(!lrs.empty()){
                Node *temp = lrs.top();
                lrs.pop();
                ans.push_back(temp->data);

                // if we want to push elementst in rls
                // then we also need to push the elements in the right to left way 
                // means first right element then left element 

                // And last we do push the elements in a current stack because 
                // it might contains the elements of current level and if we
                // push the elements of next level into the current stack it will 
                // miscalculate the ans, and gives a unwanted results 
                if(temp->right){
                    rls.push(temp->right);
                }
                if(temp->left){
                    rls.push(temp->left);
                }
            }
        }else{
            while(!rls.empty()){
                while(!rls.empty()){
                    Node *temp = rls.top();
                    rls.pop();
                    ans.push_back(temp->data);

                    // if we want to push elementst in lrs
                    // then we also need to push the elements in the left to right way 
                    // means first left element then right element 
                    if(temp->left){
                        lrs.push(temp->left);
                    }
                    if(temp->right){
                        lrs.push(temp->right);
                    }
                }
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}   