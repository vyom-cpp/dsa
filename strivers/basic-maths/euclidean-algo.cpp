#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int n1, int n2){
    for(int i = min(n1, n2); i >= 1; i--){
        if(n1 % i == 0 && n2 % i == 0){
            
            return i;
            break;
        }
    }
    return 1;
}   

int main() {
    int n1, n2;
    cout << "Enter numbers: ";
    cin >> n1 >> n2;
    gcd(n1, n2) == gcd(n1-n2, n2) ? cout << "Euclidean nums" << endl : cout << "Not Euclidean nums" << endl;
    return 0;
}