#include <iostream>
using namespace std;

// We have to find here max differnece between two elements 
// and remember a element can be subtracted from its right elements only 
// not from its left part or itself 

int main()
{
    int arr[] = {9,5,8,12,2,3,7,4};
    int n = size(arr);
    int maxi = INT_MIN,suffix=0;
    for(int i=n-2;i>=0;i--){
        suffix = max(suffix, arr[i+1]);
        maxi = max(suffix-arr[i], maxi);
    }
    cout<< maxi;
}