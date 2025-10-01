#include <iostream>
#include <vector>
using namespace std;

// IN this questions we have to print a 2d array in the spiral like 
// structure ex:
// > > > > > >
// ^ > > > > V
// ^ ^ < < V V
// ^ < < < V V
// < < < < < V
// Consider the arrows as elements of an 2d array 

// Problem: Print the elements of a 2D array in a spiral order.
// Approach: Use four pointers (top, bottom, left, right) to track the boundaries of the spiral.
// We will iterate in the order: left to right, top to bottom, right to left, and bottom to top,
// adjusting the boundaries after each complete iteration until all elements are traversed.

// Time Complexity: O(n), where n is the total number of elements in the matrix.
// Space Complexity: O(n) for storing the spiral order in the output vector.

int main(){
    int arr[5][5] ={1,2,3,4,5, 
                    6,7,8,9,10, 
                    11,12,13,14,15, 
                    16,17,18,19,20, 
                    21,22,23,24,25};
    int top = 0, bottom = 4; // Represent row indices
    int left = 0, right = 4; // Represent column indices
    vector<int> ans; // Vector to store the spiral order

    while(top <= bottom && left <= right) {
        // For left to right iteration
        for (int i = left; i <= right; i++) {
            ans.push_back(arr[top][i]);
        }
        top++; // Move the top boundary down

        // For top to bottom iteration
        for(int i = top; i <= bottom; i++) {
            ans.push_back(arr[i][right]);
        }
        right--; // Move the right boundary left

        // For right to left iteration
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                ans.push_back(arr[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        // For bottom to top iteration
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                ans.push_back(arr[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    // Print the elements in spiral order
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
