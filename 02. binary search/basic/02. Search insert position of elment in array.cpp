#include <iostream>
using namespace std;

int main(){
    int arr[] ={1,4,6,8,10,14,16,18};
    int n= size(arr), target=-1;
    int start = 0,end=n-1,ans=n,mid;
    while (start<=end){
        mid = start + (end-start)/2;
        if(arr[mid] >= target){
            ans = mid;
            end= mid-1;
        }else{
            start = mid+1;
        }
    }
    cout<<"Ans:: "<<ans;
}