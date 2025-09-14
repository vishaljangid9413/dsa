#include <iostream>
using namespace std;

/*
================================================================================
Problem: Merge K Sorted Arrays
--------------------------------------------------------------------------------
Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

We are given `k` sorted arrays (each of size `k` in this case), and the task is 
to merge them into a single sorted array. 

This problem is common in competitive programming and interviews because it 
tests knowledge of heaps, divide-and-conquer (merge sort), and efficient 
time/space trade-offs.

================================================================================
Approaches Implemented:
1. **Min Heap with Pairs**
   - Uses a priority queue (min-heap) to repeatedly extract the smallest element 
     from the heads of all arrays and push the next element from that array.
   - Efficient for continuous merging as the heap ensures smallest element access 
     in `O(log k)`.

2. **Modified Merge Sort**
   - Concatenates all arrays into one big array, then performs a custom merge 
     sort where partitioning is done by "array groups" (not simply by index).
   - Works by recursively merging portions until the full array is sorted.

================================================================================
Time & Space Complexity Analysis:
1. **Min Heap Method**
   - Time: `O(N log k)` 
       - N = total number of elements (`k*k` here).
       - Each insertion/removal from heap costs `O(log k)`.
   - Space: `O(k)` for the heap.

2. **Merge Sort Method**
   - Time: `O(N log k)` 
       - Each merge step processes all elements, with log k levels of merging.
   - Space: `O(N)` for temporary arrays during merging.

================================================================================
Step-by-Step Approach:
--------------------------------------
### Method 1: Min Heap with Pairs
1. Initialize a priority queue with the first element of each sorted array, 
   along with its `(array_index, element_index)`.
2. Repeatedly extract the smallest element from the heap and append it to the 
   final result.
3. When an element is extracted, insert the **next element** from the same array 
   into the heap.
4. Continue until the heap is empty.

--------------------------------------
### Method 2: Modified Merge Sort
1. Flatten all k arrays into one single array.
2. Perform a recursive merge sort:
   - Instead of dividing exactly in half, split the array into "portions" based 
     on how many sorted arrays are grouped together.
   - Recursively sort left and right portions.
   - Merge them back together.

================================================================================
Visualization:
--------------------------------------
Suppose we have k = 3 arrays:
arr = [[1, 4, 7], [2, 5, 8], [3, 6, 9]]

### Method 1 (Heap):
Heap initially:
    [(1,0,0), (2,1,0), (3,2,0)]
          |
          v
Extract 1 → Push next from array0 → Heap = [(2,1,0), (3,2,0), (4,0,1)]
Extract 2 → Push next from array1 → Heap = [(3,2,0), (4,0,1), (5,1,1)]
Extract 3 → Push next from array2 → Heap = [(4,0,1), (5,1,1), (6,2,1)]
...
Final sorted array: [1,2,3,4,5,6,7,8,9]

### Method 2 (Merge Sort):
Flatten: [1,4,7,2,5,8,3,6,9]

Divide into portions:
    Left: [1,4,7]   Right: [2,5,8,3,6,9]
        Left: [2,5,8]   Right: [3,6,9]
        Merge -> [2,3,5,6,8,9]
Merge final: [1,2,3,4,5,6,7,8,9]

================================================================================
Why Both Approaches Matter:
- Heap method is **optimal for streaming scenarios** where arrays arrive one by 
  one or when data is too large to hold entirely in memory.
- Merge sort method is **better for in-memory bulk sorting** when we can afford 
  extra space and want to use divide-and-conquer.

================================================================================
Best Practice:
- In interviews or large-scale systems, prefer **min-heap method** for clarity 
  and efficiency.
- Always analyze **time and space trade-offs** based on input constraints.
================================================================================
*/


// mean heap with pairs
vector<int> first_method(vector<vector<int>> &arr, int k){
    
    // define the pair type
    using PairType = pair<int, pair<int, int>>;

    // intialse a vector with first elements of each array 
    vector<PairType>temp;
    for(int i=0;i<arr.size();i++){
        temp.push_back(
            make_pair(arr[i][0], make_pair(i, 0))
        );
    }

    // now fill priorty queue with temp vector because it takes only O(k) time 
    priority_queue<PairType, vector<PairType>, greater<PairType>>p(temp.begin(), temp.end());

    // declare an element 
    PairType element;
    int i, j;
    vector<int>ans;

    while(!p.empty()){
        element = p.top(); p.pop();
        ans.push_back(element.first);
        i = element.second.first;
        j = element.second.second;

        if(j + 1 < k){
            p.push(make_pair(arr[i][j+1], make_pair(i, j+1)));
        }
    }

    return ans;
}


void merge(vector<int> &arr, int start, int mid, int end){
    // create a temp array to store the new sorted array 
    vector<int>temp(end - start + 1, 0);
    int left = start, right = mid + 1, index = 0;
    
    // iterate through the array using left and right index 
    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index] = arr[left];
            index++, left++;
        }else{
            temp[index] = arr[right];
            index++, right++;
        }
    }

    // iterate through remaining portion of array either left or right
    while(left <= mid){
        temp[index] = arr[left];
        index++, left++;
    }

    while(right <= end){
        temp[index] = arr[right];
        index++, right++;
    }

    // Copy the sorted array back to the original array
    index = 0;
    while(start <= end){
        arr[start] = temp[index];
        start++, index++;
    }
}

void mergesort(vector<int> &arr, int start, int end, int portion, int k){
    // return if only single portion remains
    // because the portion is already sorted so we do not need to break it more 
    if(portion < 2){
        return;
    }

    // modified the method to find mid 
    // because we have to find mid according to size of portion
    // we can't simply devide the array between the half
    int mid = start + (portion / 2) * k - 1;

    // go to left part 
    int left_portion = portion / 2;
    mergesort(arr, start, mid, left_portion, k);

    // go to right part
    // remaining portion go to right part
    int right_portion = portion - portion / 2;
    mergesort(arr, mid + 1, end, right_portion, k);

    // merge the array 
    merge(arr, start, mid, end);
}

// using merge sort 
vector<int> second_method(vector<vector<int>> &arr, int k){
    // first merge them in single array 
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            ans.push_back(arr[i][j]);
        }
    }

    mergesort(ans, 0, ans.size(), k, k);
    return ans;
}


int main(){
    vector<vector<int>> arr = {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    int k = 4;

    vector<int> ans;
    // ans = first_method(arr, k);
    ans = second_method(arr, k);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}