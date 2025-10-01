#include <iostream>
using namespace std;

/*
Problem: Given an array, find all unique quadruplets (four elements) that sum up to a specific target value `x`.

Time Complexity: O(n^3)
- The code includes a nested loop structure, where the outer two loops run O(n²) and the inner loop (which uses the two-pointer technique) runs O(n).

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space for variables, regardless of the input size.
*/

int main() {
    int arr[] = {1, 5, 1, 0, 6, 0}; // Input array
    int n = size(arr); // Get the size of the array
    int x = 7; // Target sum we are looking for

    // Sorting the array using selection sort
    for (int i = 0; i < n - 1; i++) {
        int index = i; // Initialize the index of the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[index]) {
                index = j; // Update the index if a smaller element is found
            }
        }
        if (index != i) {
            swap(arr[i], arr[index]); // Swap to place the minimum element in the correct position
        }
    }

    // Finding quadruplets that sum to `x`
    for (int i = 0; i < n - 3; i++) { // First element of the quadruplet
        for (int j = i + 1; j < n - 2; j++) { // Second element of the quadruplet
            int temp = x - arr[i] - arr[j]; // Remaining sum needed
            int start = j + 1, end = n - 1; // Initialize two pointers for the remaining elements

            while (start < end) {
                if (arr[start] + arr[end] == temp) { // Check if the sum of the two pointers equals the remaining sum
                    cout << arr[start] << " " << arr[end] << " " << arr[i] << " " << arr[j] << endl; // Print the quadruplet
                    break; // Exit the loop after finding a match
                } else if (arr[start] + arr[end] < temp) {
                    start++; // Move the start pointer to the right to increase the sum
                } else {
                    end--; // Move the end pointer to the left to decrease the sum
                }
            }
        }
    }

    return 0; // End of program
}
