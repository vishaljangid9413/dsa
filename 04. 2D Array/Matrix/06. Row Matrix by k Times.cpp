#include <iostream>
using namespace std;

// In here we have to rotate the matrix according to input
// means if n = 3 then roate it to the 3 times 
// means simply, 90 * 3 = 270 degree 

int main(){
    int arr[4][4] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int row = 4, col =4, k=8;
    int rotate = k % 4;

    while (rotate){
        // First transpose matrix 
        for (int i=0;i<row;i++){
            for(int j= i+1;j<col;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        // Now reverse the row 
        for (int i=0;i<col;i++){
            int start = 0,end = row-1;
            while(start<end){
                swap(arr[i][start],arr[i][end]);
                start++;end--;
            }
        }
        rotate--;
    }

    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}   