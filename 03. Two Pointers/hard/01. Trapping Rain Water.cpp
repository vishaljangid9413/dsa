#include <iostream>
using namespace std;

// Problem: Calculate the amount of water that can be trapped between the bars after rainfall.
// The given array represents the heights of bars.

 /*
Time Complexity: O(n)
- The algorithm iterates through the array twice: once to find the highest bar and once to calculate the water trapped.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space for variables `lmax`, `rmax`, `ans`, `start`, `end`, and `index`.
*/

int main() {
    int arr[] = {4, 2, 0, 5, 2, 6, 2, 3}; // Input array representing heights of bars
    int n = size(arr); // Get the size of the array
    int start = 0, end = n - 1; // Initialize pointers to the start and end of the array
    int lmax = 0, rmax = 0; // Variables to store the maximum height from the left and right
    int index = 0; // To keep track of the index of the highest bar
    int ans = 0; // To accumulate the total amount of trapped water

    // Find the index of the highest bar
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[index]) {
            index = i; // Update the index if the current bar is higher
        }
    }

    // Two-pointer approach to calculate the water trapped
    while ((start < index) || (index < end)) {
        // Calculate trapped water on the left side of the highest bar
        if (start < index) {
            // If the current left max is greater than the height of the bar
            if (lmax > arr[start]) {
                ans += lmax - arr[start]; // Add the difference to the answer
            } else {
                lmax = arr[start]; // Update left max if current bar is taller
            }
            start++; // Move the left pointer to the right
        }

        // Calculate trapped water on the right side of the highest bar
        if (index < end) {
            // If the current right max is greater than the height of the bar
            if (rmax > arr[end]) {
                ans += rmax - arr[end]; // Add the difference to the answer
            } else {
                rmax = arr[end]; // Update right max if current bar is taller
            }
            end--; // Move the right pointer to the left
        }
    }
    
    // Output the total amount of trapped water
    cout << "Total Trapped Water: " << ans << endl; 
}
