#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s = "ROORSP";
    string temp = s;
    int size = s.size();

    // Now reverse the string join both the string with '$'
    string rev = s;
    reverse(rev.begin(),rev.end());
    s += '$';
    s += rev;
    int n = s.size();

    vector<int>lps(n,0);

    // Find The Longest Prefix Suffix 
    int start = 0,end = 1;
    while(end < n){
        if(s[start] == s[end]){
            lps[end]= start+1;
            start++;end++;
        }else{
            if(start == 0){
                end++;
            } else{
                start = lps[start-1];
            }
        }
    }

    cout<<"Ans: "<<size-lps[n-1]<<endl<<"Characters: ";

    // Characters that added in the starting
    for(int i = size-1;i>=lps[n-1];i--){
        cout<<temp[i];
    }
}