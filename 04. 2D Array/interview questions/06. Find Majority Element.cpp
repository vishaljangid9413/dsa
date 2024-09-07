#include <iostream>
using namespace std;

// Here we have to find the majority element 
// and also verify that the majority element apperance count 
// is more than  n/2 it means only majority element can exist;

// And here we use "Boyer-Moore Majority Vote Algorithm"

int main(){
    int arr[]= {2,2,1,1,1};
    int n = size(arr);

    int candidate= 0,count = 0;
    for(int i = 0;i<n;i++){
        if (count == 0){
            count = 1;
            candidate = arr[i];
        }else{
            if (candidate == arr[i]){
                count++;
            }else{
                count--;
            }
        }
    }


    // verify
    count =0;
    for (int i=0;i<n;i++){
        if (candidate == arr[i]){
            count++;
        }
    }

    if(count > n/2){
        cout<<"Ans: "<<candidate<<" "<<1/3<<endl;
    }
    cout<<-1;
}