#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>>arr= {{9,1,7},{8,9,2},{3,4,6}};
    int row = arr.size(),col = arr[0].size();
    int n = row*col;
    vector<int>ans(2,0);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]--;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int value= arr[i][j] % n;
            int row_index = value/col;
            int col_index = value%col;
            arr[row_index][col_index] +=n;
        }
    }


    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int occ = arr[i][j]/n;
            int index = i * col + j;
            if(occ == 0){
                ans[1] = index + 1;
                cout<<"Missing: "<<index+1<<endl;
            }else if(occ ==2){
                ans[0] = index + 1;
                cout<<"Duplicate: "<<index+1<<endl;
            }
        }
    }
}