#include <iostream>
using namespace std;


/*
-----------------------------------------------------------------------------------------
Problem: Demonstration of Priority Queues in C++ (Max Heap and Min Heap)

Reference: 
- C++ Standard Template Library (STL) - priority_queue 
  (https://en.cppreference.com/w/cpp/container/priority_queue)

-----------------------------------------------------------------------------------------
Time and Space Complexity:
- Insertion (push): O(log N)   → because each insertion maintains the heap property.
- Access top element (top): O(1) → returns the largest (max heap) or smallest (min heap).
- Deletion (pop): O(log N) → rearranges elements after removing the top.
- Space Complexity: O(N) → where N is the number of elements in the heap.

-----------------------------------------------------------------------------------------
Step-by-Step Approach:
1. **Max Heap (default priority_queue<int>):**
   - By default, C++ priority_queue is implemented as a max heap.
   - This means the largest element is always at the top.
   - Example sequence:
     Insert: 1 → 10 → 15 → 4
     Heap structure after insertion ensures `15` is always at the top.

2. **Min Heap (priority_queue<int, vector<int>, greater<int>>):**
   - To create a min heap, we use `greater<int>` as the comparator.
   - This means the smallest element is always at the top.
   - Example sequence:
     Insert: 44 → 13 → 101
     Heap structure ensures `13` is always at the top.

-----------------------------------------------------------------------------------------
Diagrammatic Visualization:

Max Heap Example (after inserting 1, 10, 15, 4):

                  15
                 /  \
               10    1
              /
             4

- `p.top()` will give `15`.

Min Heap Example (after inserting 44, 13, 101):

                  13
                 /  \
               44    101

- `mp.top()` will give `13`.

-----------------------------------------------------------------------------------------
Beginner-Friendly Explanation:
- A **heap** is like a special tree where the parent is always greater (max heap) 
  or smaller (min heap) than its children.
- `priority_queue` in C++ is a container adaptor that provides this behavior automatically.
- Think of it like a line where the "highest priority" element always comes first:
  - In max heap → biggest number is highest priority.
  - In min heap → smallest number is highest priority.
- You don’t have to rearrange elements yourself; the priority_queue does it internally.

-----------------------------------------------------------------------------------------
*/


int main(){
    // max heap
    priority_queue<int>p;

    p.push(1);
    p.push(10);
    p.push(15);
    p.push(4);

    cout<<p.top()<<endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>>mp;
    mp.push(44);
    mp.push(13);
    mp.push(101);
    cout<<mp.top();
}
