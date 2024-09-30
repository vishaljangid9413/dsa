#include <iostream>
using namespace std;

// Panagram strings are those strings which consists
// all the letters of alphabets;

int main(){
    string st = "the quick brown fox jumps over the lazy dog";
    int arr[26] = {0};

    for(int i=0;i<st.size();i++){
        if(st[i] != ' '){
            int temp = st[i] - 'a';
            arr[temp]++;
        }
    }

    for(int i=0;i<size(arr);i++){
        if(arr[i] == 0){
            cout<<"Its not a Panagram Sentence";
        }   
    }
}