#include <iostream>
using namespace std;

// first we have to create a virtual array of  missing elements count
// formalua = arr[mid]-mid-1
// arr = {1,2,3,4,7,10,11,12}
// mis = {0,0,0,0,2,4 ,4 ,4}
// we dont have to create a array like this but just start a binary search
// and apply this formula on mid 
// and then compare the this new missing element with the k and
// search for that place where the missing element might be present 
// and remember search from the virtual array

// dont get confuse from the actual and virtual array 
// in real we are using actual array but the we are modifiyng the
// values of actual array and making a virtual array 

// and after finding the mid 
// then just add the mid with the k 


int main(){
    int arr[] ={1,2,3,4,7,10,11,12};
    int n = size(arr),k=5;
    int start = 0,end=n-1,mid,ans=n;
    while(start<=end){
        mid = start + (end-start)/2;
        int missing = arr[mid] - mid -1;
        if (missing < k){
            start = mid + 1;
        }else{
            ans = mid;                                                                          
            end = mid -1;
        }
    }
    cout<<(ans+k);

}