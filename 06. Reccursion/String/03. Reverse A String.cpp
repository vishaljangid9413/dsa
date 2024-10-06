#include <iostream>
using namespace std;

string rev(string s, int start, int end){
    swap(s[start], s[end]);
    if(start >= end){
        return  s;
    }
    return rev(s, start + 1, end -1);
}

int main(){
    string s = "namdradn";
    int start = 0, end= s.size()-1;
    cout<<rev(s, start, end);
}