#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have given a target and
// we have to find that subset which 
// have the sum equals to the target value 

// time_complexity = O(2^n)
// space_complexity = O(n)


bool target_sum(int arr[], int index, int n, int target){
    if(target == 0){
        return true;
    }
    if(index == n || target < 0){
        return false;
    }
    return (target_sum(arr, index+1, n, target) || target_sum(arr, index+1, n, target-arr[index]));
}


int main(){
    int arr[] = {3, 6, 4, 5};
    int n = size(arr), target = 12;

    bool possible = target_sum(arr, 0, n, target);
    cout<<possible;
}