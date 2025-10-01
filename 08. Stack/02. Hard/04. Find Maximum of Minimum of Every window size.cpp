#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Question: 
Find the Maximum of Minimum for Every Window Size in a given array.

The task is to find the maximum of the minimums of all contiguous subarrays of every possible size of the given array. The idea is to compute the minimum element of all windows of size 1, 2, 3, ..., n, and then return the maximum of each minimum.

Link to Problem: 
https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions

Explanation:

1. **First Method (Brute Force)**:
   - The first approach uses three nested loops to check all subarrays of every size.
   - The minimum of each subarray is calculated, and then the maximum of these minimums is stored.

2. **Second Method (Efficient Using Stack)**:
   - This approach optimizes the solution by using a stack to track the next smallest element to the left and right of each element in the array.
   - It calculates the range for each element, which helps in finding the maximum of minimums in an efficient manner.

Time Complexity:
1. **First Method**: O(n^3)
   - There are three nested loops: one for window size, one for the start of the subarray, and one for calculating the minimum in the subarray.

2. **Second Method**: O(n)
   - The stack-based approach processes each element only once, resulting in a linear time complexity.

Space Complexity:
1. **First Method**: O(n)
   - We use an array to store the results for each window size.
   
2. **Second Method**: O(n)
   - A stack is used for storing the indices, and a result array is used to store the final output.

Detailed Approach for Second Method:
1. **Initial Setup**: 
   - We initialize an empty stack and a result array `ans` of size `n` initialized with 0.
   
2. **Stack Logic**:
   - Iterate through the array.
   - If the current element is smaller than the element at the top of the stack, pop from the stack and compute the range of the window size where the popped element is the minimum. Update the result array.
   - Push the current index onto the stack.

3. **Handling Remaining Elements**:
   - After processing the array, there may still be elements left in the stack. Process those elements in a similar manner, considering the "right end" of the array as the next smaller element.
   
4. **Final Adjustment**:
   - Traverse the `ans` array in reverse and update each element with the maximum of its value and the next element to the right.

Explanation with Diagrams:

Consider the array: 
[10, 20, 30, 50, 10, 70, 30]

### Stack Visualization:
1. **Initial Stack:**
   - Stack keeps track of indices. For example, for the element `30` at index `2`, we will check the next element to the right to find the next smaller element.
   
2. **Pop and Update Logic**:
   - As elements are popped from the stack, the maximum of minimums for different window sizes is updated. For example, when the element `50` at index `3` is popped, we compute the window size where `50` was the smallest element and store the maximum of those minimums in the result array.

3. **Final Answer**:
   - Once the stack is empty, we adjust the `ans` array to fill any remaining 0 values by taking the maximum of adjacent elements.

Below is the visualization of the second method working through the array:

Array: [10, 20, 30, 50, 10, 70, 30]

| Window Size | Min of Window | Max of Minimums (for that window size) |
|-------------|---------------|-----------------------------------------|
| 1           | 10            | 10                                      |
| 2           | 10            | 20                                      |
| 3           | 10            | 30                                      |
| 4           | 10            | 50                                      |
| 5           | 10            | 10                                      |
| 6           | 10            | 70                                      |
| 7           | 10            | 30                                      |

At each step, we compare the value in the `ans` array and update it with the maximum of the minimum values we calculated.

*/

// Time Complexity O(n)
vector<int> first_method(int arr[], int n){
    vector<int>ans(n, 0);

    for (int i=0;i<n;i++){
        for(int j = 0;j<n-i;j++){
            int mini = INT_MAX;
            for(int k = j;k<i+j+1;k++){
                mini = min(mini, arr[k]);
            }
            ans[i] = max(ans[i], mini);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return ans;
}

// Time Complexity O(n)
vector<int> second_method(int arr[], int n){
    vector<int>ans(n, 0);
    stack<int>st;

    // We going to use nsl (next smallest left) and nsr (next smallet right)
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int index = st.top();
            st.pop();

            // range = nsr(array element) - nsl(stack element) - 1
            int range = 0;
            if(st.empty()){
                // array element = i, stack elment = -1
                // range = i - (-1) -1 = i
                range = i; 
            }else{
                range = i - st.top() -1 ;
            }
            // place the value which is maximum, in new value or already place value
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        st.push(i);
    }

    // iterating on elements remains in the stack 
    while(!st.empty()){
        int index = st.top();
        st.pop();

        int range = 0;
        if(st.empty()){
            // array element should be n, becuase elements are in stack
            // do not consists any next smaller right
            range = n;
        }else{
            range = n - st.top() - 1;
        }
        ans[range - 1] = max(ans[range - 1], arr[index]);
    }

    // Noe, replace all the remaining '0' elements 
    // with required bigger adjacent elements 
    for(int i = n-2;i >= 0;i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }


    for(int i=0;i<n;i++){
        cout<<ans[i] << " ";
    }
    return ans;
}


int main(){
    int arr[] = {10,20,30,50,10,70,30};
    int n = size(arr);

    // vector<int> result1 = first_method(arr, n);
    vector<int> result2 = second_method(arr, n);
}
