#include<iostream>
#include<vector>
using namespace std;

// Here we have to find the number of combination
// that we can mad using this array those sum 
// will be equals to given k 
// ex: arr = {1,5,6}
// ans = {{1,6}, {1,1,5}, {1,1,1,1,1,1,1}, {6,1}, {1,5,1}, ....}

int ways(vector<int>arr, int n, int sum){
    if(sum == 0){
        return 1;
    }else{
        return 0;
    }

    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+= ways(arr, n, sum-arr[i]);
    }
}

int main(){
    vector<int>arr = {1,5,6};
    int k = 7;
    cout<<ways(arr, arr.size(), k);
}