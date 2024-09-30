#include <iostream>
#include <vector>
using namespace std;

// Here, we have to find the smallest window (pair of contigeous element)
// elements can be duplicate 
// that consists all the unique elements 

// we have to use two pointer approach and sliding window 
// increase the second pointer till, window covers all the elements 
// that window includes 
// and then increase first pointer till the window removes any unique 
// element from the window 
// and save the length of window 

int main(){
    string s = "AABBBCBBAAC";
    vector<int>count(256,0);
    int first = 0,second = 0, diff = 0;
    int n = s.size(), cn = count.size();
    int ans = n;

    // # Find all the possible unique elments 
    while(first < n){
        if(count[s[first]] == 0){
            diff++;
        }
        count[s[first]]++;
        first++;
    }

    // clean the first and count arr 
    first = 0;
    for(int i=0;i<cn;i++){
        count[i]=0;
    }

    while(second<n){
        // Now increase the second pointer till it covers
        // all the unique elements of the current window 
        while(diff && second < n){
            if(count[s[second]]==0){
                diff--;
            }
            count[s[second]]++;
            second++;
        }

        // store the length of current window 
        // here we dont add one in (second-first) because in first loop
        // we already increased the second pointer by one 
        ans = min(ans, second-first);

        // Now decrease the size of window till 
        // the window covers all the unique elements 
        // diff == 0 represents that no elements are left from current window 
        while(diff == 0){
            count[s[first]]--;
            if(count[s[first]]==0){
                diff++;
            }
            first++;
            ans = min(ans,second - first + 1);
        }

    }

    cout<<"Ans: "<<ans;


}