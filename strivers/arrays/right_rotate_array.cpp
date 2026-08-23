#include <iostream>
#include <algorithm>
using namespace std;

// brute
void rotate_right_once(int arr[], int n){
    int temp = arr[n - 1];
    // shift elements in backward fashion to avoid the ovewriting
    for(int i = n - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

// better
// void rotate_right_d_places(int arr[], int n, int d){
//     d = d % n;
//     int temp[d];
//     for(int i = 0; i < d; i++){
//         temp[i] = arr[n - d + i];
//     }

//     // move the current elements side to make space for rotating elements
//     for (int i = n - 1; i >= d; i--) {  // select the places and move the elements
//         arr[i] = arr[i - d];
//     }

//     // move the temp elements to the front of array
//     int j = 0;
//     for(int i = 0; i < d; i++){ // select the places and move the element
//         arr[i] = temp[j];
//         j++;
//     }
// }

// optimal
void rotate_right_d_places(int arr[], int n, int d){
    reverse(arr + (n-d), arr + n);
    reverse(arr, arr + (n-d));
    reverse(arr, arr+n);
}

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // rotate_right_once(arr, n);
    rotate_right_d_places(arr, n, d);
    for(int num : arr){
        cout << num << " ";
    }

    return 0;
}