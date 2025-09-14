#include <iostream>
using namespace std;



/*
Problem: K-th Smallest Element in a Sorted Matrix
------------------------------------------------
We are given an N x N matrix where each row and column is sorted in ascending order.
The task is to find the k-th smallest element in this matrix.

Reference Link: 
https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1?page=1&difficulty[]=1&category[]=Heap&sortBy=submissions


------------------------------------------------
Time and Space Complexity
------------------------------------------------
Time Complexity: O(k * log(n))
    - Each insertion and extraction from the priority queue takes O(log n).
    - In the worst case, we repeat this process k times.
    - Hence, overall complexity is O(k log n).

Space Complexity: O(n)
    - At any time, the priority queue holds at most 'n' elements (one from each row).
    - So space complexity is O(n), not O(n^2).

------------------------------------------------
Step-by-Step Approach
------------------------------------------------
1. **Matrix Properties:**
   - Each row and each column is sorted.
   - This means the smallest element is at the top-left (mat[0][0]).
   - For each row, elements increase as we move right.
   - For each column, elements increase as we move down.

2. **Using a Min-Heap (Priority Queue):**
   - Insert the **first element of each row** into a min-heap.
     - Each heap entry is a pair: (value, (row_index, column_index)).
   - The heap ensures that the smallest element is always at the top.

3. **Extract Elements One by One:**
   - Pop the smallest element from the heap.
   - Keep a count of how many elements have been popped.
   - Once we've popped k times, the element popped is the answer.

4. **Push Next Element from the Same Row:**
   - After popping an element (value at [i][j]), insert the next element from the same row: [i][j+1], if it exists.
   - This maintains the heap property and ensures we always consider the next possible candidates for the smallest element.

5. **Repeat Until k Elements are Extracted.**

------------------------------------------------
Visualization with Example
------------------------------------------------
Matrix (4x4):
    10   20   30   40
    15   25   35   45
    24   29   37   48
    32   33   39   50

k = 7

Step 1: Push first element of each row into min-heap:
    Heap = [10, 15, 24, 32]

Step 2: Extract elements one by one:
    Pop 1 -> 10 (push 20) → Heap = [15, 20, 24, 32]
    Pop 2 -> 15 (push 25) → Heap = [20, 25, 24, 32]
    Pop 3 -> 20 (push 30) → Heap = [24, 25, 30, 32]
    Pop 4 -> 24 (push 29) → Heap = [25, 29, 30, 32]
    Pop 5 -> 25 (push 35) → Heap = [29, 32, 30, 35]
    Pop 6 -> 29 (push 37) → Heap = [30, 32, 35, 37]
    Pop 7 -> 30 → Answer = 30

Final Answer: 30


------------------------------------------------
Diagram (Heap Visualization)
------------------------------------------------
Heap after initial insertion (min-heap):
         10
       /    \
     15      24
    /
  32

After first pop (10 removed, 20 inserted):
         15
       /    \
     20      24
    /
  32

... process continues until the 7th element is extracted.


------------------------------------------------
Key Idea (Beginner Friendly)
------------------------------------------------
Think of the min-heap as a "smart container" that always gives you 
the next smallest number. 
- We start by adding the smallest numbers (first column).
- Each time we take one out, we add the "next neighbor" from the same row.
- After doing this k times, the last number we removed is the k-th smallest.
*/


int main(){
    vector<vector<int>>mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int k = 7;
    int n = mat.size();

    // first push n elements to a vector
    vector<pair<int, pair<int, int>>>temp;
    for(int i=0;i<n;i++){
        temp.push_back(
            make_pair(mat[i][0], make_pair(i, 0))
        );
    }

    // now fill the min priority queue with temp elements
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    >p(temp.begin(), temp.end());

    // now travarse through queue and fill out the kth element
    // and while popping out an elment, push its next index element 
    int ans, i, j;
    pair<int, pair<int, int>>element;

    while(k--){
        element = p.top(); p.pop();
        ans = element.first;
        i = element.second.first;
        j = element.second.second;

        if(j + 1 < n){
            p.push(make_pair(mat[i][j+1], make_pair(i, j+1)));
        }
    }

    cout<<ans;
}