#include <iostream>
using namespace std;


/*
===============================================
Problem: Check if a Binary Tree is a Heap
Source: GeeksforGeeks - https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions
===============================================

🔹 Problem Statement:
We are given a binary tree. The task is to determine whether this binary tree satisfies the properties of a Heap.
A Heap must satisfy two conditions:
1. **Complete Binary Tree (CBT):**
   - All levels are completely filled except possibly the last level.
   - The last level must have all keys as left as possible.
2. **Heap Order Property (Max-Heap in this case):**
   - Every parent node must have a value greater than or equal to its children.

---

⏱️ Time Complexity:
1. Counting nodes: O(N), where N is the number of nodes.
2. Checking CBT: O(N), since each node is visited once.
3. Checking Max-Heap property: O(N), each node checked once.
➡️ **Total Time Complexity: O(N)**

💾 Space Complexity:
- Recursive stack depth = O(H), where H is the height of the tree.
- Worst case (skewed tree): O(N).
➡️ **Total Space Complexity: O(N)**

---

🛠️ Step-by-Step Approach:
1. **Count Total Nodes:**
   - Use recursion to count all nodes in the binary tree.
   - This helps us later verify the CBT property.

2. **Check for Complete Binary Tree (CBT):**
   - Index nodes as if they were stored in an array (like heap representation).
   - For node at index `i`:
     - Left child index = `2*i + 1`
     - Right child index = `2*i + 2`
   - If any node index ≥ total number of nodes, it violates CBT.

3. **Check for Max-Heap Property:**
   - Recursively ensure that for every node:
     - Node value ≥ left child’s value (if exists).
     - Node value ≥ right child’s value (if exists).
   - Continue checking for both left and right subtrees.

4. **Final Result:**
   - If both CBT and Max-Heap conditions hold true → The tree is a Heap.
   - Otherwise, it is not.

---

📊 Visualization (Example):

Consider the tree:
             10
           /    \
         9        8
       /  \      /
      7    6    5

Step 1: Count Nodes → Total = 6

Step 2: CBT Check:
- Indexing nodes as array → [10, 9, 8, 7, 6, 5]
- All nodes fit correctly, no missing child → ✅ Complete Binary Tree.

Step 3: Max-Heap Property:
- 10 ≥ 9 and 10 ≥ 8
- 9 ≥ 7 and 9 ≥ 6
- 8 ≥ 5
✅ Max-Heap holds.

Final Answer → This tree is a Heap.

---

📐 Diagram (Heap Representation):

Array Representation: [10, 9, 8, 7, 6, 5]

                10 (index 0)
               /   \
         9 (1)       8 (2)
        /   \       /
   7 (3)   6 (4)  5 (5)

Observation:
- Structure is CBT (all nodes filled left-to-right).
- Parent values are always ≥ children.
- Hence, it is a Max-Heap.

===============================================
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

int Count(Node *root){
    if(!root){
        return 0;
    }

    return 1 + Count(root->left) + Count(root->right);
}

bool isCbt(Node *root, int index, int total_size){
    if(!root){
        return true;
    }

    if(index >= total_size){
        return false;
    }

    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    return isCbt(root->left, left_child, total_size) && isCbt(root->right, right_child, total_size);
}

bool MaxHeap(Node *root){
    if(!root){
        return 0;
    }

    if(root->left){
        if(root->data < root->left->data){
            return false;
        }

        if(!MaxHeap(root->left)){
            return false;
        }
    }

    if(root->right){
        if(root->data < root->right->data){
            return false;
        }

        // here we simply return the Maxheap output because
        // because in this case we do not need to check left part again 
        return MaxHeap(root->right);
    }

    return true;
}

int main(){
    cout<<"Enter the root Node: ";
    Node *root; 
    root = tree();

    // count the number of tree
    int num = Count(root);

    // now check that its a complete binary tree or not
    if(!isCbt(root, 0, num)){
        cout<<0;
        return 0;
    }

    cout<<MaxHeap(root);
}