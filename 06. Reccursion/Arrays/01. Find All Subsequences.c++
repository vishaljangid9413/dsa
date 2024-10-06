#include <iostream>
#include <vector>
using namespace std;

// Here, we have to find all sub sequences of array 
// Ex - {1,2}
// sub - {}, {1}, {2}, {1,2}

// time_complexity = O(2^n)
// space_complexity = O(n+2^n)

// TODO SAME CODE WILL WORK FOR STRING SUBSEQUENCES ALSO 

void sub_seq(vector<int>arr, int index, int n, vector<vector <int>>&ans, vector<int>&temp){
    // if index and the size of array is same 
    // then just push a blank array to the ans 
    if(index == n){
        ans.push_back(temp);
        return;
    }

    // first run for No scenario
    // where we dont want to add the current index value 
    // to the temp 
    sub_seq(arr, index + 1, n, ans, temp);

    // and now run for Yes case 
    // where we add the value to the temp 
    temp.push_back(arr[index]);
    sub_seq(arr, index + 1, n, ans, temp);
    // we are also removing the same element we put into 
    // it because we are taking the temp as reference 
    // means a single temp is using in each loop 
    // so we have to manage it like this 
    temp.pop_back();
}

int main(){
    vector <int>arr = {1,2};
    vector <vector <int>>ans;
    vector <int>temp;
    int n = arr.size();

    sub_seq(arr, 0, n, ans, temp);

    for(int i = 0;i<ans.size();i++){
        cout<<"{ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
}