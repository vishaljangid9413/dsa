#include <iostream>
#include <vector>
using namespace std;

// Here we have to find that the count of the longest substring, 
// which consists all the unique elements only

void first_approach(string s, int n){
    // This is my custom approach where 
    // i am just checking that is the current element already
    // stored in the array or not 
    // and if it is then just get the value of that element 
    // and the value represents its (index + 1) means 
    // where the element is stored in the string +1 of its index 
    // so it gives a value where we can shift our starting point  
    // then store the end+1 position on that element value 
    // and then just increase end++;
    // and every time at the ending of loop, store the max 
    // between ans and length of the current window 

    vector<int>arr(255,0);
    int start = 0, end = 0;
    int ans = 1;

    while(end < n){
        char c = s[end];
        if(arr[c] && start < arr[c]){
            start = arr[c];
        }
        arr[c] = end + 1;
        end++;
        ans = max(ans, end-start);
        cout<<start<<" "<<end<<" "<<c<<endl;
    }
    cout<<"Ans: "<<ans<<endl;
}

void second_approach(string s, int n){
    // Here we are first checking for that the 
    // character is present in the array
    // and then we loop through it while that its value will be 0
    // then begin the loop from the start index and store 0 to 
    // every index from the start and increase start++ 
    // and when the current repetative element will be 0
    // stop the loop 
    // and then store the 1 to the current element and 
    // then increase end++
    // and find the difference between end-start and store the 
    // max ans 

    vector<int>arr(255,0);

    int start = 0, end = 0;
    int ans =0;
    while(end<n){
        char c = s[end];
        while(arr[c]){
            arr[s[start]]=0;
            start++;
        }

        arr[c] = 1;
        end++;
        ans = max(ans, end-start);
    }
    cout<<"Ans: "<<ans;
}

int main(){
    string s = "abbannc";
    int n = s.size();

    first_approach(s,n);
    second_approach(s,n);

}