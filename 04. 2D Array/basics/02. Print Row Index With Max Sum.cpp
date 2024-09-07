#include <iostream>
using namespace std;

int main(){
    int arr[3][4] ={1,2,3,4,5,6,7,8,9,10,11,12};

    int row = 3,col=4;
    int sum=INT_MIN,index=-1;
    for(int i=0;i<row;i++){
        int total = 0;
        for(int j=0;j<col;j++){
            total+=arr[i][j];
        }  
        if(sum<total){
            sum = total;
            index = i;
        }     
    }
    cout<<"Ans: "<<sum<<" "<<index;

    
}