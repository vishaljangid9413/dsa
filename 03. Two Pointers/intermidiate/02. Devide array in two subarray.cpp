#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3,4,-2,5,8,20,-10,8};
    int n = size(arr);
    int sum=0,lsum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    for(int i=0;i<n-1;i++){
        lsum+=arr[i];
        if(sum-lsum == lsum){
            cout<<"Ans: "<<lsum<<" "<<arr[i];
        }
    }

}