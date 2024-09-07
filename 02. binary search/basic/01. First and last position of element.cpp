#include <iostream>
using namespace std;

int first_position(int arr[], int n,int target){
    int start = 0, end = n-1,mid,ans=-1;
    while (start <=end){
        mid = start +(end-start)/2;
        if (arr[mid] == target){
            ans = mid;
            end = mid-1;
        }else if(arr[mid] >target){
            end =mid -1;
        }else{
            start = mid+1;
        }
    }
    return ans;

}

int second_position(int arr[], int n,int target){
    int start = 0, end = n-1,mid,ans=-1;
    while (start <=end){
        mid = start +(end-start)/2;
        if (arr[mid] == target){
            ans = mid;
            start = mid+1;
        }else if(arr[mid] < target){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[] ={5,7,7,8,8,10};
    int n= size(arr), target=6;
    int ans[2]={0};

    ans[0] = first_position(arr,n,target);
    ans[1] = second_position(arr,n,target);

    for (int i=0;i<2;i++){
        cout<<ans[i]<<" ";
    }

}