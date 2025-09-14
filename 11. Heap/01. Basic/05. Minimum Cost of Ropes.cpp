#include <iostream>
using namespace std;


/*
====================================================================================
Problem: Minimum Cost of Ropes
Link: https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?page=1&difficulty

------------------------------------------------------------------------------------
Problem Statement:
We are given N ropes of different lengths. We want to connect all ropes into one rope. 
The cost of connecting two ropes is equal to the sum of their lengths. After connecting, 
the new rope (with combined length) is added back into the set of ropes. 
We must keep repeating this process until only one rope is left. 
The task is to minimize the total cost of connecting the ropes.

------------------------------------------------------------------------------------
Example:
Input:  [4, 3, 2, 6]
Step 1: Pick smallest ropes (2, 3). Cost = 2+3 = 5. New ropes: [4, 5, 6]
Step 2: Pick smallest ropes (4, 5). Cost = 4+5 = 9. Total cost = 5+9 = 14. New ropes: [6, 9]
Step 3: Pick smallest ropes (6, 9). Cost = 6+9 = 15. Total cost = 14+15 = 29. New ropes: [15]
Final Rope: [15] with Minimum Total Cost = 29

------------------------------------------------------------------------------------
Intuition:
To minimize the cost, always connect the two shortest ropes first. 
Why? Because longer ropes will keep appearing in later steps, and combining them early 
will unnecessarily increase the cost. This is a greedy strategy.

------------------------------------------------------------------------------------
Approach (Step-by-Step):
1. Insert all rope lengths into a Min-Heap (priority queue in C++).
   - A Min-Heap allows us to efficiently extract the two smallest ropes each time.
2. While more than one rope remains in the heap:
   - Extract the two smallest ropes.
   - Add their lengths to get the cost of this connection.
   - Accumulate this cost into the total.
   - Push the new combined rope back into the heap.
3. When only one rope remains, the accumulated total is the minimum cost.

------------------------------------------------------------------------------------
Visualization (Heap Operations):

Initial Heap: [2, 3, 4, 6]  (Min-Heap auto-arranges)
----------------------------------------------------
Step 1: Pop(2, 3) → New Rope = 5 → Total Cost = 5
Heap after push: [4, 5, 6]

Step 2: Pop(4, 5) → New Rope = 9 → Total Cost = 5+9 = 14
Heap after push: [6, 9]

Step 3: Pop(6, 9) → New Rope = 15 → Total Cost = 14+15 = 29
Heap after push: [15]

Final Answer = 29

Diagram:

          Initial
         [2,3,4,6]
             ↓
        ┌─────────┐
        │ Pop 2,3 │
        └─────────┘
             ↓
         Cost=5
         [4,5,6]
             ↓
        ┌─────────┐
        │ Pop 4,5 │
        └─────────┘
             ↓
         Cost=14
          [6,9]
             ↓
        ┌─────────┐
        │ Pop 6,9 │
        └─────────┘
             ↓
         Cost=29
           [15]

------------------------------------------------------------------------------------
Complexity Analysis:
- Let N = number of ropes.
- Each insertion/deletion in a heap costs O(log N).
- We perform this operation N-1 times (since we combine ropes until one remains).
Time Complexity: O(N log N)
Space Complexity: O(N)   (for the priority queue storage)

------------------------------------------------------------------------------------
Industry Best Practice:
- Use a Min-Heap (priority_queue with greater<int>) for greedy problems involving 
  repeated extraction of the smallest elements.
- Always analyze time complexity against naive solutions (like sorting repeatedly, 
  which would give O(N^2)) and optimize with appropriate data structures.
====================================================================================
*/


int main(){
    vector<int>arr = {4, 3, 2, 6};
    priority_queue<int, vector<int>, greater<int>> p;

    int cost = 0;

    // populate queue;
    for(int i=0;i<arr.size();i++){
        p.push(arr[i]);
    }

    while(p.size() > 1){
        int first_rope = p.top(); p.pop();
        int second_rope = p.top(); p.pop();

        int new_rope = first_rope + second_rope;
        cost += new_rope;
        p.push(new_rope);
    }

    cout<<cost;
}