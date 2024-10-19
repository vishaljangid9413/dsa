#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have given 2d array that consits some 
// characters and a string that consists a word 
// we have to find that does this 2d array's characters
// can make this word, match the given string
// return true or false 

// Although this solution is not correct we have to work on it 

bool search_word(vector<vector<char>>&arr, vector<vector<bool>>&temp, string word, int index, int row, int col){
   cout<<row<<" "<<col<<" "<<index<<endl;
   int n = arr.size();
   int m = arr[0].size();
   if(index == word.size()){
      cout<<"Return: "<<word.size()<<" "<<index<<endl;
      return true;
   }
   int point = index;
   int total = 0;
   temp[row][col] = 1;
   // left 
   if(col && !temp[row][col-1] ){
      cout<<"Left "<<row<<" "<<col<<" "<<arr[row][col-1]<<" "<<word[index]<<endl;
      if(arr[row][col - 1] == word[index]){
      total+=search_word(arr, temp, word, index+1, row, col - 1);
      }else{
      total+=search_word(arr, temp, word, 0, row, col - 1);
      }
   }
   // right 
   if(col != m-1 && !temp[row][col+1] ){
      cout<<"Right "<<row<<" "<<col<<" "<<arr[row][col+1]<<" "<<word[index]<<endl;
      if(arr[row][col + 1] == word[index]){
      total+=search_word(arr, temp, word, index+1, row, col + 1);
      }else{
      total+=search_word(arr, temp, word, 0, row, col + 1);
      }
   }
   // top 
   if(row && !temp[row-1][col] ){
      cout<<"Top "<<row<<" "<<col<<" "<<arr[row-1][col]<<" "<<word[index]<<endl;
      if(arr[row-1][col] == word[index]){
      total+=search_word(arr, temp, word, index+1, row-1, col);
      }else{
      total+=search_word(arr, temp, word, 0, row-1, col);
      }
   }
   // bottom 
   if(row != n-1 && !temp[row+1][col]){
      cout<<"Bottom "<<row<<" "<<col<<" "<<arr[row+1][col]<<" "<<word[index]<<endl;
      if(arr[row+1][col] == word[index]){
      total+=search_word(arr, temp, word, index+1, row+1, col);
      }else{
      total+=search_word(arr, temp, word, 0, row+1, col);
      }
   }
   temp[row][col] = 0;
   return total;
}

int main(){
   int row = 3, col = 4;
   vector<vector<char>>arr = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
   vector<vector<bool>>temp(row, vector<bool>(col,0));
   string word = "ABCB";
   int index = 0;
   if(arr[0][0] == word[0]){
      index++;
      temp[0][0] = 1;
   }
   cout<<search_word(arr, temp, word, index, 0, 0);

}