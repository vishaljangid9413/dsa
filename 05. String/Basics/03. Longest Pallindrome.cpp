#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Here we just have to find the count of occurence
// and the just check that occurence is odd or even 
// If even it fits perfectly and if odd just decrease it by 
// to make it even and make odd variable true 
// and then just add everyone

void find_count_pallindrome(vector<int>lower, vector<int>upper){
    // find the count of longest palindrome
    int count = 0;
    bool odd = 0;
    for(int i=0;i<26;i++){
        if (lower[i] % 2 == 0){
            count += lower[i]; 
        }else if(lower[i] % 2 != 0) {
            count += lower[i] - 1;
            odd = 1;
        }
        if (upper[i] % 2 == 0){
            count += upper[i]; 
        }else if(upper[i] % 2 != 0){
            count += upper[i] - 1;
            odd = 1;
        }
    }
    
    cout<<"Ans: "<<count+odd<<endl;
}

void find_possible_pallindrome(vector<int>lower, vector<int>upper){
 // Create a longest Possible Palindrome
    string left;
    string right;
    char odd_word = '\0';  // Initialize odd_word with a default value
    
    for (int i = 0; i < 26; i++) {
        if(lower[i]%2 != 0){
            odd_word = char(i + 'a');
        }
        if(lower[i]){
            int temp = lower[i];   
            temp /= 2;
            while (temp){
                left += char(i + 'a');
                temp--;
            }
        }

 
        if(upper[i] % 2 != 0){
            odd_word = char(i + 'A');
        }
        if(upper[i]){
            int temp = upper[i];
            temp /=2;
            while (temp){
                left += char(i + 'A');
                temp--;
            }
        }
    }

    right = left;
    reverse(right.begin(),right.end());

    // check for the odd, append with string 
    if(odd_word != '\0'){
        left += odd_word;
    }

    cout<<left+right;
}

int main(){
    string s = "aaaAAbdc";
    vector<int> lower(26,0), upper(26,0);

    // find the occurence 
    for (int i=0;i<s.size();i++){
        // ASCII value of 'a' is 97
        // ASCII value of 'A' is 65
        if(s[i] >= 'a'){
            lower[s[i] - 'a']++;
        }else {
            upper[s[i] - 'A']++;
        }
    }

    find_count_pallindrome(lower, upper);
    find_possible_pallindrome(lower, upper);
}