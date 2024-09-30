#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> arr = {
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int row = arr.size(), col =arr[0].size();
    int index = -1;
    int row_index = 0,col_index = col-1;
    int count = 0, maxi=0;
    
    while(row_index < row && col_index >=0){
        // this condition tells that this row consists no zeroes 
        if(arr[row_index][0] == 1){
            index = row_index;
            cout<<index<<" "<<col-1;
            return 1;
        }else if(arr[row_index][col_index] ==1){
            count++;
            col_index--;
        }else{
            if (count > maxi){
                index = row_index;
                maxi = count;
            }
            count = 0;
            row_index++;
            col_index = col-1;
        }
    }
    cout<<index<<endl;
}