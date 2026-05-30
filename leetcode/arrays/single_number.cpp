#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int ans = 0;

    for (int x : nums)
    {
        ans ^= x;
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}