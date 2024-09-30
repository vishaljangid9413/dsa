#include <iostream>
#include <vector>
using namespace std;

// Here we have to sort the extract the vowels from string 
// sort them according to their ASCII value and 
// place them the same position that vowels placed 
// ex: "lEetcOde" => "lEOtcede"

int main(){
    string st = "lEetcOde";
    vector <int> lower(26,0), upper(26,0);

    // first extract and store occurence 
    bool vowel_count = 0;
    for (int i=0;i<st.size();i++){
        if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u'){
            lower[st[i] - 'a']++;
            st[i]='#';
            vowel_count = 1;
        } else if(st[i] == 'A' || st[i] == 'E' || st[i] == 'I' || st[i] == 'O' || st[i] == 'U'){
            upper[st[i] - 'A']++;
            st[i]='#';
            vowel_count =1;
        }
    }

    if (vowel_count == 0){  
        // return st;
        cout<<"Return: "<<st;
    }

    // Now create a new string and store vowels in sorted form 
    string ans;
    // First Uppper 
    for(int i=0;i<26;i++){
        char c = i + 'A';
        while(upper[i]){
            ans+=c;
            upper[i]--;
        }
    }
    // Second Lower 
    for(int i=0;i<26;i++){
        char c = i + 'a';
        while(lower[i]){
            ans+=c;
            lower[i]--;
        }
    }

    // now replace '#' with the sorted vowels
    int count =0;
    for (int i=0;i<st.size();i++){
        if (st[i] == '#'){
            st[i] = ans[count];
            count++;
        }
        if(count == ans.size()){
            break;
        }
    }

    cout<<"Ans: "<<st;

}