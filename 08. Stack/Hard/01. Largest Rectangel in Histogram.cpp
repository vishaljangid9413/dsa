#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Largest rectangle in histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Question:
// Given an array of heights representing a histogram where the width of each bar is 1, 
// find the area of the largest rectangle that can be formed within the histogram.

// The problem requires finding the largest area of a rectangle that can fit under the histogram's bars.

// Time complexity and space complexity for each method are provided after each explanation.


// First method (consists of 3 loops)

// Approach:
// 1. We start by calculating two arrays: nsl (Next Smaller Left) and nsr (Next Smaller Right) for each element.
// 2. nsl[i] stores the index of the next smaller element to the left of arr[i].
// 3. nsr[i] stores the index of the next smaller element to the right of arr[i].
// 4. Once we have nsl and nsr for all elements, we can calculate the area for each element using the formula:
//    Area = arr[i] * (nsr[i] - nsl[i] - 1)
// 5. Finally, we return the maximum of all areas.

// Time Complexity: O(n) - We traverse each element at most twice.
// Space Complexity: O(n) - We use two extra arrays, nsl and nsr, each of size n.

int first_method(int arr[], int n){

    vector<int>nsl(n, -1);  // Array to store Next Smaller Left (initialized to -1)
    vector<int>nsr(n, n);    // Array to store Next Smaller Right (initialized to n)
    stack<int>st;  // Stack to store indices of elements

    // Step 1: Calculate nsl (Next Smaller Left)
    for(int i = n-1; i >= 0; i--){
        // While there are elements in the stack and the current element is smaller than the top element of the stack
        while(!st.empty() && arr[st.top()] > arr[i]){
            nsl[st.top()] = i;  // Set nsl for the element at the top of the stack
            st.pop();  // Remove the top element from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }

    // Step 2: Calculate nsr (Next Smaller Right)
    for(int i = 0; i < n; i++){
        // While there are elements in the stack and the current element is smaller than the top element of the stack
        while(!st.empty() && arr[st.top()] > arr[i]){
            nsr[st.top()] = i;  // Set nsr for the element at the top of the stack
            st.pop();  // Remove the top element from the stack
        }
        st.push(i);  // Push the current index onto the stack
    }

    // Step 3: Calculate the maximum area using nsl and nsr
    int max_area = 0;
    for(int i = 0; i < n; i++){
        int area = arr[i] * (nsr[i] - nsl[i] - 1);  // Calculate the area for the current element
        max_area = max(max_area, area);  // Update max_area if the current area is larger
    }
    return max_area;
}


// Second method (optimized: consists of 1 loop)

// Approach:
// 1. This method calculates nsl and nsr in a single loop while maintaining the stack.
// 2. For each element, we calculate the area using the current element as the height.
// 3. The width of the rectangle is determined by the distance between nsl and nsr for the current element.
// 4. We calculate the area as we process each element, updating the maximum area as needed.

// Time Complexity: O(n) - We only iterate through the array once.
// Space Complexity: O(n) - We use a stack to store indices of elements.

int second_method(int arr[], int n){
    stack<int>st;  // Stack to store indices of elements
    int max_area = 0;  // Variable to store the maximum area
    int curr_index, nsl_index, nsr_index;

    // Step 1: Process elements in a single loop
    for(int i = 0; i < n; i++){
        // While there are elements in the stack and the current element is smaller than the top element of the stack
        while(!st.empty() && arr[st.top()] > arr[i]){
            curr_index = st.top();  // Get the current index
            st.pop();  // Remove the top element from the stack
            nsr_index = i;  // Set nsr to the current index of the array

            // If the stack is not empty, the second top element of the stack gives us the nsl index
            if(!st.empty()){
                nsl_index = st.top();
                max_area = max(max_area, arr[curr_index] * (nsr_index - nsl_index - 1));  // Calculate the area
            }else{
                max_area = max(max_area, arr[curr_index] * nsr_index);  // Calculate the area when stack is empty
            }
        }
        st.push(i);  // Push the current index onto the stack
    }

    // Step 2: Clean up remaining elements in the stack
    while(!st.empty()){
        curr_index = st.top();  // Get the current index
        st.pop();  // Remove the top element from the stack
        nsr_index = n;  // Set nsr to the size of the array (end of the histogram)

        // If the stack is not empty, the second top element gives us the nsl index
        if(!st.empty()){
            nsl_index = st.top();
            max_area = max(max_area, arr[curr_index] * (nsr_index - nsl_index - 1));  // Calculate the area
        }else{
            max_area = max(max_area, arr[curr_index] * nsr_index);  // Calculate the area when stack is empty
        }
    }

    return max_area;
}

int main(){
    int arr[] = {2,3,4,2,6,5,4,5,3};
    int n = size(arr);
 
    // You can choose which method to use by uncommenting one of these:
    // int max_area = first_method(arr, n);
    int max_area = second_method(arr, n);  // This line calls the second (optimized) method

    cout << "Max Area: " << max_area;  // Output the maximum area
}
