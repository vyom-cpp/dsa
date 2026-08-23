#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxVal = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++){

        if(arr[i] > maxVal) {
            secondLargest = maxVal;
            maxVal = arr[i];
        } 

        else if(arr[i] > secondLargest && arr[i] != maxVal) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        cout << "There is no distinct second largest element." << endl;
    } else {
        cout << "Second largest is " << secondLargest << endl;
    }

    return 0;
}