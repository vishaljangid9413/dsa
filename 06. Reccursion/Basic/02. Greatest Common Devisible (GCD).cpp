#include <iostream>
using namespace std;

// Here, we have to find that maximum common number
// that is devisible by both numbers

// Here, we are using Greedy algorithm 
// according to algorithm,
// lets, take example, a = 48, b = 18

// first find mode from, the greatest number 
//  a % b = 12
// now, find the modulus of second number using the mode we get 
// means now second becomes the first number and mode becomes the second number 
// till the mode become 0

// 18 % 12 = 6
// 12 % 6 = 0
// 6 % 0 = 0
// stop, now your ans is 6



int findGCD(int a, int b){
    if (b == 0){
        cout<<"Ans: "<<a;
        return a;
    }
    return findGCD(b, a % b);
}

int main(){
    int a = 48, b= 18;
    if (a >= b){
        findGCD(a, b);
    }else{
        findGCD(b,a);
    }
}