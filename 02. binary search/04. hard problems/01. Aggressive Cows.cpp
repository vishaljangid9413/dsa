#include <iostream>
using namespace std;

/*
Problem: Place `k` cows in `n` stalls such that the minimum distance between any two cows is maximized.
- We need to find the largest minimum distance that can be maintained between any two cows in the given stalls.

Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
Time Complexity: O(n log d)
- Sorting the array takes O(n log n).
- The binary search for the optimal distance runs in O(log d), where `d` is the difference between the maximum and minimum stall positions.
- For each `mid` in binary search, checking feasibility takes O(n). So, overall complexity is O(n log d).

Space Complexity: O(1)
- Only a constant amount of extra space is used for variables.

Approach:
1. **Sorting the Stalls**:
   - First, we sort the stall positions to facilitate binary search on the distance between cows.
   
2. **Binary Search**:
   - The range of distances (possible answers) is from `1` (smallest possible distance between two cows) to the distance between the farthest stalls (`arr[n-1] - arr[0]`).
   - Use binary search to maximize the minimum distance between cows.

3. **Feasibility Check (`is_possible` function)**:
   - For each mid value (representing a candidate minimum distance), we try to place the cows in the stalls such that the distance between any two cows is at least `mid`.
   - Start by placing the first cow at the first stall, and then place each subsequent cow in the next stall that is at least `mid` units away from the last placed cow.
   - If all `k` cows can be placed with this minimum distance, the placement is possible.

4. **Edge Case**:
   - If there are fewer stalls than cows (`n < k`), it would be impossible to place all cows, but this is not checked in the current setup.
*/

bool is_possible(int arr[], int mid, int n, int k) {
    // Start by placing the first cow in the first stall
    int cows = 1; // One cow placed
    int position_of_cow = arr[0]; // Position of the last placed cow

    // Try to place the rest of the cows
    for (int i = 1; i < n; i++) {
        // Check if the current stall is at least `mid` distance away from the last placed cow
        if (arr[i] - position_of_cow >= mid) {
            position_of_cow = arr[i]; // Place the cow at the current stall
            cows++; // Increase the cow count

            // If all cows are placed, return true
            if (cows == k) {
                return true;
            }
        }
    }
    // If unable to place all cows with this distance, return false
    return false;
}

int main() {
    int arr[] = {10, 1, 2, 7, 5}; // Example stall positions (unsorted)
    int n = size(arr); // Number of stalls
    int ans = 0, mid, k = 3;

    if(n < k){
        return -1;
    }

    // Step 1: Sort the stall positions
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
    // Step 2: Binary Search to find the maximum minimum distance
    int start = 1, end = arr[n-1] - arr[0]; 

    while (start <= end) {
        mid = start + (end - start) / 2; // Calculate mid distance
        bool possible = is_possible(arr, mid, n, k); // Check if placing cows is possible with this mid

        if (possible) {
            ans = mid; // If possible, this distance could be the answer
            start = mid + 1; // Try for a larger minimum distance
        } else {
            end = mid - 1; // Try for a smaller minimum distance
        }
    }

    // Output the largest minimum distance
    cout << ans;

    return 0;
}
