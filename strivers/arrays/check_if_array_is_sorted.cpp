#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Check if the array is sorted in ascending order
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]) {
            cout << "false" << endl; 
            return 0; // Exit the program safely
        }
    }

    cout << "true" << endl;
    return 0; 
}
