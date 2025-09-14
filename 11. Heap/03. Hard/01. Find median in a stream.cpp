#include<iostream>
using namespace std;


/*
-----------------------------------------------------------------------------------
Problem: Find Median in a Stream
Link: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1?page=1&difficulty%5B%5D=2&category%5B%5D=Heap&sortBy=submissions

Statement:
-----------
We are given a stream of integers (numbers arriving one by one).
After each new number is added, we must output the **current median** of all numbers 
seen so far.

Definition:
- Median = middle value of sorted data.
    - If odd count → the exact middle element.
    - If even count → average of the two middle elements.

Example:
---------
Input Stream: [4, 3, 1, 29, 24]
Step 1: [4] → median = 4
Step 2: [3,4] → median = (3+4)/2 = 3.5
Step 3: [1,3,4] → median = 3
Step 4: [1,3,4,29] → median = (3+4)/2 = 3.5
Step 5: [1,3,4,24,29] → median = 4

Output: [4, 3.5, 3, 3.5, 4]

-----------------------------------------------------------------------------------
Time and Space Complexity:
---------------------------
- Insertion into heap: O(log n)
- Finding median: O(1) (just peek at tops of heaps)
- Total for n elements: O(n log n)
- Space Complexity: O(n) (two heaps storing all elements)

-----------------------------------------------------------------------------------
Step-by-Step Approach:
-----------------------
1. Use **two heaps**:
   - Left Heap (Max-Heap): stores the smaller half of the numbers.
   - Right Heap (Min-Heap): stores the larger half of the numbers.

   Why two heaps?
   - Max-Heap gives easy access to the largest element of the left half.
   - Min-Heap gives easy access to the smallest element of the right half.
   Together, they help us quickly find the median.

2. Balancing the heaps:
   - Ensure the size difference between heaps is at most 1.
   - Left Heap may contain one extra element if total numbers are odd.

3. Insertion Logic:
   - Case 1: Left Heap empty → push first element into it.
   - Case 2: Left Heap bigger than Right Heap → push new element into Right Heap
             or rebalance if needed.
   - Case 3: Both heaps same size → push into Left Heap or rebalance if needed.

4. Median Calculation:
   - If sizes are equal → median = (top of Left + top of Right) / 2
   - If unequal → median = top of Left Heap (since it holds the extra element)

-----------------------------------------------------------------------------------
Visualization:
--------------
Let’s visualize with input: [4, 3, 1, 29]

Step 1: Insert 4
Left Heap (max): [4]
Right Heap (min): []
Median = 4

Step 2: Insert 3
Left Heap: [3]       Right Heap: [4]
Median = (3+4)/2 = 3.5

Step 3: Insert 1
Left Heap: [3,1]     Right Heap: [4]
Median = 3

Step 4: Insert 29
Left Heap: [3,1]     Right Heap: [4,29]
Median = (3+4)/2 = 3.5

Diagram Flow (Heaps growth over time):

Stream:        4        3          1             29
Left Heap:    [4]     [3]        [3,1]        [3,1]
Right Heap:   []      [4]        [4]          [4,29]
Median:        4      3.5         3            3.5

-----------------------------------------------------------------------------------
Key Takeaway:
-------------
The two-heap method ensures:
- Fast insertion (O(log n))
- Instant median retrieval (O(1))
This is a standard and industry-preferred solution for the "Median in a Stream" problem.
-----------------------------------------------------------------------------------
*/


int main(){
    vector<int> arr = {4, 3, 1, 29, 24, 22, 22, 6, 15, 2, 1};
    int n = arr.size();
    vector<double>medians;
    
    priority_queue<int>leftHeap;
    priority_queue<int, vector<int>, greater<int>>rightHeap;
    
    for(int i=0;i<n;i++){
        if (leftHeap.empty()){
            leftHeap.push(arr[i]);
        }else if(leftHeap.size()>rightHeap.size()){
            if(leftHeap.top()>arr[i]){
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(arr[i]);
            }else{
                rightHeap.push(arr[i]);
            }
        }else{
            if(rightHeap.top()<arr[i]){
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(arr[i]);
            }else{
                leftHeap.push(arr[i]);
            }
        }

        if(leftHeap.size() == rightHeap.size()){
            double ans = leftHeap.top() + rightHeap.top();
            ans /= 2;
            medians.push_back(ans);
        }else{
            medians.push_back(leftHeap.top());

        }
    }

    for(int i=0;i<medians.size();i++){
        cout<<medians[i]<<" ";
    }
        
}


