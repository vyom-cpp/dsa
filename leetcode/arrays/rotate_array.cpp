#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate_array_left(int b[], int k, int n){
    k = k % n;
    reverse(b, b + k);
    reverse(b + k, b + n);
    reverse(b, b + n);
}

void rotate_vector_left(vector<int> a, int k){
    int n = a.size();
    k = k % n;
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
}

void rotate_array_right(int b[], int k, int n){
    k = k % n;
    reverse(b, b + n - k);
    reverse(b + n - k, b + n);
    reverse(b, b + n);
}

void rotate_vector_right(vector<int> a, int k){
    int n = a.size();
    k = k % n;
    reverse(a.begin(), a.begin() + n - k);
    reverse(a.begin() + n - k, a.end());
    reverse(a.begin(), a.end());
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    return 0;
}