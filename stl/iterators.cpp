#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> vec = {1, 2, 3, 4, 5, 6, 7};

    cout << *(vec.begin()) << endl; // 1 is printed
    cout << *(vec.end()) << endl; // garbage value
    cout << *(vec.end() - 1) << endl; // 7 is printed

    // used in looping, with the help of this direct memory location can be accessed, also declare the type of the iterator too, it needs DEREFERENCING just like ptrs

    vector <int>::iterator itr; // forwards printing
    for(itr = vec.begin(); itr != vec.end(); itr++){
        cout << *(itr);
    }

    cout << endl;

    // reverse printing
    // here itr is a reverse printing variable and detected by c++ as initialized as auto
    // auto == vector <int>::iterator itr;
    for(auto itr = vec.rbegin(); itr != vec.rend(); itr++){
        cout << *(itr);

    }
    return 0;
}