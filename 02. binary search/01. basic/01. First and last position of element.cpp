#include <iostream>
using namespace std;

/*
Problem: Finding the first and last positions of a target element in a sorted array.
Approach:
1. This problem can be solved using binary search to find both positions.
2. `first_position` finds the first occurrence of the target.
3. `second_position` finds the last occurrence of the target.
Points to remember:
1. Binary search is used to optimize the search process with O(log n) time complexity.
2. Both functions return -1 if the target is not found.
*/

// Function to find the first occurrence of the target
// Algorithm: Binary Search
// Time Complexity: O(log n) - Logarithmic time due to binary search.
// Space Complexity: O(1) - No extra space used.
int first_position(int arr[], int n, int target){
    int start = 0, end = n-1, mid, ans = -1;
    
    // Binary search to find the first occurrence of the target
    while (start <= end){
        mid = start + (end - start)/2;
        if (arr[mid] == target){
            ans = mid;  // If the target is found, store its index
            end = mid - 1;  // Continue searching in the left half to find the first occurrence
        } else if(arr[mid] > target){
            end = mid - 1;  // Target lies in the left half
        } else {
            start = mid + 1;  // Target lies in the right half
        }
    }
    return ans;  // Return the first occurrence or -1 if not found
}


// Function to find the last occurrence of the target
// Algorithm: Binary Search
// Time Complexity: O(log n) - Logarithmic time due to binary search.
// Space Complexity: O(1) - No extra space used.
int second_position(int arr[], int n, int target){
    int start = 0, end = n-1, mid, ans = -1;
    
    // Binary search to find the last occurrence of the target
    while (start <= end){
        mid = start + (end - start)/2;
        if (arr[mid] == target){
            ans = mid;  // If the target is found, store its index
            start = mid + 1;  // Continue searching in the right half to find the last occurrence
        } else if(arr[mid] < target){
            start = mid + 1;  // Target lies in the right half
        } else {
            end = mid - 1;  // Target lies in the left half
        }
    }
    return ans;  // Return the last occurrence or -1 if not found
}

int main(){
    int arr[] = {5, 7, 7, 8, 8, 10};  // Sorted array
    int n = size(arr), target = 7;  // Target element to search for
    int ans[2] = {0};

    // Finding the first and last positions of the target
    ans[0] = first_position(arr, n, target);
    ans[1] = second_position(arr, n, target);

    // Output the first and last positions of the target
    for (int i = 0; i < 2; i++){
        cout << ans[i] << " ";  // Output the result
    }
}
