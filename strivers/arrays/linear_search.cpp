#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            return i;
        } 
    }
    return -1;
}

int main() {
    int n, key;
    cin >> n >> key;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << linearSearch(arr, key, n) << endl;
    return 0;
}