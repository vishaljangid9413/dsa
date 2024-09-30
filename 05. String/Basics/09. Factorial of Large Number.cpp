#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Here we have to find the factorial of a large number
// but in many cases factorial of sum number is too large
// to store in the int and long long data type so 
// in that case we have to find something else to do this 

// so, the solution instead of storing the whole number in a single type 
// we just split it and store it into the array 

int main(){
    int n = 5;
    vector<int> ans(1,1);

    while(n > 1){
        int carry = 0,res = 0, size = ans.size();
        for(int i=0;i<size;i++){
            res = ans[i] * n + carry;
            carry = res/10;
            ans[i] = res % 10;
        }

        // if carry holds some value we have to devide it in single unit 
        // and store it 
        while(carry){
            ans.push_back(carry % 10);
            carry /= 10;
        }

        // decrease the number 
        n--;
    }

    // so the ans we got is in reverse order 
    // so we have to reverse it to get our actual ans 
    reverse(ans.begin(), ans.end());
    
    cout<<"Ans: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}