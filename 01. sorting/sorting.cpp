#include <iostream>
#include<vector>
using namespace std;

/*
Problem: Sorting an array using different sorting algorithms.
Points to remember:
1. Each algorithm has different time and space complexities.
2. Selection, Bubble, and Insertion Sort are comparison-based, with O(n^2) time complexity.
3. Merge Sort and Quick Sort are more efficient with average time complexity of O(nlogn).
*/

// Selection Sort
// Algorithm: Selection Sort
// Time Complexity: O(n^2) - Two nested loops, one for selecting, one for finding the minimum.
// Space Complexity: O(1) - In-place sorting.
void selection_sort(int arr[], int n){
    // In selection sort, we always look for the smallest element in the unsorted part
    // and then swap it with the current element.
    for (int i=0; i<n-1; i++){
        int index = i; // Assume the current index is the smallest
        for (int j=i+1; j<n; j++){
            if(arr[j] < arr[index]){
                index = j; // Update if a smaller element is found
            }
        }
        if(index != i){
            swap(arr[i], arr[index]); // Swap the smallest element with the current element
        }
    }
}


// Bubble Sort
// Algorithm: Bubble Sort
// Time Complexity: O(n^2) - Worst case, O(n) if array is already sorted (best case).
// Space Complexity: O(1) - In-place sorting.
void bubble_sort(int arr[], int n){
    // In bubble sort, we check if the current element is greater than the next one.
    // If it is, we swap them, and the largest element bubbles to the end of the array.
    for (int i=0; i<n-1; i++){
        int swapped = 0; // To optimize and stop early if the array is sorted
        for(int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); // Swap adjacent elements
                swapped = 1; // Mark that a swap occurred
            }
        }
        if(swapped == 0){
            break; // No swaps means the array is already sorted
        }
    }
}


// Insertion Sort
// Algorithm: Insertion Sort
// Time Complexity: O(n^2) - In worst case, each element is compared to all previous elements.
// Space Complexity: O(1) - In-place sorting.
void insertion_sort(int arr[], int n){
    // In insertion sort, we assume the first part of the array is sorted
    // and insert each subsequent element into its correct position.
    for (int i=1; i<n; i++){
        for(int j = i; j > 0; j--){
            if (arr[j-1] > arr[j]){
                swap(arr[j-1], arr[j]); // Move elements greater than the current element
            } else {
                break; // Exit when elements are in order
            }
        }
    }
}


// Merge Function for Merge Sort
// Algorithm: Merge Sort (Helper function)
// Time Complexity: O(n) for merging two sorted subarrays.
// Space Complexity: O(n) - Temporary array is used for merging.
void merge(int arr[], int start, int mid, int end){
    // Helper function to merge two sorted subarrays: arr[start..mid] and arr[mid+1..end].
    vector<int> temp(end-start+1, 0); // Temporary array to hold merged result
    int left = start, right = mid + 1, index = 0;

    // Merging both halves
    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index++] = arr[left++]; // Take element from left half
        }else{
            temp[index++] = arr[right++]; // Take element from right half
        }
    }

    // Copy any remaining elements from the left half
    while(left <= mid){
        temp[index++] = arr[left++];
    }

    // Copy any remaining elements from the right half
    while(right <= end){
        temp[index++] = arr[right++];
    }

    // Copy the sorted array back to the original array
    index = 0;
    while(start <= end){
        arr[start++] = temp[index++];
    }
}


// Merge Sort
// Algorithm: Merge Sort
// Time Complexity: O(nlogn) - Recursively dividing the array into halves.
// Space Complexity: O(n) - Due to recursion and temporary storage during merging.
void merge_sort(int arr[], int start, int end){
    // Merge sort works by dividing the array into two halves, sorting each half, and then merging them.
    if(start == end) return; // Base case: single element

    int mid = start + (end-start)/2;

    // Recursively sort both halves
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
}


// Partition Function for Quick Sort
// Algorithm: Quick Sort (Helper function)
// Time Complexity: O(n) - for partitioning the array.
// Space Complexity: O(1)
int partition(int arr[], int start, int end){
    // Partition the array and return the pivot index.
    int position = start;
    while(start <= end){
        if(arr[start] <= arr[end]){
            swap(arr[start], arr[position++]); // Swap elements smaller than the pivot
        }
        start++;
    }
    return position - 1; // Return the final pivot position
}


// Quick Sort
// Algorithm: Quick Sort
// Time Complexity: O(nlogn) - Average case, O(n^2) in worst case (already sorted/reversed array).
// Space Complexity: O(logn) - Recursion stack.
void quick_sort(int arr[], int start, int end){
    // Quick sort picks a pivot element and partitions the array into elements
    // smaller than the pivot and elements larger than the pivot.
    if(start >= end){
        return;
    }

    int pivot = partition(arr, start, end);

    // Recursively sort the left and right partitions
    quick_sort(arr, start, pivot-1);
    quick_sort(arr, pivot, end);
}


int main(){
    int arr[] = {9, 7, 3, 1, 6}; // Test array
    int n = size(arr); // Size of the array

    // Uncomment one sorting algorithm at a time for testing
    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // merge_sort(arr, 0, n-1);
    // quick_sort(arr, 0, n-1);

    // Output the sorted array
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}
