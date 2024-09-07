#include <iostream>
#include <vector>
using namespace std;

// IN this questions we have to print a 2d array in the spiral like 
// structure ex:
// > > > > > >
// ^ > > > > V
// ^ ^ < < V V
// ^ < < < V V
// < < < < < V

// Consider the arrows as elements of an 2d array 

int main(){
    int arr[5][5] ={1,2,3,4,5, 6,7,8,9,10, 11,12,13,14,15, 16,17,18,19,20, 21,22,23,24,25};
    int top =0,bottom=4; //represent row index;
    int left = 0,right=4; //represent col index;
    vector<int> ans;

    while(top<=bottom && left<=right){
        // For left to right iteration
        for (int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        // For top to bottom iteration
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        // For right to left iteration
        if(top <= bottom){
            for(int i= right;i >= left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        // For bottom to top iteration
        if(left<=right){
            for(int i=bottom;i>= top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}   