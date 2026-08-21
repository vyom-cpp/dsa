#include <iostream>
#include <algorithm>
using namespace std;

int pivot(int arr[], int low, int high){
    int pivotVal = arr[low]; 
    int i = low, j = high;
    while(i < j){
        while(i <= high && arr[i] <= pivotVal) i++; 
        while(j >= low && arr[j] > pivotVal) j--;  
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = pivot(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int low = 0, high = n - 1;
    quickSort(arr, low, high);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
