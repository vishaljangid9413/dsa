#include <iostream>
using namespace std;


/*
=========================================================
📝 Problem: Merge K Sorted Linked Lists
---------------------------------------------------------
We are given an array of K sorted linked lists. The goal is 
to merge them into a single sorted linked list.

🔗 Problem Link: 
https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

=========================================================
⏳ Time Complexity:
- Building the heap initially: O(K)
- Each node is inserted & removed from the heap exactly once.
- Heap operations (push/pop) take O(log K).
- If the total number of nodes across all lists = N,
  total = O(N log K)

📦 Space Complexity:
- O(K) for storing the heap (at most one node from each list).
- O(1) extra space apart from output list.

=========================================================
🛠️ Step-by-Step Approach:
1. **Initialization**:
   - We are given K sorted linked lists.
   - Create a Min Heap (priority_queue with custom comparator)
     to always extract the node with the smallest value.

2. **Heap Building**:
   - Insert the first node (head) of each linked list into the heap.

3. **Merging Process**:
   - Repeatedly extract the smallest element from the heap.
   - Append this node to the result linked list.
   - If the extracted node has a `next` pointer (more nodes left in that list),
     insert the `next` node into the heap.

4. **Termination**:
   - Continue until the heap is empty.
   - The merged linked list is built by connecting nodes in order.

=========================================================
📊 Diagram (Example with K=3):
Input:
  List1: 1 -> 4 -> 5
  List2: 1 -> 3 -> 4
  List3: 2 -> 6

Step 1: Insert first nodes into Min Heap → [1, 1, 2]

Step 2: Extract min (1), append to result:
  Result: 1
  Heap: [1, 2, 4]  (pushed 4 from List1)

Step 3: Extract min (1), append:
  Result: 1 -> 1
  Heap: [2, 4, 3]  (pushed 3 from List2)

Step 4: Extract min (2), append:
  Result: 1 -> 1 -> 2
  Heap: [3, 4, 6]  (pushed 6 from List3)

Step 5: Continue until heap is empty...

Final Output:
  Merged List = 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

=========================================================
✅ Key Insight:
Using a Min Heap ensures we always pick the smallest available
node across all lists, maintaining sorted order efficiently.
=========================================================
*/


class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Custom{
    public:
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};


int main(){
    vector<Node *>arr;

    // create min heap with custom sorting
    // because it contains Node * elements and we have to guide it that how we want to sort 
    priority_queue<Node *, vector<Node *>, Custom>p(arr.begin(), arr.end());

    // start travarsing
    // defining a dummy node to make the loop simpler
    Node *root = new Node(0);
    Node *tail = root;

    Node *temp;

    while(!p.empty()){
        // retrieve minimum element
        temp = p.top(); p.pop();
        tail->next = temp;
        tail = tail->next;

        if(temp->next){
            p.push(temp->next);
        }
    }

    // because root itself points to 0
    cout<<root->next;
}