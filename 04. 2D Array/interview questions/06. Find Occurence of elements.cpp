#include <iostream>
using namespace std;

// We have to use same concept, that we have used in the previous question 
int main(){
    // "Using Boyre Moore  Majority Vote Algorithm"
    int arr[]= {2,2,1,1,1};
    int n = size(arr);

    int candidate= 0,count = 0;
    for(int i=0;i<n;i++){
        if(count >= 0){
            count= 1;
            candidate = arr[i];
        }else{
            if(arr[i] == candidate){
                count++;
            }else{
                count--;
            }
        }
    }

    count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==candidate){
            count++;
        }
    }

    if(count > n/2){
        cout<<"YES "<<candidate;
    }
}