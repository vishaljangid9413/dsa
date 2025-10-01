#include <iostream>
using namespace std;

void upper(string &s, int index){
    if(index == -1){
        return;
    }
    s[index] = 'A' + (s[index] - 'a');
    upper(s, index - 1);
}

int main(){
    string s = "namdradn";
    int index = s.size()-1;
    upper(s, index);
    cout<<s;
}