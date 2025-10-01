#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here, we have an popular puzzle problem,
// in this we have given three road 
// and the first rod consists the N number of disks 
// so we have to transfer all the disk to third road 
// But we have some conditions:
// 1. All the transferred disk remains in thier position 
//     means disk remains in asending order, [1,2,3,4,5,6]
//     means smallest(top) to largest(bottom)
// 2. You can move one disk at a time 
// 3. You cannot place a larger disk on the top of a smaller one 

// In this we have to return the Number of steps we are taken to complete the task 
// And also prints the steps 

// In here we have a simple logic we have to calculate for its previous disk 
// means if we have 3 disk then we solve for 2 disk first  
//     and when we have 2 disks then we solve for 1 first 
//     and then return 

// Time Complexity = O(2^n - 1)
// Space Complexity = O(n)

void toh_cal(int n, int source, int helper, int destination){
    if(n == 1){
        cout<<"move disk "<<n<<" from rod "<<source<<" to "<<destination<<endl;
        return;
    }

    toh_cal(n-1, source, destination, helper);
    cout<<"move disk "<<n<<" from rod "<<source<<" to "<<destination<<endl;
    toh_cal(n-1, helper, source, destination);
}


int main(){
    int N = 3;
    int source = 1, helper = 2, destination = 3;

    toh_cal(N, source, helper, destination);

    // we just returns the steps 
    // because we already know that how many steps it will taken
    // No. of steps = Time Complexity
    cout<<(2^N)- 1;
    return (2^N)- 1;
}