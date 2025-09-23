#include <iostream>
using namespace std;

int main() {
    /*
    Problem: Find the largest integer whose square is less than or equal to x (Find floor(sqrt(x)))
    
    Time Complexity: O(log x)
    - The algorithm uses binary search, which halves the search space each time, resulting in a logarithmic time complexity.

    Space Complexity: O(1)
    - The algorithm uses a constant amount of space for the variables, regardless of the input size.
    */
    
    int x = 8; // Input number for which we want to find the square root
    int start = 0, end = x, ans = 0, mid; // Initializing start, end, and ans for binary search

    // Edge case: If x is less than 2, return x as its square root is itself
    if (x < 2) {
        return x; // Return the input number directly if it's less than 2
    }

    // Binary Search Algorithm
    while (start <= end) { // Continue searching while start is less than or equal to end
        mid = start + (end - start) / 2; // Calculate mid to avoid overflow

        // Check if mid is the perfect square root of x
        if (mid == x / mid) { // If mid * mid == x
            ans = mid; // Store the result
            break; // Exit the loop as we found the answer
        }
        // If mid^2 < x, move to the right half
        else if (mid < x / mid) { // If mid is less than the square root of x
            ans = mid; // Update ans to mid, as it's a candidate
            start = mid + 1; // Search in the right half (mid + 1 to end)
        }
        // If mid^2 > x, move to the left half
        else {
            end = mid - 1; // Search in the left half (start to mid - 1)
        }
    }
    
    // Output the final answer
    cout << ans; // Print the floor of the square root of x

    return 0; // End of the program
}
