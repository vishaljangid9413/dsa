#include<iostream>
using namespace std;


/*
===========================================================
Problem: Kth Smallest Element in an Array
-----------------------------------------------------------
Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Statement:
-----------
Given an array of integers, find the Kth smallest element.
For example:
    Input: arr = [2, 3, 1, 20, 15], K = 4
    Output: 15
Explanation: The elements in sorted order are [1, 2, 3, 15, 20].
             The 4th smallest element is 15.

-----------------------------------------------------------
Time Complexity Analysis:
--------------------------
1. Building the initial max-heap of size K: O(K log K)
2. Iterating through remaining (N - K) elements, and for each:
       - Compare with heap’s top: O(1)
       - If smaller, pop + push into heap: O(log K)
   Total = O((N - K) log K)
Overall Time Complexity = O(N log K)

Space Complexity Analysis:
---------------------------
- A max-heap of size K is used → O(K) space.

-----------------------------------------------------------
Step-by-Step Approach:
-----------------------
1. Create a max-heap (priority_queue in C++ by default is max-heap).
2. Insert the first K elements of the array into the heap.
   → The heap now contains the smallest K elements found so far,
     but the root (top) is the LARGEST among them.
3. For each remaining element in the array:
   a. Compare it with the heap’s root.
   b. If the element is smaller than the root:
        - Remove the root (largest of the K elements).
        - Insert this smaller element into the heap.
   c. Otherwise, ignore the element (since it’s not among the K smallest).
4. At the end, the root of the heap is the Kth smallest element.

-----------------------------------------------------------
Visualization (Example: arr = [2, 3, 1, 20, 15], K = 4):
-----------------------------------------------------------

Step 1: Insert first K elements → [2, 3, 1, 20]
Max-Heap = [20, 3, 1, 2]   (20 is root)

Step 2: Check next element → 15
Compare 15 with root (20).
Since 15 < 20 → Remove 20, Insert 15.

Heap after update = [15, 3, 1, 2]

Now, heap contains the 4 smallest elements: [15, 3, 1, 2]
Root = 15 → This is the 4th smallest element.

-----------------------------------------------------------
Diagram of Heap Process:
-----------------------------------------------------------

           [20]                 [15]
          /    \               /    \
        [3]    [1]   →      [3]    [1]
       /                   /
     [2]                 [2]

-----------------------------------------------------------
Key Insight:
-------------
- Using a max-heap ensures we always keep track of the smallest K elements.
- The heap’s root (maximum among them) gives us the Kth smallest element.
===========================================================
*/



int main(){
    vector<int>arr = {2, 3, 1, 20, 15};
    int n = arr.size();
    int k = 4;

    priority_queue<int>p;

    // fille queue with k elements
    for(int i=0;i<k;i++){
        p.push(arr[i]);
    }

    // iterate through remaining elements
    for(int i=k;i<n;i++){
        if(arr[i] < p.top()){
            p.pop();
            p.push(arr[i]);
        }
    }

    cout<<p.top();
}