#include <iostream>
#include <algorithm>
using namespace std;

int maximum_consecutive_ones(int arr[], int n){
    int count = 0, maxi = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
            maxi = max(count, maxi);
        } else {
            count = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << maximum_consecutive_ones(arr, n) << endl;
    return 0;
}