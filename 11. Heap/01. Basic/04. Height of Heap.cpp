#include<iostream>
using namespace std;

// here we have to find height of Heap
// Heap is always balanced so we can easily find its height using
// its size, we have to just find that how many of 2 multiples in the size 
// means, if size is 8 then there are 3 multiples -- 2 * 2 * 2;

// Link: https://www.geeksforgeeks.org/problems/height-of-heap5025/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Heap&sortBy=submissions
// time complexity = O(logn);
// space complexity = O(1)

int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6, 7, 8};

    int n = arr.size();
    int height = 0;

    if (n == 1){
        cout<<height;
        return 1;
    }

    while(n > 1){
        n /= 2;
        height++;
    }

    cout<<height;
}