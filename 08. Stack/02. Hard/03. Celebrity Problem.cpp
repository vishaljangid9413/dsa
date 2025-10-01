#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Celebrity Problem
// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

/*
 * Question:
 * Given a matrix where each element represents whether a person knows another (1) or not (0),
 * we need to find the "celebrity". A celebrity is defined as a person who:
 * 1. Doesn't know anyone.
 * 2. Everyone knows the celebrity.
 *
 * The matrix is an NxN matrix where matrix[i][j] = 1 means person i knows person j,
 * and matrix[i][j] = 0 means person i does not know person j.
 *
 * Example input matrix:
 * { {0, 1, 0, 1, 1},
 *   {0, 0, 0, 1, 1},
 *   {0, 1, 0, 1, 0},
 *   {0, 0, 0, 1, 0},
 *   {1, 0, 1, 1, 0} }
 *
 * Output:
 * The index of the celebrity, or -1 if no celebrity exists.
 *
 * Approach:
 * 1. Initialize a stack and push all the people (indices) onto it.
 * 2. Compare the top two people and remove the one who cannot be a celebrity.
 * 3. After processing all pairs, one person remains in the stack, which could be the celebrity.
 * 4. Verify if the remaining person is truly a celebrity by checking:
 *    - The row corresponding to this person should have at most one '1' (meaning they don't know anyone).
 *    - The column corresponding to this person should have all '1's (meaning everyone knows them).
 * 5. If the checks are satisfied, return the index of the celebrity. Otherwise, return -1.
 */

// Time Complexity:
// - The stack initially contains all people, so we process each pair in O(1) time.
// - In total, we compare N-1 pairs, so the time complexity of this process is O(N).
// - After this, we perform a single scan of the matrix row and column for the remaining candidate, which takes O(N).
// Therefore, the overall time complexity is O(N).

// Space Complexity:
// - We are using a stack of size O(N) to store people. Hence, the space complexity is O(N).

int main(){
    // Example matrix of size N = 5
    vector<vector<int>> matrix = {
        {0,1,0,1,1},  // Person 0 knows Person 1, 3, and 4
        {0,0,0,1,1},  // Person 1 knows Person 3 and 4
        {0,1,0,1,0},  // Person 2 knows Person 1 and 3
        {0,0,0,1,0},  // Person 3 knows Person 3
        {1,0,1,1,0}   // Person 4 knows Person 1, 3, and 4
    };
  
    int n = matrix[0].size(); // The number of people (size of the matrix)
    
    stack<int> st; // Stack to store indices of people
    // Step 1: Push all people (indices) onto the stack
    for(int i = n-1; i >= 0; i--){
        st.push(i);
    }

    // Step 2: Compare top two elements (candidates for celebrity)
    while(st.size() > 1){
        int first = st.top(); // Get the first person
        st.pop();
        int second = st.top(); // Get the second person
        st.pop();

        // Check if the first person knows the second person or not
        if (matrix[first][second] && !matrix[second][first]){
            // If the first person knows the second but the second does not know the first,
            // the second person might be the celebrity. So push second back into the stack.
            st.push(second);
        } else if(!matrix[first][second] && matrix[second][first]){
            // If the second person knows the first but the first does not know the second,
            // the first person might be the celebrity. So push first back into the stack.
            st.push(first);
        }
    }

    // Step 3: Verify the remaining candidate
    if(st.empty()){
        cout<< -1;  // No celebrity found
    } else {
        int row = 0, col = 0;
        int num = st.top(); // The final candidate who could be the celebrity
        st.pop();

        // Step 4: Verify if the candidate is a celebrity
        for (int i = 0; i < n; i++){
            row += matrix[num][i];   // Count the number of people the candidate knows
            col += matrix[i][num];   // Count the number of people who know the candidate
        }

        // Step 5: If the row count is 0 or 1 (meaning they don't know anyone) and column count is N (meaning everyone knows them),
        // return the index of the celebrity, else return -1.
        cout<< (row <= 1 && col == n ? num : -1);
    }
}
