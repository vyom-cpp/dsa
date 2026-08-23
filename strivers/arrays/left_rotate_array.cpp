#include <iostream>
#include <algorithm>
using namespace std;

// brute
void left_rotate_once(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

// Just in case there is not reverse function allowed to be used
// void reverse(int arr[], int start, int end){
//     while(start < end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }


// better
// void left_rotate_d_places(int arr[], int n, int d){
//     d = d % n;
//     int temp[d];
//     for(int i = 0; i < d; i++){
//         temp[i] = arr[i];
//     }

//     // move the elements in array to left
//     for(int i = d; i < n; i++){
//         arr[i - d] = arr[i];
//     }

//     // put back temp elements at front
//     int j = 0;
//     for(int i = n-d; i < n; i++){
//         arr[i] = temp[j];
//         j++;
//     }
//     // if dont want to take another j variable
//     for(i = n - d; i < n; i++){
//          arr[i] = temp[i-(n-d)];
//     }
    
// }

// optimal
void left_rotate_d_places(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // left_rotate_once(arr, n);

    // for(int num : arr){
    //     cout << num << " ";
    // }

    left_rotate_d_places(arr, n, d);

    for(int nums : arr){
        cout << nums << " ";
    }

    return 0;
}