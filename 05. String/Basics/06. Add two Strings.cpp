#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// here we have to add two strings numbers
// we start adding string from the last like we do in normal addition
// pick the last number add them and forward carry to next one

string add(string num1, string num2){
    string ans;
    int sum = 0;
    int carry = 0;
    int first = num1.size() - 1;
    int second = num2.size() - 1;

    while (second >= 0)
    {
        // first we have to add the numbers
        sum = (num1[first] - '0') + (num2[second] - '0') + carry;
        carry = sum/10;
        ans += (sum % 10) + '0';
        first--;second--; 
    }


    // this loop will run for remaing values
    // what if, the length of num1 is greater that num2 
    // then first loop will run till only the num2 length 
    while(first >= 0){
        sum = (num1[first] - '0') + carry;
        carry = sum / 10;
        ans += (sum % 10) + '0';
        first--;
    }

    // what if both the numbers have same length 
    // and after adding them one carry remains 
    // ex: '999' + '999', then we remain one carry left 
    // by our logic it gonna be '098' but the answer is '1098'
    // so we add the carry to our ans 
    // # Carry value cant be greater than 1
    if(carry){
        ans += '1';
    }
    
    reverse(ans.begin(), ans.end());
    cout<<"Ans:"<<ans;
    return ans;
}

int main()
{
    string num1 = "11";
    string num2 = "123";

    // check if num1 is greater than or not 
    if (num1.size() > num2.size()){
        add(num1, num2);
    }else{
        add(num2, num1);
    }
 
}