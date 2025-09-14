#include<iostream>
using namespace std;

/*
================================================================================
Problem: Implementation of a Max Heap (Insert, Delete, and Print Operations)
--------------------------------------------------------------------------------
A Max Heap is a complete binary tree where the value of each parent node 
is greater than or equal to the values of its child nodes. The maximum 
element is always at the root (index 0). This implementation provides:

1. Insertion of elements while maintaining the Max Heap property.
2. Deletion of the root element (maximum) while maintaining the structure.
3. Heapify process to restore the Max Heap property after deletion.
4. Printing the current state of the heap array.

Reference: 
- Heap Data Structure (Max Heap) → https://www.geeksforgeeks.org/max-heap-in-java/
- Used in priority queues, scheduling algorithms, graph algorithms (like Dijkstra’s).

--------------------------------------------------------------------------------
Time and Space Complexity:
- Insert operation: O(log n)
    Each insertion may bubble up (percolate) along the tree height. 
    In a heap of size n, the height is O(log n).
- Delete (root removal): O(log n)
    Removing the root requires placing the last element at the root 
    and heapifying down, which may traverse the tree height.
- Heapify: O(log n)
    Ensures the heap property is maintained after changes.
- Print operation: O(n)
    Traverses all elements once.
- Space Complexity: O(n)
    The heap is stored as an array of size n.

--------------------------------------------------------------------------------
Step-by-Step Approach:
1. **Representation**: 
   - A heap is represented as an array. 
   - For any element at index `i`:
        Parent index = (i - 1) / 2
        Left child index = 2 * i + 1
        Right child index = 2 * i + 2

2. **Insertion (insert method)**:
   - Place the new element at the end of the array.
   - Compare it with its parent:
        If it is greater, swap it with the parent.
   - Repeat until the element is smaller than its parent 
     OR it becomes the root.
   - This process ensures the Max Heap property.

3. **Deletion (Delete method)**:
   - Remove the root element (maximum).
   - Replace the root with the last element in the heap.
   - Reduce heap size by 1.
   - Call `heapify(0)` to restore the Max Heap property.

4. **Heapify (heapify method)**:
   - Compare the node at `index` with its left and right children.
   - If either child is larger than the node:
        Swap the node with the larger child.
        Recursively call `heapify` on the affected child.
   - This ensures that the largest value bubbles down to its correct position.

5. **Print (print method)**:
   - Simply iterate through the array up to current size and print values.

--------------------------------------------------------------------------------
Visualization (Diagram):

Example: Inserting 12, 14, 4 into the heap.

Step 1: Insert 12
    Heap: [12]

            12

Step 2: Insert 14
    Heap array: [12, 14]
    Compare 14 with parent 12 → swap.
    Heap: [14, 12]

            14
           /
         12

Step 3: Insert 4
    Heap array: [14, 12, 4]
    Parent of 4 is 14 → no swap needed.
    Heap remains:

            14
           /  \
         12    4

This ensures the Max Heap property (parent ≥ children).

--------------------------------------------------------------------------------
Summary:
- This code builds a Max Heap supporting insertion, deletion, and printing.
- It uses array representation with parent-child index formulas.
- Critical operations rely on heapify to maintain heap structure.
- Complexity ensures efficient operations (O(log n) for insert/delete).
================================================================================
*/


// formula to find parent: (index - 1)/2
// formula to find child: 
// left child: 2*index + 1
// right child: 2*index + 2

class MaxHeap{
    int *arr;
    int size;
    int total_size;
    
    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value){
        if(size >= total_size){
            cout<<"Heap is overflow\n";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index > 0 && arr[(index - 1)/2] < arr[index]){
            swap(arr[(index - 1)/2], arr[index]);
            index = (index - 1)/2;
        }

        cout<<arr[index]<<" is inserted into heap\n";
    }

    void Delete(){
        if(size == 0){
            cout<<"Heap is underflow\n";
            return;
        }

        cout<<arr[0]<<" is deleted from heap\n";

        // delete the root node and swap it with the last child
        arr[0] = arr[size - 1];
        size--;

        // return if array is blank
        if(size == 0){
            return;
        }

        // now heapify the elements means place elements in correct order
        heapify(0);
    }

    void heapify(int index){
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // check that the child elements is bigger or not
        // if bigger then replace it with index
        if(left < size && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != index){
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    MaxHeap h1(6);
    h1.insert(12);
    h1.insert(14);
    h1.insert(4);
    h1.print();
    
}