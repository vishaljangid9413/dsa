#include <iostream>
using namespace std;

// Problem: Rotate a square matrix 90 degrees clockwise a specified number of times.
// Each rotation corresponds to a 90-degree clockwise turn.
// If the input k = 3, it means the matrix should be rotated 3 times (270 degrees).

int main() {
    // Initialize a 4x4 2D array (matrix) with values from 1 to 16.
    int arr[4][4] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        13, 14, 15, 16
    };
    
    int row = 4, col = 4; // Define the number of rows and columns.
    int k = 8; // Number of rotations to perform.
    int rotate = k % 4; // Calculate effective rotations needed (since rotating 4 times results in the same matrix).

    // Perform the rotation 'rotate' times.
    while (rotate) {
        // Step 1: Transpose the matrix.
        for (int i = 0; i < row; i++) {
            for (int j = i + 1; j < col; j++) {
                swap(arr[i][j], arr[j][i]); // Swap elements across the diagonal.
            }
        }
        
        // Step 2: Reverse each row of the transposed matrix.
        for (int i = 0; i < col; i++) {
            int start = 0, end = row - 1; // Define the start and end indices for the row.
            // Reverse the row by swapping elements from start to end.
            while (start < end) {
                swap(arr[i][start], arr[i][end]);
                start++; 
                end--;
            }
        }
        
        rotate--; // Decrease the number of remaining rotations.
    }

    // Print the rotated matrix.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Print each element followed by a space.
        }
        cout << endl; // Move to the next line after printing each row.
    }

    return 0; // Indicate successful completion of the program.
}
