#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> vec; // 0

    // for pushing at the back
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(46);
    vec.push_back(47);
    vec.push_back(48);
    vec.push_back(43);
    vec.push_back(42);

    // for popping out the last element
    vec.pop_back();
    vec.pop_back();

    vec.emplace_back(5); // look in the notes for this one 

    // vec[2] == vec.at(2)

    // front and back elements
    cout << vec.front() << endl; // 1
    cout << vec.back() << endl; // 5 

    // copy vector
    vector <int> copy_vec(3, 10); // means a copy vector of size = 3 and each value is 10; more useful in dp - tabulation

    // if we want to initialize vec2 elements with elements of vec1 then
    vector <int> vec1(4, 5);
    vector <int> vec2(vec1);

    // ☝🏻 all are easy O(1) TC operationsn

    // 👇🏻 all are heavy O(n) TC opertions

    // 1. delete()
    vec.erase(vec.begin());
    vec.erase(vec.begin() + 2);
    vec.erase(vec.begin() + 1, vec.begin() + 3); // vec.erase(start, end); end not included
    // Erase changes the size of vector but capacity is same (untouched)

    // 2. insert(position, value)
    vec.insert(vec.begin() + 2, 100);

    // 3. clear and empty
    vec.clear();
    cout << "Is Vector Empty? " << vec.empty() << endl;

    return 0;
}