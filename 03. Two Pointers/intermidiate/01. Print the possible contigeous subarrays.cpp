#include <iostream>
using namespace std;

// creates all the possible contigeous subarrays

int main()
{
    int arr[] = {2, 4, 5, 6};
    int n = size(arr);
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n - k; i++){
            cout <<" [";
            for (int j = 0; j <= k; j++){
                cout<<arr[i + j];
                if (j!=k){
                    cout<<", ";
                }
            }
            cout << "] ";
        }
        cout << endl;
    }
}