#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merging(vector<int> &arr, int low, int mid, int high);

void merge_sort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    
    int mid = low + (high - low) / 2; 
    
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merging(arr, low, mid, high);
}

void merging(vector<int> &arr, int low, int mid, int high){
    vector<int> tempArr;
    
    int left = low;
    int right = mid + 1;
    

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            tempArr.push_back(arr[left]);
            left++;
        } else {
            tempArr.push_back(arr[right]);
            right++;
        }
    }
    

    while(left <= mid){
        tempArr.push_back(arr[left]);
        left++;
    }
    

    while(right <= high){
        tempArr.push_back(arr[right]);
        right++;
    }
    

    for(int i = low; i <= high; i++){
        arr[i] = tempArr[i - low];
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    merge_sort(arr, 0, n - 1);
    

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
