#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


// Here, we have given a circular string 
// and there is also a sub string of it.
// we have to find that the sub string is a part 
// of the string or not.

// Here we add the main string to self,
// so the rotated substring can be in a linear state 

int main(){
    string s = "cdeabroab";
    string sub = "abcde";
    s += s;
    int n = s.size(),m = sub.size();
    vector<int>lps(m,0);
    
    int first = 0,second = 1;
    while(second < m){
        if(sub[first]==sub[second]){
            lps[second] = first + 1;
            first++;second++;
        }else{
            if(first == 0){
                second++;
            }else{
                first = lps[first-1];
            }
        }
    }


    first = 0,second=0;
    while(first < n && second < m){
        if(s[first] ==  sub[second]){
            first++;second++;
        }else{
            if(second==0){
                first++;
            }else{
                second = lps[second-1];
            }
        }
    }

    if(second == m){
        cout<<"Ans: "<<second<<" "<<1;
    }else{
        cout<<"Ans: "<<-1;
    }
}