#include <iostream>
using namespace std;

/**************************************************************
 * Problem: Magician and Chocolates
 * Link: https://www.interviewbit.com/problems/magician-and-chocolates/
 *
 * Problem Statement:
 * ------------------
 * We are given N bags, where each bag contains some chocolates.
 * A magician allows us to perform the following operation exactly X times:
 *   1. Pick any one bag (always pick the bag with the maximum chocolates).
 *   2. Eat all the chocolates from that bag.
 *   3. The magician refills that bag with half the number of chocolates 
 *      (floor division) that were just eaten.
 *
 * Our goal is to maximize the total number of chocolates eaten in these X steps.
 *
 * Example:
 * --------
 * Input:
 *   Bags = [2, 4, 6, 8, 10], X = 5
 * Output:
 *   29
 *
 * Explanation of steps:
 *   - Step 1: Pick bag with 10 → eat 10, bag becomes 5.
 *   - Step 2: Pick bag with 8 → eat 8, bag becomes 4.
 *   - Step 3: Pick bag with 6 → eat 6, bag becomes 3.
 *   - Step 4: Pick bag with 5 → eat 5, bag becomes 2.
 *   - Step 5: Pick bag with 4 → eat 4, bag becomes 2.
 *   Total = 10 + 8 + 6 + 5 + 4 = 33 → (mod 1,000,000,007) = 33.
 *
 *
 * Time and Space Complexity:
 * --------------------------
 *   - Let N = number of bags, X = number of steps allowed.
 *   - We use a max-heap (priority_queue in C++) to always fetch the bag 
 *     with the maximum chocolates.
 *   - Each insertion or deletion in a heap takes O(log N).
 *   - We perform at most X operations, so total complexity:
 *       Time = O(N log N + X log N)
 *       Space = O(N)   (to store chocolates in the heap)
 *
 *
 * Step-by-Step Approach:
 * ----------------------
 * 1. Insert all the bag values (chocolates) into a max-heap.
 * 2. Repeat the following X times:
 *      a) Extract the maximum element (the bag with the most chocolates).
 *      b) Add that value to our result (total chocolates eaten).
 *      c) Insert back half of that value (floor division) into the heap.
 * 3. Since the answer can be large, take the result modulo 1,000,000,007.
 *
 *
 * Visualization (Diagram):
 * ------------------------
 * Initial Heap (max on top):
 *             10
 *           /    \
 *          8      6
 *         / \
 *        2   4
 *
 * Operation 1: Eat 10 → push back 5
 *             8
 *           /   \
 *          5     6
 *         / \
 *        2   4
 *
 * Operation 2: Eat 8 → push back 4
 *             6
 *           /   \
 *          5     4
 *         / \
 *        2   4
 *
 * Operation 3: Eat 6 → push back 3
 *             5
 *           /   \
 *          4     4
 *         / \
 *        2   3
 *
 * Operation 4: Eat 5 → push back 2
 *             4
 *           /   \
 *          4     3
 *         / \
 *        2   2
 *
 * Operation 5: Eat 4 → push back 2
 *             4
 *           /   \
 *          3     2
 *         / \
 *        2   2
 *
 * Total chocolates eaten = 33.
 *
 * Key Idea:
 * ---------
 * The greedy strategy of always choosing the bag with the maximum chocolates 
 * ensures that we maximize chocolates eaten at every step. This is why a 
 * priority queue (max-heap) is the best data structure for this problem.
 *
 **************************************************************/


int main(){
    int arr[] = {2, 4, 6, 8, 10};
    int n = size(arr);

    int x = 5;

    // max number of choclates
    long long total_choclates = 0;

    // use priority queue to pick the largest eleemnts
    priority_queue<int> p;

    for(int i=0;i<n;i++){
        p.push(arr[i]);
    }

    while(x && !p.empty()){
        int element = p.top(); p.pop();
        total_choclates += element;

        // put half of choclates
        if(element/2){
            p.push(element/2);
        }

        x--;
    }

    // give unswer in modules
    total_choclates %= 1000000007; 
    cout<<total_choclates;
}