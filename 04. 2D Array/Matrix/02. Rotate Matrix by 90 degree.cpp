#include <iostream>
using namespace std;

// We can not use any dynamic value at the time of giving
// size to array ex = arr[row][col] instead arr[row][col]
// because it gives the unusual output 
// so to prevent this we have to convert this row and col into
// constexpr, which make them a constant variables 

int main(){
    constexpr int row = 4,col=4;
    int arr[row][col]= {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
    int new_arr[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            // new_arr[j][row-i-1] = arr[i][j];
            // cout<<"ARR: "<<i<<" "<<j<<" "<<arr[i][j]<<endl;
            // cout<<"SEC: "<<j<<" "<<(row-i-1)<<" "<<arr[j][row-i-1]<<endl<<endl;
            
            swap(arr[j][row-i-1],arr[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<new_arr[i][j]<<" ";
        }
        cout<<endl;
    }
}