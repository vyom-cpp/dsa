#include <iostream>
#include <vector>
using namespace std;

int rotated_binary_search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        if (nums[start] <= nums[mid])
        { // Left part sorted
            if (nums[start] <= target && target <= nums[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        { // Right part sorted
            if (nums[mid] <= target && target <= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target;                              
    cout << "Enter target: ";
    cin >> target;
    cout << rotated_binary_search(nums, target) << endl;
    return 0;
}