#include <iostream>
using namespace std;

/*
Problem: Given an array, check if there are three elements that add up to a specific target value `x`.

Time Complexity: O(n^2)
- The code involves a nested loop structure where the outer loop runs O(n) times and the inner loop (which uses the two-pointer technique) runs O(n) times.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space for variables, regardless of the input size.
*/

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8}; // Input array
    int n = size(arr); // Get the size of the array
    int x = 13; // Target sum we are looking for

    // Sort the array using bubble sort (inefficient for large arrays)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap if elements are in the wrong order
            }
        }
    }

    // Check for three elements that add up to `x`
    for (int i = 0; i < n - 2; i++) {
        int start = i + 1, end = n - 1; // Set pointers for the two-pointer technique
        int temp = x - arr[i]; // Calculate the remaining sum needed

        while (start < end) {
            if (arr[start] + arr[end] == temp) { // Check if the two elements sum up to the remaining
                cout << "True" << endl; // Found a triplet
                return 0; // Exit the program
            } else if (arr[start] + arr[end] < temp) {
                start++; // Move the left pointer to the right to increase the sum
            } else {
                end--; // Move the right pointer to the left to decrease the sum
            }
        }
    }
    
    cout << "Fail"; // No triplet found
    return 0;
}
