#include <iostream>
using namespace std;

// IN this questions we have to print a 2d array in the wave like 
// structure ex:
// *   * * *   *
// *   *   *   *
// *   *   *   *
// * * *   * * * 
// Consider the stars as elements of an 2d array 

int main(){
    int arr[3][4] ={1,2,3,4,5,6,7,8,9,10,11,12};
    int row = 3, col =4;

    for (int i=0;i<row;i++){
        for(int j = 0;j<col;j++){
            if(j % 2 ==0){
                cout<<arr[i][j]<<" ";
            }else{
                cout<<arr[row-i-1][j]<<" ";
            }
        }
        cout<<endl;
    }
}   