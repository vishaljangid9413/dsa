#include <iostream>
using namespace std;

void first_approach(int num){
    int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ch[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string ans;
    int index = 0;

    while(num > 0){
        if(num >= arr[index]){
            num -= arr[index];
            ans += ch[index];
        }else{
            index++;
        }
    }
    cout<<"Ans: "<<ans<<endl;

}

void second_approach(int num){
    string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string ths[]={"","M","MM","MMM"};
    string ans = ths[num/1000] + hrns[(num % 1000) / 100] + tens[(num % 100) /10] + ones[num % 10];
    cout<<"Ans: "<<ans;
}


int main(){
    int num = 3749;

    first_approach(num);
    second_approach(num);

}