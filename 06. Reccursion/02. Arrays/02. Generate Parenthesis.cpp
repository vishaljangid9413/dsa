#include <iostream>
#include <vector>
using namespace std;

// Here we have given a number 
// and we have to create combination of parenthesis 
// that how many combination can we create with given 
// number of parenthesis

// ex: int n = 3 
// {}, {(),(),()}, {(()),()},{(),(())}, {((()))}

// its also have the almost same approach like the
// previous question but some twist 

void parenthesis(int n, int left, int right, vector<string>&ans, string &temp){
    // here left and right represents for 
    // number of left parenthesis, and number of right
    // and the left and right parenthesis sould be 
    // equal to create a fault free ans 
    if((left + right) == 2*n){
        ans.push_back(temp);
        return;
    }

    if(left < n){
        temp.push_back('(');
        parenthesis(n, left + 1, right, ans, temp);
        temp.pop_back();
    }

    if(right < left){
        temp.push_back(')');
        parenthesis(n, left, right + 1, ans, temp);
        temp.pop_back();
    }
}

int main(){
    int n= 3;
    vector<string>ans;
    string temp;

    parenthesis(n, 0, 0, ans, temp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }    
}

