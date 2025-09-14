#include<iostream>
using namespace std;


/*
====================================================================
Problem: Building a Heap (Min Heap and Max Heap) from an Array
====================================================================

Reference:
- Heap Data Structure (GeeksforGeeks): https://www.geeksforgeeks.org/heap-data-structure/
- CLRS (Introduction to Algorithms) Heap Chapter

--------------------------------------------------------------------
💡 Problem Statement:
We are given an unsorted array of integers, and our task is to 
transform it into a valid Heap data structure. A heap is a complete 
binary tree that satisfies one of the following properties:

1. **Max Heap**: Each parent node is greater than or equal to its children.
2. **Min Heap**: Each parent node is less than or equal to its children.

This code demonstrates how to:
- Convert an array into a Max Heap using the "maxHeapify" process.
- Convert an array into a Min Heap using the "minHeapify" process.

The heap is stored in array form, where:
- For node at index i:
    - Left child = 2*i + 1
    - Right child = 2*i + 2
    - Parent = (i-1)/2

--------------------------------------------------------------------
⏳ Time Complexity Analysis:

1. **Heapify (single node)**: O(log n)
   - Because in the worst case, we may have to move the node all the way 
     down to a leaf, traversing the height of the tree (log n).

2. **Build Heap (entire array)**: O(n)
   - Starting from the last non-leaf node at index n/2 - 1 and calling 
     heapify ensures each node is adjusted in optimal time.
   - Surprisingly, this is O(n), not O(n log n), because most heapify 
     calls occur on smaller subtrees.

📌 Space Complexity:
- O(1) auxiliary space (in-place transformation).
- The array itself represents the heap; no extra space is required.

--------------------------------------------------------------------
🛠️ Step-by-Step Approach:

1. **MaxHeapify/MinHeapify Function:**
   - Look at a node and its children.
   - Find the largest (for Max Heap) or smallest (for Min Heap).
   - If the parent does not satisfy heap property, swap with child.
   - Recursively heapify the affected subtree.

2. **Build Heap Function:**
   - Start from the last non-leaf node: index = (n/2 - 1).
   - Move backwards up to index 0.
   - For each node, call heapify to enforce heap property.
   - By the end, the entire array satisfies the heap structure.

3. **Printing the Heap:**
   - Traverse the array and print elements sequentially.

--------------------------------------------------------------------
📊 Visual Diagram: Array to Heap Conversion

Example Input Array:
    arr = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70}

Step 1: Visualize array as a complete binary tree
               10
           /       \
          3         8
        /   \     /   \
       9     5   13   18
      / \   / 
    14 11 70 

Step 2: Apply Build Min Heap
- Start from last non-leaf node (index n/2 - 1).
- Heapify each subtree.
- Final tree (Min Heap):

                3
           /        \
          5          8
       /    \      /    \
     9      10   13     18
    / \     / 
  14 11   70 

Step 3: The array now represents this Min Heap:
    {3, 5, 8, 9, 10, 13, 18, 14, 11, 70}

--------------------------------------------------------------------
✅ Beginner-Friendly Explanation:

Think of a heap as a "priority queue" where parents must always be 
greater (Max Heap) or smaller (Min Heap) than their children. 
We use an array to store it, and we can navigate like a tree using 
simple index math. 

- **Heapify** is like fixing a single family: if the parent breaks the 
  rule, swap them until order is restored. 
- **Build Heap** is like fixing the entire neighborhood: start from the 
  bottom-most parents and keep fixing until the root also follows the 
  rule. 

By the end, the whole tree is well-structured!

====================================================================
*/


void maxHeapify(int arr[], int index, int n){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest], arr[index]);
        maxHeapify(arr, largest, n);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = (n/2 - 1);i >= 0;i--){
        maxHeapify(arr, i, n);
    }
}


void minHeapify(int arr[], int index, int n){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != index){
        swap(arr[smallest], arr[index]);
        minHeapify(arr, smallest, n);
    }
}

void buildMinHeap(int arr[], int n){
    for(int i = (n/2 - 1);i >= 0;i--){
        minHeapify(arr, i, n);
    }
}


void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14,11, 70};
    int n = size(arr);
    // buildMaxHeap(arr, n);
    buildMinHeap(arr, n);
    print(arr, n);
}