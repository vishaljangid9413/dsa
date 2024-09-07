#include <iostream>
using namespace std;

// Just check that you are on which part i am using mid element to find that
// i am on which part if the mid is lower than its next element or higher than its 
// previous element than you are on left side else on right side 
// and then just check for the prev< mid > next condition its your ans 

int main(){
    int arr[] = {2,4,6, 8,10,8,5};
    int n = size(arr);
    int start = 1,end = n-2,mid,ans=-1;
    if(n > 2){
        while (start<=end){
            mid = start + (end-start)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                ans = mid;
                break;
            }else if (arr[mid-1] < arr[mid]){
                start = mid+1;
            }else{
                end = mid- 1;
            }
        }
    }
    cout<<ans;
}