#include <iostream>
using namespace std;

int main(){
    int arr[] ={4,2,0,5,2,6,2,3};
    int n = size(arr);
    int start = 0, end = n-1;
    int lmax = 0,rmax=0;
    int index = 0;
    int ans=0;
    for (int i=0;i<n;i++){
        if(arr[i]>arr[index]){
            index = i;
        }
    }

    while((start < index) | (index < end)){
        if(start <index){
            if(lmax > arr[start]){
                ans += lmax -arr[start];
            }else{
                lmax = arr[start];
            }
            start++;
        }
        if(index<end ){
            if(rmax>arr[end]){
                ans += rmax-arr[end];
            }else{
                rmax = arr[end];
            }
            end--;
        }
    }
    cout<<ans;
}