#include <iostream>
#include <algorithm>
using namespace std;

void reverse_array_with_recursion(int i, int arr[], int n){
    if(i >= n/2)    return;
    swap(arr[i], arr[n-i-1]);
    reverse_array_with_recursion(i+1, arr, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    reverse_array_with_recursion(0, arr, n);

    for(int i = 0; i < n; i++)  cout << arr[i] << " ";
    cout << endl;
    return 0;
}