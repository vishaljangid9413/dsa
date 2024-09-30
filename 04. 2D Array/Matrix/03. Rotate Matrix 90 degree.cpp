#include <iostream>
using namespace std;

// We can not use any dynamic value at the time of giving
// size to array ex = arr[row][col] instead arr[row][col]
// because it gives the unusual output 
// so to prevent this we have to convert this row and col into
// constexpr, which make them a constant variables 

int main(){
    int arr[4][4] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int row = 4, col =4;

    // First Transpose a Matrix 
    for (int i=0;i<row-1;i++){
        for(int j=i+1;j<row;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // and then reverse the row 
    for (int i=0;i<col;i++){
        int start = 0,end = row-1;
        while(start<end){
            swap(arr[i][start],arr[i][end]);
            start++;end--;
        }
    }

    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}   