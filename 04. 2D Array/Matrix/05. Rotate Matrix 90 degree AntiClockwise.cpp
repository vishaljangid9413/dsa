#include <iostream>
using namespace std;

/*
Problem: Rotate a square matrix (2D array) by 90 degrees counterclockwise.
Approach:
1. First, we need to transpose the matrix, which means converting all rows to columns.
2. Then, we reverse each column to achieve the counterclockwise rotation.

Time Complexity: O(n^2) - Since we are traversing each element of the matrix.
Space Complexity: O(1) - We are performing the operations in-place without using any extra space.
*/

int main() {
    // Initialize a 4x4 matrix
    int arr[4][4] = {1, 2, 3, 4, 
                     5, 6, 7, 8, 
                     9, 10, 11, 12, 
                     13, 14, 15, 16};
    int row = 4, col = 4;

    // Step 1: Transpose the matrix
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < col; j++) {
            // Swap the elements to transpose the matrix
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    int start= 0,end=row-1;
    while(start<end){
        for(int i=0;i<row;i++){
            swap(arr[start][i],arr[end][i]);
        }
        start++;end--;
    }
    
    // Print the rotated matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Print each element of the matrix
        }
        cout << endl; // New line for each row
    }
}
