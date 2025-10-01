#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Here, we have a maze and a rat 
// rat wants to escape from the maze 
// and we have to analyze that how the rat 
// will escape from the maze and how many path 
// it takes to escapes and store all the paths 
// we just have to move our rat step by step 
// rat can move top, bottom, left, right 
// but there are some conditions:
// 1. rat should not move out of the maze means 
//     we should not move our index outside the array 
// 2. Rat should not move to the blocked place in maze 
//     means our array have some indexes 0, so we should 
//     move our rat only to non 0 values
// 3. Rat should not revisit the already visited path 
//     so we have to store the visited path and check 
//     every time that the next path is visited or not 

// time_complexity = O(3^n^2) means, 3 ki power n square


void maze(vector<vector<bool>>&arr, vector<vector<bool>>&temp, vector<string>&ans, string &path, int row, int col){
   int n = arr.size();
   if(row + col == n*2-2 ){
      ans.push_back(path);
      return;
   }

   // left 
   temp[row][col] = 1;
   if(col && !temp[row][col-1] && arr[row][col - 1]){
      path.push_back('L');
      maze(arr, temp, ans, path, row, col - 1);
      path.pop_back();
   }
   // right 
   if(col != n-1 && !temp[row][col+1] && arr[row][col + 1]){
      path.push_back('R');
      maze(arr, temp, ans, path, row, col + 1);
      path.pop_back();
   }
   // top 
   if(row && !temp[row-1][col] && arr[row-1][col]){
      path.push_back('T');
      maze(arr, temp, ans, path, row-1, col);
      path.pop_back();
   }
   // bottom 
   if(row != n-1 && !temp[row+1][col] && arr[row+1][col]){
      path.push_back('B');
      maze(arr, temp, ans, path, row+1, col);
      path.pop_back();
   }
   temp[row][col] = 0;
}

int main(){
   int n = 4;
   vector<vector<bool>>arr = {{1,0,0,0},{1,1,0,1},{1,1,1,1},{1,1,1,1}};
   vector<vector<bool>>temp(n, vector<bool>(n,0));
   vector<string>ans;
   string path;

   maze(arr, temp, ans, path, 0, 0);

   for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<endl;
   }
}