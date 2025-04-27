#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
The problem involves finding the total time spent until the kth person has received all their tickets in a queue. The queue represents people standing in line to buy tickets, where each element in the queue represents the number of tickets a person wants to buy. The goal is to compute the time it takes until the kth person (0-indexed) has bought all of their tickets.

Link to the problem: https://leetcode.com/problems/time-needed-to-buy-tickets/description/

Time Complexity:
- The time complexity of the `first_method` is O(n^2) because we use a queue and simulate the entire ticket-buying process, where in each iteration, we are checking and updating each person in the queue.
- The time complexity of the `second_method` is O(n), as it calculates the total time using a more optimized approach without simulating each ticket-buying process for every person.

Space Complexity:
- The space complexity is O(n) for both methods due to the use of the queue in the `first_method` and the storage required for the `tickets` vector.

Step-by-Step Approach:

**first_method**:
1. The method simulates the queue, where each person in the queue reduces their ticket count one by one.
2. It starts by filling the queue with indices from `0` to `n-1` (each person in the queue).
3. It loops through the queue, reducing the tickets of each person until the kth person has zero tickets remaining.
4. Each time a person buys a ticket, they are either removed from the queue or pushed back if they still need more tickets.
5. It counts the total time until the kth person has bought all of their tickets.

**second_method**:
1. This method takes a more mathematical approach.
2. It first calculates the total time for the people up to and including the kth person.
3. Then, it calculates the total time for the remaining people after the kth person, considering that the kth person has one less ticket to buy when calculating the time for the subsequent people.
4. This method doesn't require simulating the queue, making it more efficient.

Explanation with Diagrams:

**first_method** Example:

Queue: [5, 1, 1, 1] (First element represents the number of tickets for the 0th person, second for the 1st person, and so on).
Goal: Find the total time until the kth person (0th in this case) has bought all their tickets.

- First, the queue is populated: Queue = [0, 1, 2, 3] (The numbers represent the indices of the people).
- Process the queue: 
    - First, person 0 buys a ticket (ticket count becomes 4).
    - Then, person 1, person 2, and so on, keep buying tickets in rounds until the kth person (index 0) gets all their tickets.

**second_method** Example:

Queue: [5, 1, 1, 1] (We want to calculate the time until the 0th person has bought all their tickets).

- Loop through the first `k` elements and calculate the total time for each element.
- For elements after the kth person, calculate time for the kth person considering one less ticket after they are done.

Simplified, the total time is calculated in two parts: the time for the kth element and the time for the other elements using a more direct formula.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// First method to solve the problem using a queue (O(n^2) time complexity)
int first_method(vector<int> tickets, int k) {
    queue<int> q;
    int total_time = 0;

    // Initialize the queue with indices representing each person in the queue
    for (int i = 0; i < tickets.size(); i++) {
        q.push(i); // Each person enters the queue in sequence
    }

    // Continue processing until the kth person gets their last ticket
    while (tickets[k] != 0) {
        tickets[q.front()]--;  // The person at the front of the queue buys a ticket
        if (tickets[q.front()]) {
            q.push(q.front());  // If the person still needs tickets, they go to the back of the queue
        }
        q.pop();  // The person at the front of the queue is processed
        total_time++;  // Increment the total time for each ticket buying event
    }
    return total_time;  // Return the total time when the kth person gets their last ticket
}

// Optimized method to solve the problem using a more mathematical approach (O(n) time complexity)
int second_method(vector<int> tickets, int k) {
    int n = tickets.size();
    int total_time = 0;

    // First loop: calculate the time for all people from 0 to k
    for (int i = 0; i <= k; i++) {
        total_time += min(tickets[k], tickets[i]);  // Add the minimum time taken by the ith or kth person
    }

    // Second loop: calculate the time for people from k+1 to n-1
    for (int i = k + 1; i < n; i++) {
        total_time += min(tickets[k] - 1, tickets[i]);  // Subtract 1 from kth person's time for the remaining people
    }

    return total_time;  // Return the total time after considering both parts
}

int main() {
    vector<int> tickets = {5, 1, 1, 1};  // The number of tickets each person wants
    int k = 0;  // The index of the person for whom we want to calculate the total time

    // Display results from both methods
    cout << first_method(tickets, k) << endl;  // Output from the first method
    cout << second_method(tickets, k) << endl; // Output from the second method

    return 0;
}
