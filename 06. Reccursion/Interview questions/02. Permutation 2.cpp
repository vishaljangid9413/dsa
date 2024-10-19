#include <iostream>
#include <vector>
using namespace std;

// In pervious question the array consists only unique elements
// but here the array consists also duplicate elements 
// Array range: -10 < i < 10

// Time Complexity = O(n*n!)
// Inner loop run n times * Permute functions calls n!

// Space Complexity = O(n)
// Here we ignore ans variable because we have to 
// pass it as ans, we dont using it for our purpose

// Question Link: https://leetcode.com/problems/permutations-ii/description/


void permute(vector<int>&arr, int index, vector<vector<int>>&ans){
    if(index == arr.size() - 1){
        ans.push_back(arr);
        return;
    }
    // here we created a temp array 
    // with the size of array = 22 because
    // we already have given that element range 
    // is from -10 to 10
    // this array stores those values which are 
    // already appeared at the index place 

    // In the below lines we are using doing this 
    // temp[arr[i] + 10] == 0
    // it means we are checking that the current element 
    // is already appeared or not
    // and how we are checking,
    // we know that array consists negative and positive elements 
    // so positive elemnts can easily handled where we just 
    // increase the count of that element where our 
    // element == index of temp 
    // but for negative, array does not consist any negative indexing 
    // for this we just store each element with the positive margin
    // of 10, so for this we are adding 10 with the value 

    // ex: element = -8, after adding 10, 
    // element = -8 + 10 = 2;
    // ex: element = 5, after adding 10,
    // element = 5 + 10 = 15 

    vector<int>temp(21,0);
    for(int i = index;i<arr.size();i++){
        if(temp[arr[i] + 10] == 0){
            temp[arr[i]+10]++;
            swap(arr[i], arr[index]);
            permute(arr, index+1, ans);
            swap(arr[i], arr[index]);
        }
    }
}


int main(){
    vector<int>arr = {3,3,0,3};
    vector<vector<int>>ans;
    permute(arr, 0, ans);


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}