#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector of pair
    vector <pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};

    vec.push_back({4, 5}); // here we have to make pair to insert
    vec.emplace_back(5, 6); // emplace back creates inplace objects at the time of insertion

    for(pair<int, int> p : vec){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}