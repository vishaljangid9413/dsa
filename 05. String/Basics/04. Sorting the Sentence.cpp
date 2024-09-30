#include <iostream>
#include <vector>
using namespace std;

// Here we have to sort the sentence 
// after every word their is a number attach to it
// and 1 <= number <= 9;


int main(){
    string st = "is2 sentence4 this1 a3";
    string ans;
    vector<string>hello(10);
    int count=0;
    
    // Add a empty space at the end 
    st+=' ';

    // now just check for the space and get the number
    // from word and place the string to index of that number 
    for (int i=0;i<=st.size();i++){
        if(st[i] == ' '){
            int index = ans[ans.size()-1] - '0';
            ans.pop_back();
            hello[index] = ans;
            ans.clear();
            count++;
        }else{
            ans += st[i];
        }
    }

    for(int i=1;i<=count;i++){
        ans += hello[i] + ' ';
    }
    ans.pop_back();
    
    cout<<"ANS: "<<ans;

}