// Leetcode #7 (Medium)

#include <iostream>
#include <cmath>
using namespace std;

int reverse(int x){
    if(x == INT_MIN) return 0;  // checks for min possible value of signed int

    int actualNum = x;
    int absNum = std::abs(x);
    long long revNum = 0;   // to prevent overflow

    while(absNum > 0){
        int lastDigit = absNum % 10;
        revNum = (revNum * 10) + lastDigit;
        absNum = absNum / 10;
    }

    if(revNum > INT_MAX)    return 0;   // to not let 64 bit num come

    if(actualNum < 0)   return -revNum;
    else    return revNum;
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
    return 0;
}