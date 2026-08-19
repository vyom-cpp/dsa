#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int counter = 0;

    for(int i = 0; i * i <= n; i++){
        if(n % i == 0)  counter++;
            if((n/i) != i)  counter++;
        
    }

    if(counter == 2)    cout << "It is prime" << endl;
    else    cout << "It is not a prime" << endl;
    return 0;
}