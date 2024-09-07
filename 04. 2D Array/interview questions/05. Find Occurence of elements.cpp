#include <iostream>
using namespace std;

// We have to use same concept, that we have used in the previous question 
int main(){
    int arr[] = {3,2,5,3,1,2,3,7};
    int n = size(arr);

    // Decrease element by 1;
    for (int i=0;i<n;i++){
        arr[i]--;
    }

    for(int i=0;i<n;i++){
        int element = arr[i]%n;
        arr[element] += n;
    }

    for(int i=0;i<n;i++){
        int element = arr[i]%n;
        int occurence = arr[element]/n;
        cout<<"Occurence: "<<element+1<<" "<<occurence<<endl;
    }

}