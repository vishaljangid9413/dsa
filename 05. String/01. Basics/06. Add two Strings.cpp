#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem:
// We are given two strings that represent numbers. The task is to add these two numbers
// as if they were large integers, starting from the last digit and moving towards the first, 
// handling carry as needed. For example, "11" + "123" should result in "134".

// Approach:
// 1. Start adding the numbers from the last digit (just like normal addition).
// 2. Maintain a carry variable to handle values greater than or equal to 10.
// 3. Continue adding the corresponding digits of both strings until all digits are processed.
// 4. If one number is shorter, process the remaining digits of the longer number.
// 5. If a carry remains after processing all digits, add it to the result.
// 6. Reverse the result string since the digits are computed from the least significant to the most significant.

// Time Complexity: O(n), where n is the length of the longer number string. We traverse each digit once.
// Space Complexity: O(n), since we store the result string which has at most n+1 digits (in case of carry).

string add(string num1, string num2){
    string ans;  // String to store the result
    int sum = 0;  // Variable to hold the sum of current digits
    int carry = 0;  // Variable to hold carryover during addition
    int first = num1.size() - 1;  // Pointer to the last digit of num1
    int second = num2.size() - 1;  // Pointer to the last digit of num2

    // Add digits of num1 and num2 from the last digit to the first
    while (second >= 0) {
        // Add the corresponding digits from num1, num2, and carry
        sum = (num1[first] - '0') + (num2[second] - '0') + carry;
        carry = sum / 10;  // Compute the new carry
        ans += (sum % 10) + '0';  // Append the last digit of sum to result
        first--; second--;  // Move to the next digits (leftwards)
    }

    // If num1 has more digits left, continue adding them
    while(first >= 0){
        sum = (num1[first] - '0') + carry;  // Add the digit from num1 and carry
        carry = sum / 10;  // Update carry
        ans += (sum % 10) + '0';  // Append the last digit to result
        first--;  // Move to the next digit of num1
    }

    // If there is any carry left after processing all digits, append it to result
    if(carry){
        ans += '1';  // Add the carry as the last digit
    }

    // The digits were added from least significant to most, so reverse the result
    reverse(ans.begin(), ans.end());

    // Output the final result
    cout<<"Ans: "<<ans;
    return ans;  // Return the result string
}

int main() {
    string num1 = "11";  // First number
    string num2 = "123";  // Second number

    // Check if num1 is longer than num2 and call the 'add' function accordingly
    if (num1.size() > num2.size()){
        add(num1, num2);
    } else {
        add(num2, num1);
    }
}
