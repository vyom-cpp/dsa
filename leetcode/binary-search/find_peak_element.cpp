#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            // Peak is on the right side
            start = mid + 1;
        }
        else
        {
            // Peak is at mid or on the left side
            end = mid;
        }
    }

    return start;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}

// # 162 (Medium)