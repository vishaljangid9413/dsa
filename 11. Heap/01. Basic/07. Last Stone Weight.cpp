#include<iostream>
using namespace std;

/*
Problem: Last Stone Weight
Source: https://leetcode.com/problems/last-stone-weight/

---------------------------------------------------------
📝 Problem Statement:
We are given an array of stones, where each element represents the weight of a stone. 
We repeatedly perform the following operation until there is at most one stone left:
    1. Select the two heaviest stones.
    2. Smash them together:
        - If they are equal, both stones are destroyed.
        - If they are unequal, the smaller one is destroyed, and the remaining stone 
          has weight = (heavier - lighter).
    3. Insert the resulting stone back into the collection (if > 0).
The goal is to return the weight of the final stone, or 0 if no stones remain.

---------------------------------------------------------
⏱️ Time Complexity:
- Insertion into a max-heap / priority_queue → O(log n)
- Each stone may be inserted and removed → O(n log n)
Total Time Complexity = **O(n log n)**

💾 Space Complexity:
- The priority queue stores all stones → O(n)
- Apart from this, no extra space is used → **O(n)**

(Note: The code comments incorrectly state O(1) space, but in reality, 
the priority queue stores up to n elements.)

---------------------------------------------------------
📘 Step-by-Step Approach:
1. Insert all stone weights into a max-heap (priority_queue in C++).
   - This ensures we can always get the two heaviest stones in O(log n) time.
   
2. While more than one stone remains:
   - Extract the two heaviest stones.
   - Compute the difference (first - second).
   - If the result > 0, push it back into the heap (because a new smaller stone remains).
   
3. At the end:
   - If the heap is empty, return 0 (all stones destroyed).
   - Otherwise, return the top element (the last remaining stone).

---------------------------------------------------------
🔍 Visual Example:
Input: [2, 7, 4, 2, 9, 1]

Step 1: Insert into max-heap  
Heap (max at top): [9, 7, 4, 2, 2, 1]

Step 2: Pop two largest → (9, 7)  
New stone = 9 - 7 = 2 → Push back  
Heap: [4, 2, 2, 2, 1]

Step 3: Pop two largest → (4, 2)  
New stone = 4 - 2 = 2 → Push back  
Heap: [2, 2, 2, 1]

Step 4: Pop two largest → (2, 2)  
New stone = 0 → Ignore  
Heap: [2, 1]

Step 5: Pop two largest → (2, 1)  
New stone = 2 - 1 = 1 → Push back  
Heap: [1]

End → Only one stone remains → Answer = 1

---------------------------------------------------------
📊 Diagram: (Heap Operations Flow)

Initial:   [9, 7, 4, 2, 2, 1]
            |
        ┌───┴───┐
      [9]       rest
       |
   Pop (9,7)
       ↓
Push 2 back
       ↓
    [4, 2, 2, 2, 1]
       |
   Pop (4,2)
       ↓
Push 2 back
       ↓
    [2, 2, 2, 1]
       |
   Pop (2,2)
       ↓
No push (0)
       ↓
    [2, 1]
       |
   Pop (2,1)
       ↓
Push 1 back
       ↓
    [1]  ← Final Answer

---------------------------------------------------------
✅ Key Insight:
- The use of a max-heap is crucial because we always need to pick 
  the two largest elements efficiently.
- If we tried using sorting after each operation, it would be much slower (O(n² log n)).

---------------------------------------------------------
Industry Best Practice:
- Always prefer priority_queue for "largest/smallest element repeatedly" problems.
- Double-check space complexity when using heaps, as they grow with input size.
*/


int main(){
    int arr[] = {2,7,4,2,9,1};
    int n = size(arr);

    priority_queue<int>p;

    for(int i=0;i<n;i++){
        p.push(arr[i]);
    }

    while(p.size() > 1){
        int first = p.top(); p.pop();
        int second = p.top(); p.pop();

        int remaining_elements = first - second;
        if(remaining_elements > 0){
            p.push(remaining_elements);
        }
    }

    // if priority queue is empty then return 0
    cout<<(p.empty() ? 0 : p.top());
}


int main(){
    int arr[] = {2,7,4,2,9,1};
    int n = size(arr);

    priority_queue<int>p;

    for(int i=0;i<n;i++){
        p.push(arr[i]);
    }

    while(p.size() > 1){
        int first = p.top(); p.pop();
        int second = p.top(); p.pop();

        int remaining_elements = first - second;
        if(remaining_elements > 0){
            p.push(remaining_elements);
        }
    }

    // if poritiy queue is empty then reutrn 0
    cout<<(p.empty() ? 0 : p.top());

}