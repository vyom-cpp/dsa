#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precompute
    // always take a single piece of size more in hashing
    int hash[13] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    // find the maximum and minimum frequencies
    int max_freq = INT32_MIN, min_freq = INT32_MAX;
    for(int i = 0; i < 13; i++){
        if(hash[i] > 0) {
            if (hash[i] > max_freq) {
                max_freq = hash[i];
            }
            // Check for min
            if (hash[i] < min_freq) {
                min_freq = hash[i];
            }
        }
    }

    cout << "Max Frequency: " << max_freq << endl << "Min Frequency: " << min_freq << endl;

    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;

        // fetch
        cout << hash[num] << endl;
    }

    return 0;
}