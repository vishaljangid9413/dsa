#include <iostream>
#include <vector>
using namespace std;

// Flip all the 0s to 1 in k size windows and gives the flip count
// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/


// In this problem we go step by step
// first we start iterate through array and 
// when a 0 number comes we start our logic 
// we just find the window size and pick the index of its last element 
// and stores it 
// and it means that from the current index to the stored index 
// all the element is flipped, we imagined that 
// and then while iterating through next elements we check 
// that the element is 0 or 1 means it is flipped or not 
// for finding it we use our stored elements 
// the no. of stored elements resembles the no. of flips 
// means if element is 1 and stored elements are 3 means odd 
// then its actually flipped 3 times  and it will be become 0 
// so we have to check this condition when 
// element is 0 and stored lements are even 
// and element is 1 and stored elements are odd 
// because this condition says that the numbers become 0 after flips 
// so we continue our iteration and checking that number is 0 or not after flip or before flip 
// and also check that the index element present in starting of the queue is not part of our current or next window then remove it
// and if find ourselves in a particular condtion where a element is 0 but its next consecutive elements
// can't able to create a k size window then we should return -1 
// because it means that we can't able to create a window and flip it 
// so we do not able to filp 0 to 1


// CHAT GPT EXPANATION
// Problem: Minimum Number of K Consecutive Bit Flips
// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

// Goal: Flip k consecutive bits to turn the entire array into all 1s
// If not possible, return -1

// Approach (based on your code):

// 1. We iterate through each index of the array from left to right.

// 2. We use a queue to store the ending indices of the flip windows.
//    This means that each time we perform a flip at index i, we add (i + k - 1) to the queue.

// 3. At each index, we first check if the flip at the front of the queue has expired.
//    A flip expires when its effect no longer includes the current index,
//    so if q.front() < i, we pop it from the queue.

// 4. The size of the queue tells us how many flips are currently active at index i.
//    This is important because:
//    - An even number of flips means the current bit is unchanged (original).
//    - An odd number of flips means the current bit has been flipped.

// 5. We compare the parity of the active flips with the value at nums[i].
//    If q.size() % 2 == nums[i], it means the current bit is 0 after considering flips,
//    and we must flip the next k bits starting at index i.

// 6. Before flipping, we check if i + k - 1 >= n.
//    If true, it means there aren’t enough bits left to perform a full flip,
//    so we return -1 because it's impossible to solve.

// 7. If the flip is possible, we add (i + k - 1) to the queue
//    to represent the end of the new flip window,
//    and increment the flip counter.

// 8. After finishing the loop, we return the total number of flips performed.



// Time Complexity:
// - O(n) where n is the length of the input array `nums`. 
//   - We are iterating through the array once, and each flip operation (push and pop from the queue) is done in constant time.


// Space Complexity:
// - O(k), where k is the size of the sliding window. The queue stores indices of flip windows, and the maximum number of
//   flips will be proportional to the number of elements involved in the window (thus O(k)).

int main(){
    // nums: the binary array to flip, k: window size for the flip
    vector<int>nums = {0,1,0};
    int n = nums.size();  // Length of the binary array
    int k = 1;  // The window size for the flip (size of consecutive bits to flip)
    queue<int> q;  // Queue to store indices of flip windows (end indices of flips)
    int flip = 0;  // Counter for the number of flips performed

    // Traverse the array
    for (int i = 0; i < n; i++) {
        // Remove flip windows that have ended (i.e., flips that no longer affect the current index i)
        if (!q.empty() && q.front() < i) {
            q.pop();  // Remove the flip window that ended before index i
        }

        // If the size of the queue is odd, the current bit is flipped an odd number of times
        // If the size of the queue is even, the current bit is flipped an even number of times
        // Therefore, we check if the current bit is 0 after considering the flips
        // `q.size() % 2 == nums[i]` means if the bit at nums[i] is flipped (i.e., 0 when it should be 1 or vice versa)
        if (q.size() % 2 == nums[i]) {
            // If there aren’t enough elements left in the array to flip a window of size k, return -1
            if (i + k > n) {
                return -1;  // Not enough elements for a full flip
            }

            // Perform a flip starting from index i
            q.push(i + k - 1);  // Add the index of the flip window’s end (i + k - 1) to the queue
            flip++;  // Increment the flip counter
        }
    }

    // Output the total number of flips
    cout << flip;
}