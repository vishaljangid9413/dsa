#include <iostream>
using namespace std;

int main(){
    int x =8;
    int start = 0,end=x,ans=0,mid;
    if(x<2){
        cout<<x<<endl;
        return x;
    }

    while (start<=end){
        mid = start + (end-start)/2;
        if (mid ==x/mid){
            ans = mid;
            break;
        }
        else if (mid < x/mid){
            ans = mid;
            start = mid +1;
        }else{
            end = mid-1;
        }
    }
    cout<<ans;
}