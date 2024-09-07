#include <iostream>
using namespace std;

// Just apply a binary search to the assumed 1d array and 
// then just find the row_index and col_index from the appeard index 
// and then triverse the 2d array using row_index and col_index 
// Time_Complexit = O(log(row*col))

int main(){
    int arr[3][4] ={1,3,5,7, 10,11,16,20, 23,30,34,60};
    int row = 3, col =4, k=3,ans=-1,mid;
    int start = 0,end=(row * col)-1; 
    while (start <= end){
        mid = start + (end-start)/2;
        int row_index = mid / col;
        int col_index = mid % col;

        if (arr[row_index][col_index] == k){
            ans = 1;
            break;
        }else if(arr[row_index][col_index] < k){
            start = mid + 1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}   