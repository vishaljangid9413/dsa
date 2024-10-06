#include <iostream>
#include<vector>
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


void merge(int arr[], int start, int mid, int end){
    // Its a helper function for merge_sort 
    // and it is the main function of merge sort 
    // which is used to sort the arrays and merge them 

    // We are creating a temp array to storing 
    // the sorted array temprorily
    vector<int> temp(end-start,0);
    int left = start, right = mid + 1, index = 0;
    
    // here we are sorting the array by deviding into two parts 
    // and storing it to temp array 
    // ex: ---
    //     first = [3,5,2], second = [1,4,2];
    //     we just comparing both of them by using left and right variables 
    //     and which one arrays element is smaller than storing 
    //     it to the temp array 
    // we are not actualy deviding the array we are just triversing the 
    // array like this using left and right, that appears that we are deviding it
    // but in actually we are just using its elements for comparisons
    //  and creating a new sorted array using temp array 

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index++] = arr[left++];
        }else{
            temp[index++] = arr[right++];
        }
    }

    // now imagine if both arrays does not have equal length 
    // so whichever will triverse first will break the loop 
    // so the another one remain untriversed 
    // and we also dont know which array is completely triversed and 
    // which is not, so we have to check for both of them 

    while(left <= mid){
        temp[index++] = arr[left++];
    }
    while(right <= end){
        temp[index++] = arr[right++];
    }

    // now we have get our sorted array now just copy the 
    // temp sorted array into the actual sorted array using the 
    // pointers start and end

    index = 0;
    while(start <= end){
        arr[start++] = temp[index++];
    }
}

void merge_sort(int arr[], int start, int end){
    // Merge Sort, works on devide,sort and merge rule,
    // in here we simply devide the array till the single element 
    // remains in the array and then sort them one by one 
    // we use recurrsion here 
    // And it is more faster than the previous sorting 
    // time complexity = O(nlogn)

    if(start == end) return;

    int mid = start + (end-start)/2;

    // left side 
    merge_sort(arr, start, mid);
    // right side 
    merge_sort(arr, mid + 1, end);
    // sorting and merging both sides 
    merge(arr, start, mid, end);
}


int partition(int arr[], int start, int end){
    // this is the main function do the functionality
    // of placing pivot element to its correct position and 
    // separte array 

    int position = start;
    while(start <= end){
        if(arr[start] <= arr[end]){
            swap(arr[start],arr[position]);
            position++;
        }
        start++;
    }
    return position - 1;
}

void quick_sort(int arr[], int start, int end){
    // Quick Sort, works on a technique that 
    // just pick the last element from the array and 
    // place it to its correct position in the array 
    // and make it pivot element 
    // now, put all the elements that are smaller from the pivot
    // element to the left and greater element element to right.

    // and then just repeat the same task to the both 
    // left and right part till the (start >= end)condition satisfy 
    if(start >= end){
        return;
    }

    int pivot = partition(arr, start, end);
    // left part -- consists smaller elements
    quick_sort(arr, start, pivot-1);
    // right part -- consists larger elements
    quick_sort(arr, pivot, end);
}


int main(){
    int arr[] = {9,7,3,1,6};
    int n = size(arr);
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // merge_sort(arr,0, n-1);
    // quick_sort(arr,0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

