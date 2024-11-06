#include <iostream>
using namespace std;

// Problem:
// Convert a given integer to its Roman numeral representation. 
// Roman numerals use the characters I, V, X, L, C, D, M to represent values.
// There are certain combinations of these characters for specific values like IV (4), IX (9), etc.

// Approach:
// 1. First Approach (Greedy): Start with the largest Roman numeral and subtract it from the number until it's smaller. 
//    Keep adding the corresponding Roman numeral to the result string.
// 2. Second Approach (Decomposition): Break down the number into thousands, hundreds, tens, and ones.
//    Use predefined arrays of Roman numerals for each digit's place to quickly build the result string.

// Time Complexity: O(1) for both approaches because the number is bounded by a maximum value (3999).
// Space Complexity: O(1) for both approaches since the memory used is constant, regardless of the input value.

void first_approach(int num){
    // Arrays storing Roman numeral values and their corresponding symbols
    int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ch[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string ans;  // Resulting Roman numeral string
    int index = 0;  // Index to traverse through the Roman numeral arrays

    // Loop until the number is reduced to 0
    while(num > 0){
        // If the current number is greater than or equal to the Roman numeral value
        if(num >= arr[index]){
            // Subtract the Roman numeral value from the number
            num -= arr[index];
            // Append the corresponding Roman numeral symbol to the result
            ans += ch[index];
        }else{
            // Move to the next smaller Roman numeral
            index++;
        }
    }
    cout << ans << endl;  // Output the Roman numeral representation
}

void second_approach(int num){
    // Predefined Roman numeral symbols for ones, tens, hundreds, and thousands
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};
    
    // Construct the Roman numeral by breaking the number into thousands, hundreds, tens, and ones
    string ans = ths[num/1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    
    cout << ans;  // Output the Roman numeral representation
}

int main(){
    int num = 3749;  // Input number to convert

    // Call both approaches and print the Roman numeral representation
    first_approach(num);  // Output for the first approach
    second_approach(num);  // Output for the second approach
}
