#include <iostream>
using namespace std;

// There is a simple approach 
// we have to place every cow with the calculated distance
// what is the calcuation that the distance between each cow 
// is minimum of maximum distance we can give 
// means cows ko aise rakhna h ki wo dur bhi rahe apas me
// aur enough stalls me bhi place ho jaye
// simple si baat h ki me diye gayi stall ko pura use karo 
// aur cows ko jitne dur ho utna dur rakh saku aapas me 

// so we have to find that particular distance 
// if distance is more than we cant assign all the cows in the given stall
// and if the distance is less than we should increase the distance between cows 


bool is_possible(int arr[], int mid, int n, int k){
    // here at first stall we have to place a cow and record
    // posititon of the cow and the next cow should be placed 
    // according to the given distance and if the stalls fit to that distance 
    // then place the cow to that stall and store the position of that cow 
    int cows = 1;
    int position_of_cow = arr[0];
    for (int i= 1;i<n;i++){
        if(mid+position_of_cow <= arr[i] ){
            position_of_cow = arr[i];
            cows++;
        }
    }
    if(cows < k){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int arr[] ={10,1,2,7,5};
    int n = size(arr);

    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
 
    int start = 1, end = arr[n-1],ans,mid,k=3;

    while(start<=end){
        mid = start + (end-start)/2;
        bool possible = is_possible(arr,mid,n,k);
        if (possible == 1){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid-1;
        }
    }
    cout<<ans;
}