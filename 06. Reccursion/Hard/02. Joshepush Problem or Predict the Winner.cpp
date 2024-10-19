#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have a game where we have given a number 
// of person that are placed in a circle
// and question says that we have to eliminate 
// every kth person 
// ex: n=3,k=2 then starts with 1, skip 2, then elminiate 3
// now, start with 1, skips 2, 3 already elminiated, then eliminate 1
// now, only 2 left so 2 is winner 

// Question Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/


int winner_with_loop(vector<bool>&temp, int person,  int index, int count, int k){
   // This is solved with the while loop only 
   // we dont use recurssion here 
   // time_complexity = O(n^2);
   // space_complexity = O(n)

   int n = temp.size();
   while (person)
   {
      while(temp[index] == 1){
         index = (index + 1) % n;
      }

      if(temp[index] == 0){

         count++;
         if(count == k){
            temp[index] = 1;
            count = 0;
            person--;
            if(person == 0){
               return index+1;
            }
         }
      }
      index = (index + 1) % n;
   }
}

int winner_with_recurrsion(vector<bool>&temp, int person, int index, int count, int k){
   // This is my custom approach, with the recurrsion
   // Here we take no. of person remaining,
   // count: that checks how many persons have to skip
   // index: show the current index of person 
   // temp: that stores the person is eliminated or not 

   // so every time first we skips the persons accordint to value of k
   // and during this process we also skips the eliminated person 

   int n = temp.size();

   while(count<k){
      count++;
      index = (index + 1) % n;
      while(temp[index] == 1){
         index = (index + 1) % n;
      }
   }

   // and after this loop we reached to that person 
   // we have to eliminate and also decrease the count of person 
   temp[index] = 1;
   person--;

   // and if we dont remain any person alive 
   // then we just return the last person 
   // and here if index == 0 that means we have to 
   // declare winner to the last person 
   if (person == 0){
      if(index == 0){
         return n;
      }
      return index;
   }

   return winner_with_recurrsion(temp, person, index, 0, k);
}

int winner(int n, int k){
   // Here, we are using the most optimised approach, the Josephus Method 
   // every time we just decrease the size of the Circle 

   // time_complexity = O(n);
   // space_complexity = O(n)
   if (n == 1){
      return 0;
   }

   return (winner(n-1, k) + k) % n;
}

int main()
{
   int n = 3;
   int k = 1;
   if(k != n){ 
      k = k % n;
   }
   vector<bool> temp(n, 0);

   // cout<<winner_with_loop(temp, n, 0, 0, k);
   // cout<<winner_with_recurrsion(temp, n, 0, 0, k);
   cout<<winner(n, k)+1;
}