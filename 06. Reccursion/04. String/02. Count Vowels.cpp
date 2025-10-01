#include <iostream>
using namespace std;

int count(string s, int index){
    if(index == -1){
        return 0;
    }
    if(s[index] == 'a' | s[index] =='e' | s[index] == 'i' | s[index] == 'o' | s[index] == 'u'){
        return 1 + count(s, index - 1);
    }
    return count(s, index - 1);
}

int main(){
    string s = "naman";

    cout<<count(s, s.size()-1);
}