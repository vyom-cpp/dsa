#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;

    m["iTv"] = 100;
    m["iPhone"] = 50;
    m["iPad"] = 15; // output will be printed in lexicographical order

    for(auto p: m){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}