#include <iostream>
#include <algorithm>
using namespace std;

void bubbly_sort(int arr[], int n){
    for(int i = n - 1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }

        if(didSwap == 0)    break;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bubbly_sort(arr, n);

    for(int itr : arr){
        cout << itr << " ";
    }

    return 0;
}