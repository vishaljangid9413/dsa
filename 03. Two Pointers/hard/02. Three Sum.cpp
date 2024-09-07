#include <iostream>
using namespace std;

int main(){
    int arr[]={1,4,45,6,10,8};
    int n = size(arr);
    int x= 13;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int i=0;i<n-2;i++){
        int start=i+1,end=n-1;
        int temp = x-arr[i];
        while(start<end){
            if(arr[start]+arr[end]==temp){
                cout<<"True"<<endl;
                break;
            }else if(arr[start]+arr[end] < temp){
                start++;
            }else{
                end--;
            }
        }
    }
    cout <<"Fail";
}