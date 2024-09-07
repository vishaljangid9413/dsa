#include <iostream>
using namespace std;

// Here we also uses the Kedane's Algorithm
// this algorithm says that if sum of a contigoues
// sub array is negative then decline that array and
// continue to remaining elements 

int main()
{
    int arr[] = {3,4,-2,5,8,20,-10,8};
    int n = size(arr);
    int maxi = INT_MIN,prefix=0;
    for(int i= 0;i<n;i++){
        prefix+=arr[i];
        maxi= max(maxi,prefix);
        if(prefix < 0){
            prefix=0;
        }
    }
    return maxi;

}