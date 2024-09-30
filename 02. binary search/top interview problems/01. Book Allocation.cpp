#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_possible(vector<int>arr,int n,int mid,int k){
    int total = 0;
    int count = 1;
    for (int i=0;i<n;i++){
        if(total+arr[i] <= mid){
            total += arr[i];
        }else{
            count++;
            total = arr[i];
        }
    }
    // Here, we are determining if the books can be distributed among a certain number of students. 
// If the number of books allotted is equal to or fewer than `k` and the student count `<= k`, 
// then the distribution is feasible. 
// Now, consider the case where the number of books exceeds `k` by just 1. 
// If the resulting student count is greater than `k + 1`, it would clearly exceed the available books. 
// In this case, it becomes impossible to allocate `k + 1` books to `k + 2` students.

    if(count <= k ){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    vector<int>arr ={15, 10, 19, 10, 5, 18, 7};
    int n = arr.size();
    int start = 0,end =0,mid,ans=-1,k=5;

    if (n < k){
        return -1;
    }

    for (int i = 0;i<n;i++){
        start = max(start, arr[i]);
        end += arr[i];
    }

    while (start<=end){
        mid = start+(end-start)/2;
        bool possible = is_possible(arr,n,mid,k);
        if(possible == 1){
            ans = mid;
            end = mid-1;
        }else{
            start = mid +1;
        }
    }
    cout<<"Ans: "<<ans;
}