#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n1, n2;
    cout << "Enter numbers: ";
    cin >> n1 >> n2;

    for(int i = min(n1, n2); i >= 1; i--){
        if(n1 % i == 0 && n2 % i == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
