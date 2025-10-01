#include <iostream>
using namespace std;

/*
Problem: Find the index in an array where the sum of elements on the left side equals the sum of elements on the right side. 
         The problem is a variation of finding the equilibrium index where the cumulative sum on both sides of the index is equal.

Time Complexity: O(n)
- The first loop computes the total sum of the array in O(n) time.
- The second loop iterates over the array elements once, calculating the left-side sum and comparing it with the right-side sum.
- Thus, the overall complexity is linear, O(n).

Space Complexity: O(1)
- The algorithm uses only a constant amount of extra space (`sum`, `lsum`, and the loop control variable `i`).

Approach:
1. **First Step**: Calculate the total sum of all the elements in the array (`sum`).
2. **Second Step**: Use a second loop to calculate the left cumulative sum (`lsum`) while iterating through the array.
   - For each element, check if the left sum equals the right sum. The right sum can be derived as `sum - lsum`.
   - If `lsum` equals `sum - lsum`, then print the result.
   
3. **Edge Cases**:
   - Single-element arrays will not have an equilibrium index.
   - Arrays with only negative numbers might still have an equilibrium index based on the sum.

*/

int main()
{
    int arr[] = {3, 4, -2, 5, 8, 20, -10, 8}; // Input array
    int n = size(arr); // Get the size of the array
    int sum = 0, lsum = 0;

    // Calculate the total sum of the array
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Iterate through the array to find where the left sum equals the right sum
    for(int i = 0; i < n - 1; i++) {
        lsum += arr[i]; // Cumulative sum on the left side
        if(sum - lsum == lsum) { // Check if left sum equals right sum
            cout << "Ans: " << lsum << " at element " << arr[i] << endl;
        }
    }

}
