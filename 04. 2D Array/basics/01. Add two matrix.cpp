#include <iostream>
using namespace std;

int main(){
    int arr1[3][4] ={1,2,3,4,5,6,7,8,9,10,11,12};
    int arr2[3][4] ={0,1,2,3,4,5,6,7,8,9,10,11};
    int ans[3][4];

    int row = 3,col=4;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans[i][j]=arr1[i][j]+arr2[i][j];
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<ans[i][j]<<" ";
        }
    }

    
}