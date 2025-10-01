#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem:
// Find the factorial of a large number. For larger values, factorials become so large 
// that they cannot be stored in standard data types like int or long long.
// We need to handle large numbers by storing the result in an array.

// Approach:
// We use a vector to store individual digits of the result (like a big integer).
// We multiply the current factorial result by decreasing numbers (n to 1), 
// updating the vector by handling the carryover after each multiplication.
// Finally, reverse the result since the digits are stored in reverse order.

// Time Complexity: O(n * m), where n is the number whose factorial is to be calculated and 
// m is the number of digits in the resulting factorial. Each multiplication step is proportional to m.
// Space Complexity: O(m), where m is the number of digits in the resulting factorial.

int main(){
    int n = 5;  // Input number for which we need to find the factorial
    vector<int> ans(1,1);  // Vector to store factorial digits, initialized with 1

    // Loop until n becomes 1 (factorial = n * (n-1) * ... * 1)
    while(n > 1){
        int carry = 0, res = 0, size = ans.size();  // Initialize carry and res for each iteration
        for(int i = 0; i < size; i++){
            // Multiply the current digit by n and add carry from the previous step
            res = ans[i] * n + carry;
            carry = res / 10;  // Update carry
            ans[i] = res % 10;  // Store the result digit
        }

        // If carry remains, split it into digits and store it
        while(carry){
            ans.push_back(carry % 10);
            carry /= 10;
        }

        // Decrease the number for the next iteration
        n--;
    }

    // The result is stored in reverse order in the vector
    reverse(ans.begin(), ans.end());

    // Output the result
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
    }
}
