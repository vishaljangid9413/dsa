#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Find the minimum eating speed (represented by `mid`) to eat all the bananas within `k` hours.
- Each pile of bananas is eaten at a rate of `mid` bananas per hour, and any remaining bananas after one hour are counted as a new pile for the next hour.

Time Complexity: O(n log m)
- Sorting the array takes O(n log n).
- The binary search for the optimal speed `mid` runs in O(log m), where `m` is the sum of all bananas divided by the number of hours.
- For each `mid`, the check if it is possible takes O(n), where `n` is the number of piles.
- Hence, the overall complexity is O(n log m).

Space Complexity: O(1)
- Only a constant amount of extra space is used for variables.

Approach:
1. **Sorting the Piles**:
   - Sort the array to make sure we can efficiently work with the largest pile when calculating speeds.

2. **Binary Search**:
   - The range for the eating speed (`mid`) is from `1` (smallest possible speed) to the largest pile in the array (`arr[n-1]`).
   - Use binary search to find the minimum eating speed that allows all the bananas to be eaten in `k` hours.

3. **Feasibility Check (`possible` function)**:
   - For each `mid`, calculate how many hours it will take to eat all the bananas. If the total number of hours is less than or equal to `k`, it means that the speed is feasible.
   - The calculation is done by determining how many hours each pile will take at the current speed and summing them up.

4. **Edge Cases**:
   - If there are fewer bananas than hours (`k > n`), it's possible to finish within `k` hours with minimal speed.

*/

bool possible(int arr[], int n, int mid, int k){
    int total = 0;
    // Calculate the total hours needed to eat all bananas at speed `mid`
    for(int i = 0; i < n; i++){
        // (arr[i] + mid - 1) / mid is used to compute the number of full hours needed to eat each pile
        // its working like ciel,
        // means if devision have remainder then total will +1
        total += (arr[i] + mid - 1) / mid;
    }
    // Return true if the total time is less than or equal to `k`
    return total <= k;
}

int main(){
    int arr[] = {30, 11, 23, 4, 20}; // Pile sizes
    int n = size(arr); // Number of piles
    int hour = 5; // Total hours available to eat the bananas

    // Step 1: Sort the array (You can skip this since it’s unnecessary for the logic, but sorting is fine for other applications)
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Step 2: Define search space
    // The minimum possible speed is the total number of bananas divided by the total hours (for optimization)
    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    int start = sum / hour; // Lower bound for speed
    int end = arr[n-1]; // Upper bound for speed (the largest pile)
    
    // If start is 0, set it to 1 to avoid division by zero
    if (!start) start = 1;

    int ans = -1; // Variable to store the result (minimum speed)

    // Step 3: Binary search for the minimum possible speed
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (possible(arr, n, mid, hour)){
            ans = mid; // Mid is a possible answer, try smaller speeds
            end = mid - 1;
        } else {
            start = mid + 1; // Mid is too small, try larger speeds
        }
    }

    // Output the minimum speed required to eat all bananas in `hour` hours
    cout << ans;
}
