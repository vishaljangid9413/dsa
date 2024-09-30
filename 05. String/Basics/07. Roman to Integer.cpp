#include <iostream>
using namespace std;

int number(char c){
    if (c == 'I'){
        return 1;
    }else if (c == 'V'){
        return 5;
    }else if (c=='X'){
        return 10;
    }else if(c == 'L'){
        return 50;
    }else if(c == 'C'){
        return 100;
    }else if(c == 'D'){
        return 500;
    }else if(c == 'M'){
        return 1000;
    }
    return 0;
}

int main(){
        string st= "CDXLIII";
        int sum = 0;

    for (int i= 0;i<st.size()-1;i++){
        if (number(st[i]) < number(st[i+1])){
            sum -= number(st[i]);
        }else{
            sum += number(st[i]);
        }
    }
    sum += number(st[st.size()-1]);
    cout<<"Ans: "<<sum;
}