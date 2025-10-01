#include <iostream>
using namespace std;

// Problem: Find the maximum difference between two elements in the array 
// where the smaller element appears before the larger one (i.e., arr[i] can only be subtracted from arr[j] for j > i).

/*
Time Complexity: O(n)
- The algorithm makes a single pass through the array from right to left, calculating the maximum element in the suffix and the maximum difference.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space (for variables `maxi`, `suffix`, and the loop variable `i`).
*/

int main()
{
    int arr[] = {9, 5, 8, 12, 2, 3, 7, 4}; // Input array
    int n = size(arr); // Get the size of the array

    int maxi = INT_MIN; // To store the maximum difference encountered so far
    int suffix = 0;     // To store the maximum element in the suffix (i.e., the right part of the array)

    // Iterate through the array from the second last element to the first element
    for(int i = n - 2; i >= 0; i--) {
        suffix = max(suffix, arr[i + 1]);  // Update the suffix with the maximum element to the right of arr[i]
        maxi = max(suffix - arr[i], maxi); // Calculate the difference and update maxi if this difference is larger
    }

    // Output the maximum difference
    cout << "Maximum Difference: " << maxi << endl; 
}
