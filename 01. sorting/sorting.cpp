#include <iostream>
using namespace std;


void selection_sort(int arr[], int n){
    // In selection sort, we always look for the smallest elment in right
    // and then swap with the current elemtn 
    for (int i=0;i<n-1;i++){
        int index =i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        if(index != i){
            swap(arr[i],arr[index]);
        }
    }
}

void bubble_sort(int arr[], int n){
    // In bubble sort, we check that current element is greater than the next tuple_element
    // and if it then swap them, this will going to place the largest element at the 
    // end of the array

    for (int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
}

void insertion_sort(int arr[], int n){
    // Insertion sorting is just similar to bubble sort we move
    // the largest elements in the right, but here we moves the 
    // smallest element in the left, in bubble_sort second loop 
    // run till j<n-i-1, but in insertion we start reverse loop j = i;j>0

    for (int i=1;i<n;i++){
        for(int j =i;j>0;j--){
            if (arr[j-1] > arr[j]){
                swap(arr[j-1],arr[j]);
            }else{
                break;
            }
        }
    }
}

int main(){
    int arr[] = {9,7,3,1,6};
    int n = size(arr);
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}