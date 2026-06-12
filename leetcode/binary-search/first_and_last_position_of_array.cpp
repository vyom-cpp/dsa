#include <iostream>
#include <vector>
using namespace std;

int findFirst(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int firstIndex = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            firstIndex = mid;
            end = mid - 1; // keep searching left
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return firstIndex;
}

int findLast(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    int lastIndex = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            lastIndex = mid;
            start = mid + 1; // keep searching right
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return lastIndex;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {findFirst(nums, target), findLast(nums, target)};
}

int main()
{
    vector<int> nums = {5, 7, 7, 7, 7, 8};
    int target;
    cout << "Enter target: ";
    cin >> target;
    vector<int> x = searchRange(nums, target);
    for (int j : x)
    {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}

// Leetcode 54 (Binary Seach - Medium)