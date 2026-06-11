#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    int ans = INT16_MAX;
    while (start <= end)
    {
        if (nums[start] <= nums[end])
        { // if whole array is sorted
            ans = min(ans, nums[start]);
            break;
        }

        int mid = start + (end - start) / 2;

        if (nums[start] <= nums[mid])
        { // it shows left part is sorted, store the current smallest and then check
            ans = min(ans, nums[start]);
            start = mid + 1;
        }
        else
        { // it shows right part is sorted, store the current smallest and then check
            ans = min(ans, nums[mid]);
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1};
    cout << findMin(nums) << endl;
    return 0;
}