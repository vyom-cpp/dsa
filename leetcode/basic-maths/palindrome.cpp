// Leetcode #9 (Easy)

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revNum = 0;
        while (x > revNum) {    // stops halfway while (x > 0) returns complete reverse of the number but here it stopping it halfway prevents overflow and it is widely used in plaindrome checking types
            int lastDigit = x % 10;
            revNum = (revNum * 10) + lastDigit;
            x = x / 10;
        }

        return x == revNum || x == revNum / 10;     // at the end of the loop x = 12 and revNum = 123 (12 > 123) => false and if (revNum / 10 == x); then the number is palindrome
    }


int main() {
    int n;
    cin >> n;
    cout << isPalindrome(n) << endl;
    return 0;
}