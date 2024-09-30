#include <iostream>
using namespace std;

// Here we have given an array 
// that contains element (1 < arr[i] <n)
// means all the elements in array is lower than n 
// but there is a issue that in this there is only a duplicate
// element and only a missing element
// And below approaches only works with this pattern 
// where the size and range of element is given and only 
// contain one - one, duplicate and missing problem 


void first_approach(int arr[], int n){
    int new_arr[7] = {0};

    for (int i=0;i<n;i++){
        new_arr[arr[i]-1]++;
    }

    for (int i=0;i<n;i++){
        if (new_arr[i] == 2){
            cout<<"Duplicate: "<<i+1<<endl;
        }else if(new_arr[i] == 0){
            cout<<"Missing: "<<i+1<<endl;
        }
    }
}


void second_aproach(int arr[], int n){
// First we should decrease each element with 1
    // this will make them suitable to find the incremental element 
    for (int i=0;i<n;i++){
        arr[i]--;
    }

    // Now we have to give the occurence count of each element 
    // and also stores the (occurence + value) in a single position 
    for(int i=0;i<n;i++){
        int value = arr[i] % n;
        arr[value] += n;
        
        // First we have to find the original value

        // Here, we have to add the n to that value which 
        // is placed on index == current element .

        // Means we are storing the occurence of current element with 
        // that element which have the index == our current element 

        // Why we are not storing the occurence of an element with itself?
        // ex: while iteration if we get our first element 2 and we store its 
        // occurence by adding n to it, it means its occured one time.
        // after some iterations if we find 2 again and now we have to increase 
        // the occurence of 2 one more time then we are not able to fetch that 2
        // once again because we dont know the index of it 
        // and also 2 is in two places then there is other question
        //  that where we gonna be store its occurence. 
        // So that's why we are using that element which 
        // index == current element (after decreasing each element by 1), in this if 2 comes first time 
        // we just go to 2 index and add n to that element 
        // and after if we got another 2 then again we go to that increment element and add 7 to it.
        // Easy peasy.

    }

    for (int i=0;i<n;i++){
        int occurence = arr[i]/n;
        if (occurence == 2){
            cout<<"Duplicate: "<<i+1<<endl;
        }else if(occurence ==0){
            cout<<"Missing: "<<i+1<<endl;
        }
    }
}


int main(){
    int arr[] = {4,3,2,1,2,7,6};
    int n = 7;

    first_approach(arr,n);
    second_aproach(arr,n);    
}

