#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void reverseString(vector<char> &s){
    int start = 0, end = s.size() - 1;
    while(start < end){
        swap(s[start++], s[end--]); // swap(s[start], s[end]); start++; end--;
    }
}

int main() {
    vector<char> s = {'a', 'b', 'c', 'd'};

    reverseString(s);

    for(char ch : s){
        cout << ch << " ";
    }

    cout << endl;

    // other way
    string str = "vyom";
    reverse(str.begin(), str.end()); // iterators and much better then up above previous code 
    cout << str << endl;

    return 0;
}