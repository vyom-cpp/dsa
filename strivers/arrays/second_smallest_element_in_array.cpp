#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int smallest = INT16_MAX, secondSmallest = INT16_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && secondSmallest != smallest){
            secondSmallest = arr[i];
        }
    }

    if(secondSmallest == INT16_MAX) cout << "Second minimum does not exist" << endl;
    else cout << "Second smallest is " << secondSmallest << endl;

    return 0;
}