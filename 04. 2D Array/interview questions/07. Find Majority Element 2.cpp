#include <iostream>
#include <vector>
using namespace std;

// Here we have to find the majority element 
// and also verify that the majority element apperance count 
// is more than  n/3 it means max 2 majority element can exist;
// ex: if size of array is 7;
// so count of majority element must be <= (n/3+1)
// so, if one majority elemnt 
// remaining elements = (n/3 + 1) * 1 
//                     = 3*1 = 3
//                     = n -3 = 4
// lets, consider two,
// remaining_elements = (n/3 + 1) * 2
//                    = 3*2 = 6
//                    = n -6 = 2
// its not possible, so if the size is 7, only one majaority element is possible   
            
                

// And here we use "Boyer-Moore Majority Vote Algorithm"

int main(){
    int arr[]= {2,1,1,3,1,4,5,6};
    int n = size(arr);

    int candidate= 0,count = 0;
    int candidate1= 0,count1 = 0;

    for (int i=0;i<n;i++){
        if(count == 0 && candidate1 != arr[i]){
            count = 1;
            candidate = arr[i];
        }else if(count1 == 0 && candidate != arr[i]){
            count1 = 1;
            candidate1 = arr[i];
        }else if(candidate == arr[i]){
            count++;
        }else if(candidate1 == arr[i]){
            count1++;
        }else{
            count--;
            count1--;
        }
    }
    cout<<candidate<<" "<<candidate1<<endl;
    // verify 
    count=0,count1=0;
    for(int i=0;i<n;i++){
        if(candidate==arr[i]){
            count++;
        }else if(candidate1==arr[i]){
            count1++;
        }
    }

    vector<int>ans;
    if (count > n/3){
        ans.push_back(candidate);
    }
    if(count1>n/3){
        ans.push_back(candidate1);
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}