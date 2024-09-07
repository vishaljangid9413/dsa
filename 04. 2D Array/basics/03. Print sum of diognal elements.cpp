#include <iostream>
using namespace std;

// first_digonal = 
//  *
//     *
//         *
//             *
// second_digonal=
//             *
//         *
//     *
// *

int main(){
    int arr[4][4] ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    int row = 4,col=4;
    int first_diognal=0,second_diognal=0;
    for(int i=0;i<row;i++){
        first_diognal += arr[i][i];
        second_diognal += arr[i][col-i-1];
    }
}