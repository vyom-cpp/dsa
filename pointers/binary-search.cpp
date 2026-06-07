#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &nums, int target)        // Iterative Code
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {-1, 0, 4, 5, 9, 12};
    int target;
    cout << "Enter the target: ";
    cin >> target;
    cout << binary_search(nums, target) << endl;
    return 0;
}