#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int actualNum = n, revNum = 0;

    while(n > 0){
        int lastDigit  = n % 10;
        revNum = (revNum * 10) + lastDigit;
        n = n/10;
    }

    if(actualNum == revNum) cout << "This is a palindrome" << endl;
    else    cout << "Not a palindrome" << endl; 

    return 0;
}