#include <iostream>
#include <vector>
using namespace std;

int kadane_algorithm(vector<int> &nums)
{
    int current_sum = 0, max_sum = INT16_MIN;
    for (int val : nums)
    {
        current_sum += val;
        max_sum = max(current_sum, max_sum);
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << kadane_algorithm(nums) << endl;
    return 0;
}