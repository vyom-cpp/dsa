#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> vec = {'a', 'b', 'c', 'd'};
    for (char i : vec) // this i iss not for indexing and this is for each loop and the type of vector specified above and iterator i should be same, in this case it is <char>
    {
        cout << i << endl;
    }

    // Size
    cout << "Size of original vector is " << vec.size() << endl;

    // push_back() - adds element at the end
    vec.push_back('e');
    cout << "\nAfter push_back('e'):" << endl;
    for (char i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    // front() - returns first element
    cout << "\nFirst element (front): " << vec.front() << endl;

    // back() - returns last element
    cout << "Last element (back): " << vec.back() << endl;

    // at() - access element at a specific index
    cout << "Element at index 2: " << vec.at(2) << endl;

    // pop_back() - removes last element
    vec.pop_back();
    cout << "\nAfter pop_back():" << endl;
    for (char i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    // Size
    cout << "\nSize of modified vector is " << vec.size() << endl;
    cout << "\nCapacity of vector is " << vec.capacity() << endl;

    return 0;
}