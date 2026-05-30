#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    cout << "Elements: ";
    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}