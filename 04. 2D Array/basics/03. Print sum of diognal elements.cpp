#include <iostream>
using namespace std;

// first_digonal = 
//  *
//     *
//         *
//             *
// second_digonal=
//             *
//         *
//     *
// *

/*
This program calculates the sum of two diagonals in a 4x4 matrix:
1. The primary (first) diagonal runs from the top-left to the bottom-right.
2. The secondary (second) diagonal runs from the top-right to the bottom-left.
*/

int main() {
    // Initialize a 4x4 matrix (2D array) with some values
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int row = 4, col = 4; // Define the dimensions of the matrix
    int first_diagonal = 0, second_diagonal = 0; // Variables to store the sums of the diagonals

    // Calculate the sum of both diagonals
    for (int i = 0; i < row; i++) {
        first_diagonal += arr[i][i];          // Sum of elements on the primary diagonal
        second_diagonal += arr[i][col - i - 1]; // Sum of elements on the secondary diagonal
    }

    // Output the results
    cout << "Sum of the first diagonal: " << first_diagonal << endl;
    cout << "Sum of the second diagonal: " << second_diagonal << endl;

    return 0; // End of the program
}
