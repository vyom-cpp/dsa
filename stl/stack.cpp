#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack <int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    // while(!s.empty()){
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    // cout << endl;

    stack<int> s2;

    cout << "Size of s before swapping " << s.size() << endl;

    s2.swap(s);

    cout << "Size of s after swapping " << s.size() << endl;
    cout << "Size of s2 after swapping " << s2.size() << endl;

    return 0;
}