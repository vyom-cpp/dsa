#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    deque <int> l;

    l.push_back(1);
    l.emplace_back(2);
    l.push_front(3);
    l.emplace_front(4);

    l.pop_back();
    l.pop_front();
 
    for(int val : l){
        cout << val << " ";
    }

    cout << endl;
    // functions like size, erase, clear, begin, end, rbegin, rend, insert, front, back; all of them work on list the same way they do on vectors
    return 0;
}