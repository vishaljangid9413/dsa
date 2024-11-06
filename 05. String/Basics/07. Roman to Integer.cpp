#include <iostream>
using namespace std;

// Problem:
// We are given a string that represents a Roman numeral. The task is to convert this Roman numeral 
// into its corresponding integer value. Roman numerals are usually written from largest to smallest left to right.
// However, when a smaller numeral appears before a larger one, we subtract the smaller from the larger.

// Approach:
// 1. Create a helper function `number()` that maps each Roman numeral character to its integer value.
// 2. Traverse the Roman numeral string from left to right. If a numeral is smaller than the numeral after it, 
//    subtract its value; otherwise, add its value.
// 3. The last character in the string is always added, so handle it separately after the loop.
// 4. Return the final sum as the result.

// Time Complexity: O(n), where n is the length of the string. We traverse the string once.
// Space Complexity: O(1), constant space, since we're only using a few variables for calculation.

int number(char c){
    // This function returns the integer value corresponding to a Roman numeral character.
    if (c == 'I'){
        return 1;
    }else if (c == 'V'){
        return 5;
    }else if (c=='X'){
        return 10;
    }else if(c == 'L'){
        return 50;
    }else if(c == 'C'){
        return 100;
    }else if(c == 'D'){
        return 500;
    }else if(c == 'M'){
        return 1000;
    }
    return 0;  // Default case if an invalid Roman numeral is passed
}

int main(){
    // Input Roman numeral string
    string st= "CDXLIII";  // Example input: "CDXLIII" represents 443
    int sum = 0;  // Variable to store the final integer value

    // Traverse the Roman numeral string
    for (int i = 0; i < st.size() - 1; i++){
        // If the current numeral is smaller than the next one, subtract its value
        if (number(st[i]) < number(st[i+1])){
            sum -= number(st[i]);
        }
        // Otherwise, add its value
        else{
            sum += number(st[i]);
        }
    }
    // Add the value of the last numeral in the string
    sum += number(st[st.size()-1]);

    // Output the final result
    cout << sum;
}
