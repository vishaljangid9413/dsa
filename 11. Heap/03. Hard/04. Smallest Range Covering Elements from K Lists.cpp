#include<iostream>
using namespace std;


/*
Problem: Smallest Range Covering Elements from K Lists
Source: LeetCode
Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

Description:
Given k sorted integer arrays, the task is to find the smallest range [a, b] such that 
at least one element from each of the k lists lies within this range. 

Example:
Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation: The range 20 to 24 includes at least one element from each list:
- 24 from first list
- 20 from second list
- 22 from third list

Time Complexity:
O(n log k) 
- n = total number of elements across all lists
- k = number of lists
Explanation: Each element is pushed and popped from a min-heap at most once. Each heap operation takes O(log k) time.

Space Complexity:
O(k)
- The min-heap stores at most one element from each list at a time, so the space used is proportional to the number of lists.

Step-by-Step Approach:
1. **Initialization**:
   - Push the first element of each of the k arrays into a min-heap. 
   - Track the maximum element among these first elements (initial `maximum`).
   - Initialize the smallest range using the smallest element in the heap (`minimum`) and `maximum`.

2. **Heap Operations**:
   - While the heap has k elements:
     a. Extract the smallest element from the min-heap (`minimum`).
     b. Identify which array (`row`) and which index (`col`) this element came from.
     c. If there’s a next element in the same array:
        - Push it into the min-heap.
        - Update `maximum` if the new element is larger.
        - Update the smallest range `[ans[0], ans[1]]` if the new range (`maximum - minimum`) is smaller than the previous range.

3. **Termination**:
   - The loop terminates when one of the arrays runs out of elements, i.e., the heap size < k.
   - The stored range `[ans[0], ans[1]]` is the minimum range containing at least one element from each list.

Visual Explanation:

Heap at start (first elements):
            0
          /   \
        4       5
       /         \
     10           18

Step 1: Pop smallest (0), push next element from the same array (9), update max to 18.

Step 2: Pop smallest (4), push next element (10), update max if necessary, check if new range is smaller.

Step 3: Repeat until one list is exhausted.

Diagram of range update logic:

          Heap
      +------------------+
      | min = top of heap | <- current minimum
      | max = maximum     | <- track max among current elements
      +------------------+
               |
               v
   If (max - min < ans[1] - ans[0]) update ans

Key Idea:
- Always maintain a window of k elements (one from each array) using a min-heap.
- The minimum element is always at the top of the heap.
- By moving the smallest element forward, we try to shrink the range while including elements from all lists.

Best Practices:
- Use `priority_queue` with custom comparator (`greater<>`) for min-heap.
- Track both row and column indices in heap elements to know which array the element came from.
- Always update `maximum` after pushing a new element to the heap.
*/


int main(){
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    int k = nums.size();

    // define pair aliase
    using PairType = pair<int, pair<int, int>>;

    // define the element, minimum and maximum element
    PairType element;
    int row, col;
    int minimum, maximum = INT_MIN;

    // store first elemnt of every array in min heap
    priority_queue<PairType, vector<PairType>, greater<PairType>>p;
    for(int i =0;i<k;i++){
        p.push(make_pair(nums[i][0], make_pair(i, 0)));
        // store the maxmimum element 
        maximum = max(maximum, nums[i][0]);
    }

    minimum = p.top().first;

    // define the ans array with size 2;
    vector<int>ans = {minimum, maximum};

    // iterate through heap till its the size of k
    // here we have to simply store 3 elements and only remove smallest element 
    // and update its next element from array
    while(p.size() == k){
        element = p.top(); p.pop();
        row = element.second.first;
        col = element.second.second;

        // update the queue only if the next element is presernt
        if(col + 1 < nums[row].size()){
            p.push(make_pair(nums[row][col + 1], make_pair(row, col + 1)));

            // update minimum and maximum elemnt 
            minimum = p.top().first;
            maximum = max(maximum, nums[row][col + 1]);

            // now check if the current range is smaller than the stored one
            if(maximum - minimum < ans[1] - ans[0]){
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
    }

    cout<<ans[0]<<" "<<ans[1];
}