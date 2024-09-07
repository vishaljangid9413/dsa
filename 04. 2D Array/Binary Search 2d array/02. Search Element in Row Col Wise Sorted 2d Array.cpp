#include <iostream>
using namespace std;

//Time Complexit = O(row+col);
int main(){
    int arr[3][5] ={4,7,15,25,60, 18,22,26,42,80, 36,40,50,68,104};
    int row = 3, col =5, target = 50;
    int row_index = 0, col_index = col -1;

    while (row_index < row && col_index >= 0){
        if(arr[row_index][col_index]==target){
            cout<<true;
            break;
        }else if(arr[row_index][col_index] < target){
            row_index++;
        }else{
            col_index--;
        }
    }

} 