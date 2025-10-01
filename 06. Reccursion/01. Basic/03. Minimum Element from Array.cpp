#include <iostream>
using namespace std;

int mini(int arr[], int n, int index){
    if(index == n - 1){
        return arr[index];
    }
    return min(arr[index], mini(arr, n, index + 1));
}

int main(){
    int arr[] = {4,5,2,67,1};
    int n = size(arr);

    cout<<mini(arr,n,0);
}