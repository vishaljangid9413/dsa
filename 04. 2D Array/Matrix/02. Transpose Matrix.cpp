#include <iostream>
using namespace std;

int main(){
    int arr[3][3] ={1,2,3,4,5,6,7,8,9};
    int row = 3, col =3;

    // int row = arr.size(),col=arr[0].size();
    for(int i=0;i<row-1;i++){
        for(int j=i+1;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}   