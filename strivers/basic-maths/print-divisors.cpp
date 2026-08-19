#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    // for(int i = 0; i <= n; i++){
    //     if(n % i == 0)
    //     cout << i << " ";
    // }

    // cout << endl;

    // current up above solution takes O(n) as time complexity, below is the optimized soution 
    vector <int> factors;
    for(int i = 0; i * i <= n; i++){
        if(n % i == 0){
            factors.push_back(i);
            if(n / i != i)  factors.push_back(n/i);
        }
    }

    sort(factors.begin(), factors.end());

    for(auto val: factors)
        cout << val << " ";

    cout << endl; 
    return 0;
}