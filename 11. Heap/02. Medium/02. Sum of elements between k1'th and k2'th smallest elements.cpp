#include<iostream>
using namespace std;

/****************************************************
 Problem: Sum of Elements Between Two k-th Smallest Elements
 Source: GeeksforGeeks
 Link: https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1?page=1&difficulty%5B%5D=0&category%5B%5D=Heap&sortBy=submissions

 ----------------------------------------------------
 Problem Statement:
 We are given an array of integers and two integers k1 and k2. 
 Our task is to find the sum of all elements that lie between 
 the k1-th smallest element and the k2-th smallest element 
 in the array (excluding the k1-th and k2-th elements themselves).

 Example:
   Input:
      arr = [20, 8, 22, 4, 12, 10, 14]
      k1 = 3, k2 = 6
   Step 1: Sort the array → [4, 8, 10, 12, 14, 20, 22]
   Step 2: Identify k1-th and k2-th smallest:
              k1 = 3 → 10
              k2 = 6 → 20
   Step 3: Elements between 10 and 20 are [12, 14]
   Step 4: Sum = 12 + 14 = 26
   Output: 26

 ----------------------------------------------------
 Time Complexity:
   - Inserting all n elements into a min-heap → O(n log n)
   - Extracting all elements from the heap → O(n log n)
   - Overall: O(n log n)

 Space Complexity:
   - Heap stores n elements → O(n)
   - No extra data structures apart from heap → O(n)

 ----------------------------------------------------
 Step-by-Step Approach:
 1. Insert all elements of the array into a min-heap 
    (priority queue with "greater<int>" comparator).
    - This ensures that the smallest elements come out first.
 2. Pop elements one by one while keeping track of index "i".
    - When "i" equals k1, we skip that element (k1-th smallest).
    - When "i" equals k2, we stop before including it (k2-th smallest).
    - For all elements between indices k1 and k2-1, add them to the sum.
 3. Print the sum at the end.

 ----------------------------------------------------
 Visual Explanation (Heap Processing):

   Given arr = [20, 8, 22, 4, 12, 10, 14]
   Min-Heap (internally arranged for extraction):
             4
           /   \
          8     10
         / \    / \
       20  12 14  22

   Extraction Order (sorted): 4 → 8 → 10 → 12 → 14 → 20 → 22
   Indexes:       i=0  i=1  i=2  i=3  i=4  i=5  i=6

   k1 = 3 → Skip element at i=2 (value=10)
   k2 = 6 → Stop before i=5 (value=20)
   Add elements between them → [12, 14]
   Result = 26

 ----------------------------------------------------
 Beginner-Friendly Analogy:
 Imagine lining up numbers in ascending order.
 - You mark two positions: the k1-th person and the k2-th person in line.
 - Then you add up the values of everyone standing strictly between 
   those two marked positions.

****************************************************/


int main(){
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>>max_heap;

    for(int i=0;i<n;i++){
        max_heap.push(arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(i >= k1 && i < k2-1){
            ans += max_heap.top();
        }
        max_heap.pop();
    }

    cout<<ans;
}