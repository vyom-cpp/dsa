#include <iostream>
using namespace std;

void print_name(int i, int n){
    // bc
    if(i > n) return;
    cout << "A" << " ";
    print_name(i+1, n);
}

void print_one_to_n(int i, int n){
    // bc
    if(i > n) return;
    cout << i << " ";
    print_one_to_n(i+1, n);
}

void print_n_to_one(int i, int n){
    // bc
    if(i < 1) return;
    cout << i << " ";
    print_n_to_one(i - 1, n);
}

// using backtracking
void print_1_to_n(int i, int n){
    // bc
    if(i < 1)   return;
    print_1_to_n(i-1, n);
    cout << i << " ";
}

void print_n_to_1(int i, int n){
    // bc
    if(i > n)   return;
    print_n_to_1(i+1,n);
    cout << i << " ";
}

int main() {
    int n;
    cin >> n;
    // print_name(1, n);
    // print_one_to_n(1, n);
    // print_n_to_one(n, n);
    // print_1_to_n(n, n);
    print_n_to_1(1, n);
    return 0;
}