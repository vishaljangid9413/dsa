#include <iostream>
using namespace std;

// Time Complexity: O(n) for both approaches.
// Space Complexity: O(n) for the first approach, O(1) for the second approach (using the same array).

// In this problem, we are given an array of size n that contains elements 
// in the range (1 to n) with exactly one duplicate and one missing element. 

void first_approach(int arr[], int n) {
    // Create a new array to count occurrences of each number.
    int new_arr[7] = {0}; // Size should be n for general use.

    // Count occurrences of each element in the input array.
    for (int i = 0; i < n; i++) {
        new_arr[arr[i] - 1]++;
    }

    // Identify the duplicate and missing elements.
    for (int i = 0; i < n; i++) {
        if (new_arr[i] == 2) {
            cout << "Duplicate: " << i + 1 << endl; // Found duplicate.
        } else if (new_arr[i] == 0) {
            cout << "Missing: " << i + 1 << endl; // Found missing.
        }
    }
}

void second_aproach(int arr[], int n) {
    // First we should decrease each element by 1 to fit them within index range.
    for (int i = 0; i < n; i++) {
        arr[i]--; // Decrement each element.
    }

    // Now we have to give the occurrence count of each element.
    for (int i = 0; i < n; i++) {
        int value = arr[i] % n; // Get the adjusted value for indexing.
        arr[value] += n; // Increment the position by n to track occurrence.

        // The approach ensures we use the index to store occurrence
        // This avoids complications with the duplicate element.
    }

    // Identify the duplicate and missing elements from the modified array.
    for (int i = 0; i < n; i++) {
        int occurrence = arr[i] / n; // Get the occurrence count.
        if (occurrence == 2) {
            cout << "Duplicate: " << i + 1 << endl; // Found duplicate.
        } else if (occurrence == 0) {
            cout << "Missing: " << i + 1 << endl; // Found missing.
        }
    }
}

int main() {
    int arr[] = {4, 3, 2, 1, 2, 7, 6}; // Example input array.
    int n = 7; // Size of the array.

    // Call both approaches to find the duplicate and missing elements.
    first_approach(arr, n);
    second_aproach(arr, n);    
}
