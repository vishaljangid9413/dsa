#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Problem 1: Print All Numbers in a Sliding Window of Size K
Link to the problem (if available): N/A

Time Complexity: O(n^2)
- The time complexity is O(n^2) because we are processing each window of size K for every element in the array. For each window, we print the elements and pop one element, which could involve up to O(K) operations for each window.

Space Complexity: O(K)
- We are using a queue to store up to K elements at a time. Hence, the space complexity is O(K).

Step-by-Step Approach:
1. Initialize a queue `q`.
2. Fill the queue with the first `k-1` elements (this is a temporary step to ensure the window is ready).
3. For each element from index `k-1` to `n-1` in the array:
   - Add the element to the queue.
   - Call `first_display()` to print the current window of size `k`.
   - Pop the element that is now outside the window.
4. This gives us the sliding window and prints the elements in the current window.

Explanation with Diagrams:
- Initially, the queue is empty.
- Fill the queue with the first `k-1` elements.
- Then for each new element, push it into the queue and print the contents of the queue (i.e., the current window).
- Pop the oldest element to maintain the window size.

*/

// Function to print all numbers in the current sliding window
void first_display(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";  // Print the front element of the queue
        q.pop();  // Remove the front element of the queue
    }
    cout<<endl;  // Print a new line after each window
}

void first_problem(){
    int arr[] = {2, 3, 1, 5, 6, 7, 8};  // Input array
    int n = size(arr);  // Size of the array
    int k = 3;  // Size of the sliding window

    queue<int>q;
    // Fill the first k-1 elements
    for (int i = 0; i < k-1; i++) {
        q.push(arr[i]);  // Push elements into the queue
    }

    // Now slide the window across the array
    for (int i = k-1; i < n; i++) {
        q.push(arr[i]);  // Push the new element into the queue
        first_display(q);  // Print the elements in the current window
        q.pop();  // Pop the element that is now out of the window
    }
}

/*
Problem 2: First Negative Integer in Every Window of Size K
Link to the problem (if available): N/A

Time Complexity: O(n)
- The time complexity is O(n) because we only process each element in the array once. Each element is pushed into and popped from the queue at most once.

Space Complexity: O(K)
- We use a queue to store the indices of negative elements in the current window. At most, we need to store K indices.

Step-by-Step Approach:
1. Initialize an empty queue `q` to store the indices of negative numbers.
2. Fill the queue with the indices of negative numbers in the first `k-1` elements.
3. For each element from index `k-1` to `n-1`:
   - If the current element is negative, add its index to the queue.
   - Remove indices from the front of the queue if they are outside the current window.
   - If the queue is empty, no negative number is in the window, so append `0` to the answer.
   - Otherwise, append the value of the element at the index stored at the front of the queue.
4. Print the result, which shows the first negative integer in each window.

Explanation with Diagrams:
- Initially, the queue is empty.
- As we move through the array, we store the indices of negative numbers.
- For each window, the queue keeps track of negative numbers that are still in the current window.
- If the queue is empty, there is no negative number in the window, and `0` is appended.

*/

void second_problem(){
    int arr[] = {2, -3, -4, -2, 7, 8, 9, -10};  // Input array
    int n = size(arr);  // Size of the array
    int k = 3;  // Size of the sliding window
    vector<int> ans;  // Vector to store the result

    queue<int>q;
    // Fill the first k-1 elements with negative number indices
    for (int i = 0; i < k-1; i++) {
        if (arr[i] < 0) {
            q.push(i);  // Push the index of negative elements into the queue
        }
    }

    // Slide the window across the array
    for (int i = k-1; i < n; i++) {
        if (arr[i] < 0) {
            q.push(i);  // If the current element is negative, add its index to the queue
        }

        if (q.empty()) {
            ans.push_back(0);  // No negative number in the window, append 0
        } else {
            // Check if the current element in the queue is part of the current window
            if (q.front() <= i - k) {
                q.pop();  // Remove elements that are outside the current window
            }
            if (q.empty()) {
                ans.push_back(0);  // No negative number in the window, append 0
            } else {
                ans.push_back(arr[q.front()]);  // Append the first negative number in the window
            }
        }
    }

    // Print the result: first negative integer in every window
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    first_problem();  // Call the function to print all numbers in window size k
    second_problem();  // Call the function to find the first negative integer in every window size k
}
