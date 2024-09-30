#include <iostream>
#include <vector>
using namespace std;

// Here we have to find the index of element from where 
// the sub string is matched in the main string  

// For this first we find the LPS (Longest Prefix Suffix)
// and then matches the sub string with the string 

int main(){
    string st = "aabaaabaaac";
    string sub = "aabaaac";
    int n = st.size();
    int m = sub.size();
    vector<int>lps(m, 0);

    // find the LPS of sub string 
    int first = 0, second = 1;
    while(second < m){
        if(sub[first] == sub[second]){
            lps[second] = first + 1;
            first++;second++;
        }else{
            if(first == 0){ 
                lps[second] = 0;
                second++;
            }else{
                first = lps[first-1];
            }
        }
    }


    // match the main string with sub string 
    // and first pointer trivese the main string 
    // and second pointer triverse the sub string 
    first = 0,second = 0;
    while(first < n && second < m){
        if(st[first] == sub[second]){
            first++;second++;
        }else{
            if(second == 0){
                first++;
            }else{
                second = lps[second - 1];
            }
        }
    }
    if(second == m){
        cout<<"Ans: "<< first-second;
    }else{
        cout<<"Ans: "<<-1;
    }
}