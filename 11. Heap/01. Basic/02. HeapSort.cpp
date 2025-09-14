#include<iostream>
using namespace std;


/*************************************************************************************
Problem: Heap Sort Algorithm Implementation
Source/Reference: [Heap Sort - GeeksforGeeks](https://www.geeksforgeeks.org/heap-sort/)
--------------------------------------------------------------------------------------
Problem Statement:
We are implementing the Heap Sort algorithm using a **Max Heap** data structure.  
The idea is to first build a max heap from the given array, then repeatedly extract 
the maximum element (root of the heap) and move it to the end of the array, reducing 
the heap size each time. This process sorts the array in ascending order.

--------------------------------------------------------------------------------------
Time and Space Complexity:
1. Time Complexity:
   - Building Max Heap: O(n)
   - Heapify operation (per element): O(log n)
   - HeapSort (n elements × log n): O(n log n)
   => Total: **O(n log n)**

2. Space Complexity:
   - Recursive Heapify: O(log n) (due to recursion stack)
   - Iterative Heapify: O(1)
   => Overall: **O(1) auxiliary space** (in iterative implementation)

--------------------------------------------------------------------------------------
Step-by-Step Approach:
1. **Build Max Heap**
   - Start from the last non-leaf node (at index n/2 - 1) and call Heapify.
   - This ensures the complete array satisfies the Max Heap property 
     (parent ≥ children).

2. **Heap Sort Process**
   - Swap the root element (maximum) with the last element in the heap.
   - Reduce heap size by 1 (excluding the last element which is now sorted).
   - Call Heapify on the root to restore the Max Heap property.
   - Repeat until the heap size becomes 0.

3. **Final Result**
   - The array is sorted in ascending order.

--------------------------------------------------------------------------------------
Beginner-Friendly Explanation with Diagram:

Think of a Max Heap as a binary tree where each parent is greater than or equal to its children.
For an array of size `n`, the parent-child relationship is:
   - Left child = 2 * index + 1
   - Right child = 2 * index + 2

Example: For the input array:
   [10, 3, 8, 9, 5, 13, 18, 14, 11, 70]

Step 1: Build Max Heap
   Represent as a binary tree (Max Heap):
   
                70
              /    \
            14      18
           /  \    /  \
         11    10  13   8
        / \    /
       9   5  3

Step 2: Extract Maximum (70), place it at end, reduce heap size.
   Swap(70, arr[last]) → Heapify again.
   Repeat this until all elements are placed at the correct position.

Step 3: Final Sorted Array
   [3, 5, 8, 9, 10, 11, 13, 14, 18, 70]

--------------------------------------------------------------------------------------
Key Insight:
- HeapSort is an in-place, comparison-based sorting algorithm.
- It is more memory-efficient than Merge Sort (O(1) vs O(n) extra space).
- However, unlike QuickSort, it is **not cache-friendly** because of its scattered memory access.

*************************************************************************************/



void Heapify(int arr[], int index, int n){

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(n > left && arr[left] > arr[largest]){
        largest = left;
    }

    if(n > right && arr[right] > arr[largest]){
        largest = right;
    }

    if(index != largest){
        swap(arr[index], arr[largest]);
        Heapify(arr, largest, n);
    }
}


void buildMaxHeap(int arr[], int n){
    for(int i=(n/2 -1);i>=0;i--){
        Heapify(arr, i, n);
    }
}


void heapSort(int arr[], int n){
    for(int i=n-1;i>=0;i--){
        // swap the first max element with index so it stores in the sorted order
        swap(arr[0], arr[i]);

        // then rearrange the heap for the first element
        // that's why we always send first element's index 
        // and also reduce the size of array to exclude the 
        // already sorted elements 
        Heapify(arr, 0, i);
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

    buildMaxHeap(arr, n);
    heapSort(arr, n);
    print(arr, n);
}