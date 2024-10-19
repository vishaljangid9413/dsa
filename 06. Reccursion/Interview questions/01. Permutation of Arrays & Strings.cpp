#include <iostream>
#include <vector>
using namespace std;

// Time Complexity = O(n*n!)
// Inner loop run n times * Permute functions calls n!

// Space Complexity = O(n)
// Here we ignore ans variable because we have to 
// pass it as ans, we dont using it for our purpose

// Question Link: https://leetcode.com/problems/permutations/


void permute(vector<int>&arr, vector<int>&visited, vector<vector<int>>&ans, vector<int>&temp){
    if(temp.size() == visited.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=0;i<visited.size();i++){
        if(visited[i] == 0){
            visited[i]++;
            temp.push_back(arr[i]);
            permute(arr, visited, ans, temp);
            visited[i]--;
            temp.pop_back();
        }
    }

}


void permute2(vector<int>&arr, int index, vector<vector<int>>&ans){
    if(index == arr.size() - 1){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i < arr.size();i++){
        swap(arr[i], arr[index]);
        permute2(arr, index+1,ans);
        swap(arr[i], arr[index]);
    }
}


int main(){
    vector<int>arr = {1,2,3};
    vector<vector<int>>ans;

    // ** First Approach
    // Here, we have to find all the permutaion and combination
    // of given array.
    // Here we create an array that stores the visits of elements
    // and then we loop through all the non visited elements 
    // and store them in a temp variable 
    // and if all the elements are visited and the temp is equals to 
    // size of arr then store the temp into the ans vector(2d)

    // vector<int>visited(arr.size(),0);
    // vector<int>temp;
    // permute(arr, visited, ans, temp);


    // ** Second Approach
    // Here, we just triverse our original array using index 
    // and increase index with every loop and just swap the 
    // elements of arr one by one to get unique combination 
    // every time and then the index is reached the end element 
    // then just push the copy of arr to the ans 
    // and then revert all the changes after completion of function 
    // in this approach we do not have to create two extra arrays 
    permute2(arr, 0, ans);


    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}