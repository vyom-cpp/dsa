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

// Kadane's Algorithm
// [3, -4, 5, 4, -1, 7, -8], maximum_sum = 15 {5, 4, -1, 7}
// Kadane's Algorithm says that negative value will always reduce the sum, so when the current sum becomes negative, make it zero and ignore the numbers making it less than zero, for eg; the sub array {3, -4} will make current_sum = -1, so elements {3, -4} are of no use