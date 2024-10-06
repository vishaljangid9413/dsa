#include <iostream>
using namespace std;

int bs(int arr[], int start, int end, int target){
    if(start >= end){
        return -1;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] == target){
        return mid;
    }else if (arr[mid] < target){
        return bs(arr, mid + 1, end, target);
    }else{
        return bs(arr, start, mid - 1, target);
    }
}


int main(){
    int arr[] = {8, 11, 15, 22, 45, 46};
    int n = size(arr);
    int target = 45;

    int start = 0, end = n-1;
    cout<<bs(arr, start, end, target);
}