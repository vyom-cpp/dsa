#include <iostream>
using namespace std;

// 1. Paramterized way
void parameterized_way_sum(int i, int sum){
    if(i < 1){
        cout << sum << endl;
        return;
    } else {
        parameterized_way_sum(i-1, sum + i);
    }
}

// 2. Functional way
int functional_way_sum(int n){
    if(n == 0)  return 0;
    else    return n + functional_way_sum(n - 1);
}

int factorial(int n){
    if(n == 1 || n == 0) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    cin>>n;
    parameterized_way_sum(n, 0);
    cout << functional_way_sum(n) << endl;
    cout << factorial(5) << endl;
    return 0;
}