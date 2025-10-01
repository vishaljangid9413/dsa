#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have an array and a target
// we have to find that how many subsets are there 
// who have the sum equals to target, give the count

// time_complexity = O(2^n)
// space_complexity = O(n)


int target_sum(int arr[], int index, int n, int target, int ans){
    if(target == 0){
        return ans+1;
    }
    if(index == n || target < 0){
        return ans;
    }
    return (target_sum(arr, index+1, n, target,ans) + target_sum(arr, index+1, n, target-arr[index],ans));
}


int main(){
    int arr[] = {1,2,3};
    int n = size(arr), target = 2;
    int ans = 0;
    cout<<target_sum(arr, 0, n, target, ans);
}