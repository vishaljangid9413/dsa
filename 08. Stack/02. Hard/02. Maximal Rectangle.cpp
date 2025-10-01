#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Problem: Maximal Rectangle
// Link: https://leetcode.com/problems/maximal-rectangle/description/

// Question: 
// Given a 2D matrix containing '0' and '1', find the largest rectangle containing only '1' and return its area.

// Approach:
// This problem is a variation of the "Largest Rectangle in Histogram" problem. 
// The idea is to compute the maximum rectangular area for each row, considering it as a histogram where the heights of the bars 
// are computed for each column in the matrix. The largest rectangle can then be calculated in each histogram.
// We keep track of the heights of '1's in each column, and whenever we encounter a '0', we reset the height for that column.


// Time Complexity:
// For each row in the matrix, we calculate the maximal rectangle area using the "Largest Rectangle in Histogram" approach.
// The time complexity of the `Rectangle()` function is O(n), where n is the number of columns. 
// Since we iterate through each row, the overall time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix.

// Space Complexity:
// We use a vector `height[]` to store the height values for each column, which has a size of O(n), where n is the number of columns.
// The space complexity is O(n).


// Detailed Step-by-Step Approach:

// Step 1: Iterate through the matrix row by row.
// Step 2: For each row, update the `height[]` vector.
//         If the matrix element is '0', set the corresponding height to 0. 
//         If the matrix element is '1', increment the height for that column.
// Step 3: After updating the height array for the current row, call the function `Rectangle()` 
//         to calculate the maximal rectangle area for that row's histogram representation.
// Step 4: Keep track of the maximum area found across all rows.


// Function to calculate the maximum area of a rectangle in a histogram (array of heights).
int Rectange(vector<int> height) {
    int n = height.size();         // Get the number of columns.
    int max_area = 0;              // Variable to store the maximum area.
    int curr_index, nsl_index, nsr_index;   // Indices for the current, left, and right nearest smaller elements.
    stack<int> st;                 // Stack to store indices of histogram bars.

    // Step 1: Iterate through the histogram.
    for (int i = 0; i < n; i++) {
        // Step 2: Calculate the largest rectangle for the current height.
        while (!st.empty() && height[st.top()] > height[i]) {
            // Pop the top element from the stack
            curr_index = st.top();
            st.pop();
            nsr_index = i;   // Right nearest smaller index is the current index.

            // Check if there is a smaller element to the left of the popped element.
            if (!st.empty()) {
                nsl_index = st.top();  // Left nearest smaller index.
                // Calculate the area of rectangle with height of the popped element.
                max_area = max(max_area, height[curr_index] * (nsr_index - nsl_index - 1));
            } else {
                // If no smaller element to the left, use the entire width from the beginning to the current index.
                max_area = max(max_area, height[curr_index] * nsr_index);
            }
        }
        // Push the current index onto the stack.
        st.push(i);
    }

    // Step 3: After the loop, we need to handle any remaining bars in the stack.
    while (!st.empty()) {
        curr_index = st.top();
        st.pop();
        nsr_index = n; // Right nearest smaller index is the size of the histogram.

        // Check if there is a smaller element to the left.
        if (!st.empty()) {
            nsl_index = st.top();
            // Calculate the area of rectangle with height of the popped element.
            max_area = max(max_area, height[curr_index] * (nsr_index - nsl_index - 1));
        } else {
            // If no smaller element to the left, use the entire width.
            max_area = max(max_area, height[curr_index] * nsr_index);
        }
    }

    return max_area;  // Return the maximum area found.
}


int main() {
    // Step 1: Define the matrix (grid of 1s and 0s).
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    // Step 2: Initialize variables for matrix dimensions and the height array.
    int row = matrix.size();
    int col = matrix[0].size();
    int max_size = 0;             // Variable to store the maximum rectangle area.
    vector<int> height(col, 0);   // Height array to store the height for each column.

    // Step 3: Iterate over each row to calculate the height for each column.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // If the current element is '0', reset the height for that column.
            if (matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                // If the current element is '1', increment the height for that column.
                height[j]++;
            }
        }

        // Step 4: Call the Rectange function to find the maximal rectangle area for this row.
        max_size = max(max_size, Rectange(height));
    }

    // Step 5: Output the maximum rectangle area.
    cout << "Ans: " << max_size;
    return 0;
}

