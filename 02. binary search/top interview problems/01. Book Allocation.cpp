#include <iostream>
#include <vector>
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
    cout<<"DDDDDDD "<<ans;
}