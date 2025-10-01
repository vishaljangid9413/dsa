#include <iostream>
using namespace std;

// Problem: Given an array where each element is in the range [1, n], where n is the size of the array,
// we need to find the frequency of each element in the array. The elements may include duplicates.
// This approach leverages the fact that the values are within a specific range, allowing us to modify the input array
// to keep track of counts without using additional space.
// 
// Approach: 
// 1. Decrease each element by 1 to handle zero-based indexing.
// 2. Use the modulus operator to find the appropriate index to increment the count of occurrences.
// 3. After processing, calculate the occurrences by dividing the values in the array by n.
// 
// Time Complexity: O(n), as we are making a constant number of passes through the array.
// Space Complexity: O(1), as we are using the input array itself to store the counts.

int main() {
    int arr[] = {3, 2, 5, 3, 1, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);  // Determine the size of the array

    // Decrease elements by 1 to adjust for zero-based indexing
    for (int i = 0; i < n; i++) {
        arr[i]--;
    }

    // Increment the count for each element
    for (int i = 0; i < n; i++) {
        int element = arr[i] % n;  // Get the original value (after decrement)
        arr[element] += n;  // Increment the count of that element
    }

    // Output the occurrences of each element
    for (int i = 0; i < n; i++) {
        int element = arr[i] % n;  // Get the original value (after decrement)
        int occurrence = arr[element] / n;  // Calculate the frequency of that element
        cout << "Occurrence: " << element + 1 << " " << occurrence << endl;  // Print the result
    }

    return 0;
}
