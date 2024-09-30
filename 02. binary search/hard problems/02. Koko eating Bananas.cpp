#include <iostream>
using namespace std;

bool is_possible(int arr[], int n, int mid, int hour){
    int total=0;
    for (int i=0;i<n;i++){
        // here you can use this only 
        total += (arr[i]+mid-1)/mid; //working like ceil

        // or can use this, both works correctly 
        // if(arr[i] < mid){
        //     total++;
        // }else{
        //     total += arr[i] / mid;
        //     if(arr[i] % mid != 0){
        //         total++;
        //     }
        // }
        if(total>hour){
            return 0;
        }
    }
    return 1;
}

int main(){
    int arr[] = {30,11,23,4,20};
    int n = size(arr);
    for(int i= 0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    int start = 0, end=0,mid,ans,hour=5;
    long long sum=0;
    for (int i=0;i<n;i++){
        sum+= arr[i];
    }
    start = sum/hour;
    ans = arr[n-1];

    if (!start)
    start=1;

    while(start<=end){
        mid = start+(end-start)/2;
        bool possible = is_possible(arr,n,mid,hour);
        if(possible ==1){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<"Ans: "<<ans;
}