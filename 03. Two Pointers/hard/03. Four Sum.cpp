#include <iostream>
using namespace std;

int main(){
    int arr[]= {1,5,1,0,6,0};
    int n = size(arr), x=7;

    for (int i=0;i<n-1;i++){
        int index = i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        if(index != i){
            swap(arr[i],arr[index]);
        }
    }
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int temp =  x -arr[i] -arr[j];
            int start = j+1,end=n-1;
            while(start<end){
                cout<<"hello"<<endl;
                if(arr[start]+arr[end]==temp){
                    cout<<arr[start]<<" "<<arr[end]<<" "<<arr[i]<<" "<<arr[j]<<endl;
                    break;
                }else if(arr[start]+arr[end]<temp){
                    start++;
                }else{
                    end--;
                }
            }
        }   
    }
}