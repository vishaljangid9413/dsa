#include <iostream>
using namespace std;

// Here, we have to find the number of ways that 
// we can climb the nth number of stairs
// and you can only tep 1 and 2 steps at one time 

// Ex: if it is 3 step ladder
// then, 
// 1 + 1 + 1, 1 + 2, 2 + 1
// so there are only three ways to do it 


// Here, we can find a pattern that no. of ways to climb for 
// each ladder step is sum of its previous two ladder steps
// like if 3 step ladder, then the total method will be
// climb(3-1)+climb(3-2)

int climb(int n){
    if(n <= 1){
        return 1;
    }
    return climb(n-1)+climb(n - 2);
}

int main(){
    int n = 4;

    cout<<"Ans: "<<(climb(n));

}