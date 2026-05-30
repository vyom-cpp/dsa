#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    int sum = 0;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);

    cout << "Single number is: ";
    for (int x : nums)
    {
        sum ^= x;
    }

    cout << sum << endl;
    return 0;
}