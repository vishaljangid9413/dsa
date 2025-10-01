#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have to find the sum of all the possible subsets
// so we just have to follow the yes and no approach 
// means that just decide wheter to use current element 
// or just skip 

// Time_complexity = O(2^n)
// Space_complexity = O(n)

void print(vector<int>arr, int index, int n, int sum, vector<int>&ans){
    if(index == n){
        ans.push_back(sum);
        return;
    }

    // here we are not adding the current element 
    // value with the sum 
    print(arr, index+1, n, sum, ans);
    // and here we are adding the current value 
    print(arr, index + 1, n, sum+arr[index], ans);
}


int main(){
    vector<int>arr = {1,2,3,4};
    int n = arr.size(), sum = 0;
    vector<int>ans;
    vector<int>temp;

    print(arr, 0, n, sum, ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}