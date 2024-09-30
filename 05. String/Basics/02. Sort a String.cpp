#include <iostream>
using namespace std;

int main(){
    string st = "gfkiclwma";
    int arr[26] = {0};
    string ans;

    for(int i=0;i<st.size();i++){
        arr[st[i]-'a']++;
    }

    for(int i=0;i<size(arr);i++){
        char c = i + 'a';
        while(arr[i]){
            ans += c;
            arr[i]--;
        }
    }

    cout<<ans;
}