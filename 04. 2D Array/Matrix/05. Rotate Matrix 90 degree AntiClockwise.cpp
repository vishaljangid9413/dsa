#include <iostream>
using namespace std;

int main(){
    int arr[4][4] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int row = 4, col =4;
    
    for (int i=0;i<row;i++){
        for (int j=i+1;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    
    // reverse the columns
    int start= 0,end=row-1;
    while(start<end){
        for(int i=0;i<row;i++){
            swap(arr[start][i],arr[end][i]);
        }
        start++;end--;
    }

    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}   