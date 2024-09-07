#include <iostream>
using namespace std;

int main(){
    int arr[] ={2,3,5,10,50,80};
    int n = size(arr);
    int start =0,end=1,target=45;
    if (target<0){
        target *= -1;
    }
    while(end<n){
        if(arr[end]-arr[start]==45){
            cout<<"ANs: "<<arr[start]<<" "<<arr[end];
            break;
        }else if(arr[end]-arr[start]<target){
            end++;
        }else{
            start++;
        }
        if(start ==end){
            end++;
        }
    }   
   
}