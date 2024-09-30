#include <iostream>
using namespace std;

int main(){
    int arr[] ={1,0,1,0,1,0};
    int n = size(arr);
    int start =0,end=n-1;
    while(start<end){
        if(arr[start] == 0){
            start++;
        }else{
            if(arr[end]==0){
                swap(arr[start],arr[end]);
                start++;end--;  
            }else{
                end--;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}