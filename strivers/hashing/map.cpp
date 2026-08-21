#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // precompute
    map<int, int> mpp;  // <int, int> means declaring the type of the key the value
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }

    // iterator
    // for(auto itr : mpp){
    //     cout << itr.first << "->" << itr.second << endl;
    // }
    // itr.first accesses key to the map pair and itr.second accesses the value of the map pair && this precomputation can be done in upper for loop also but it wont make much difference because its (N + N) and not (N * N)

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;

        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}