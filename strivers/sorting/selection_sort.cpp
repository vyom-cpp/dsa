#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] < arr[minIndex])  swap(arr[j], arr[minIndex]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    selection_sort(arr, n);

    for(int itr : arr){
        cout << itr << " ";
    }

    cout << endl;
    
    return 0;
}