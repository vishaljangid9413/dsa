#include <iostream>
#include <vector>
using namespace std;

// KMP ALGORITHM - Knuth Moris Pratt Algorithm 
// This algorithm works like if you are matchin two pointers
// and they match then add the first pointer's index + 1 in second pointer
// and if not matched then check if first pointer index is 0 
// if it is then store 0 in second pointer
// or if index is not 0, then check the value of previous element of
// first pointer and point the first pointer to that elements value
// and last pointer's value is your ans 


// Here we have to find the prfix and suffix 
// in a string means longest possible strings 
// prfix - starts with starting of string 
// suffix - starts with ending of string 
// ex = "abacab", prufix = "ab", suffix = "ab"

int main(){
    string s = "abacab";
    int n= s.size();
    vector<int>lps(n, 0);
    int start = 0, end = 1;

    while(end < n){
        if(s[start] == s[end]){
            lps[end] = start+1;
            start++;end++;
        }else{
            if(start == 0){
                lps[end]=0;
                end++;
            }else{
                start = lps[start-1];
            }
        }
    }
    cout<<"Ans: "<<lps[n-1];
}