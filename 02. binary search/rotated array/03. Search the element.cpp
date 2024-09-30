#include <iostream>
using namespace std;

int main(){
    int arr[] ={4,5,6,7,10,1,2};
    int n = size(arr),target=10;
    int start = 0,end=n-1,mid,ans=-1;
    while(start<=end){
        mid = start +(end-start)/2;
        if(arr[mid] == target){
            ans = mid;
            break;
        }else if(arr[0]<=arr[mid]){
            if(arr[0] <= target && target < arr[mid]){
                end = mid-1;
            }else{
                start = mid +1;
            }
        }else{
            if(arr[mid] < target && target <= arr[end]){
                start = mid +1;
            }else{
                end = mid-1;
            }
        }
    }
    cout<<"SSSSS: "<<ans;
}