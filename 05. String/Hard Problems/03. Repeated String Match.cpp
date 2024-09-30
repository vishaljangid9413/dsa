#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Here, we have a string and a sub string
// but here the string is smaller then sub string
// so here we have to add the string to itself 
// till the second string can be a sub string of it 
// and we have to give the count of repeatation of strings 

bool KMP_MATCH(string s, string sub){
    vector<int>lps(sub.size(),0);

    // find lps 
    int first = 0,second = 1;
    while(second < sub.size()){
        if(sub[first] == sub[second]){
            lps[second] = first+ 1;
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
    while(first < s.size() && second < sub.size()){
        if(s[first] == sub[second]){
            first++;second++;
        }else{
            if (second ==0){
                first++;
            }else{
                second = lps[second-1];
            }
        }
    }
    if(second == sub.size()){
        return true;
    }else{
        return false;
    }
}

int main(){
 string s = "abcd";
 string sub = "cdabcdab";
int n= sub.size();

 if(s == sub){
    cout<<"Ans: "<<1;
    return 1;
 }

 int repeat = 1;
 string temp = s;

 while(temp.size() < n){
    temp += s;
    repeat++;
 }

 if(KMP_MATCH(temp,sub)){
    cout<<"Ans: "<<repeat;
    return repeat;
 }

// again check with adding the string to itself again 
 if(KMP_MATCH(temp+=s,sub)){
    cout<<"Ans: "<<repeat+1;
    return repeat+1;
 }

cout<<"-1";



}