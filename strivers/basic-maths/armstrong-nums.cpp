// If 371 => 3^3 + 7^3 + 1^3 == 371 then is it a armstrong num
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int actualNum = n, sum = 0;

    while(n > 0){
        int lastDigit = n % 10;
        sum = sum + (lastDigit * lastDigit * lastDigit);
        n = n / 10;
    }

    if(actualNum == sum)     cout << "Armstrong num" << endl;
    else    cout << "Not an armstrong num" << endl;

    return 0;
}