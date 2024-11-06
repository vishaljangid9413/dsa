#include <iostream>
#include <vector>
using namespace std;

// Problem:
// We need to extract vowels from a given string, sort them according to their ASCII values,
// and then place them back in their original positions, resulting in a modified string.
// For example, "lEetcOde" becomes "lEOtcede".

// Approach:
// 1. Traverse the string and extract vowels, keeping track of their occurrences in separate arrays for upper and lower case.
// 2. Replace vowels in the original string with a placeholder (e.g., '#') to keep their positions.
// 3. Create a new string containing sorted vowels by iterating through the occurrence arrays.
// 4. Replace the placeholders in the original string with the sorted vowels.
// 5. Print the modified string.

// Time Complexity: O(n + m), where n is the length of the input string (for extraction and replacement),
// and m is the number of vowels (for sorting and replacing back).
// Space Complexity: O(1) for the fixed-size arrays storing occurrences of vowels (constant space).

int main(){
    string st = "lEetcOde";  // Input string
    vector<int> lower(26, 0), upper(26, 0);  // Arrays to track occurrences of lower and upper case vowels

    // First, extract and store occurrences of vowels
    bool is_vowel = 0;  // Flag to check if there are any vowels in the string
    for (int i = 0; i < st.size(); i++){
        if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u'){
            lower[st[i] - 'a']++;  // Count lower case vowels
            st[i] = '#';  // Replace the vowel with '#'
            is_vowel = 1;  // Set flag indicating at least one vowel is found
        } else if (st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U'){
            upper[st[i] - 'A']++;  // Count upper case vowels
            st[i] = '#';  // Replace the vowel with '#'
            is_vowel = 1;  // Set flag indicating at least one vowel is found
        }
    }

    // If no vowels found, return the original string
    if (is_vowel == 0){  
        cout << "Return: " << st;  // Print the string with no vowels
        return 0;  // Exit the program
    }

    // Now create a new string and store vowels in sorted form
    string ans;  // String to store sorted vowels

    // First, add upper case vowels in sorted order
    for (int i = 0; i < 26; i++){
        char c = i + 'A';  // Get the character for the current index
        while (upper[i]){  // While there are occurrences of this vowel
            ans += c;  // Add it to the result string
            upper[i]--;  // Decrease the count
        }
    }

    // Second, add lower case vowels in sorted order
    for (int i = 0; i < 26; i++){
        char c = i + 'a';  // Get the character for the current index
        while (lower[i]){  // While there are occurrences of this vowel
            ans += c;  // Add it to the result string
            lower[i]--;  // Decrease the count
        }
    }

    // Now replace '#' in the original string with the sorted vowels
    int count = 0;  // Counter for the sorted vowels
    for (int i = 0; i < st.size(); i++){
        if (st[i] == '#'){  // If the current character is a placeholder
            st[i] = ans[count];  // Replace it with the next sorted vowel
            count++;  // Move to the next vowel
        }
        if (count == ans.size()){  // If all sorted vowels have been used
            break;  // Exit the loop
        }
    }

    // Output the final modified string with sorted vowels
    cout << st;
}
