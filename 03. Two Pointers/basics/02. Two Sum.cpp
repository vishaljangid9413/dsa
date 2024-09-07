#include <iostream>
using namespace std;

int main(){
    int arr[] ={2,7,11,15,27};
    int n = size(arr);
    int start =0,end=n-1,target=22;
    while(start<end){
        if(arr[start]+arr[end]==target){
            cout<<"Ans: "<<arr[start]<<" "<<arr[end]<<endl;
            break;
        }else if(arr[start]+arr[end] < target){
            start++;
        }else{
            end--;
        }

    }
   
}