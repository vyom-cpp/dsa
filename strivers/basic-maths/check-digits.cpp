#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int count = 0;

    while(n > 0){
        // int lastDigit = n % 10;
        count++;
        n = n / 10;
    }

    cout << "No. of digits are " << count << endl;
    return 0;
}