#include <iostream>
using namespace std;

int main(){
    int arr[] ={4,6,8,10,11,0,1,2};
    int n = size(arr);
    int start = 0,end=n-1,mid,ans=arr[0];
    while(start<=end){
        mid = start +(end-start)/2;
        if (arr[0] < arr[mid]){
            start = mid +1;
        }else{
            ans = mid;
            end = mid-1;
        }
    }
    cout<<"SSSSS: "<<ans;
}