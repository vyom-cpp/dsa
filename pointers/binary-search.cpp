#include <iostream>
#include <vector>
using namespace std;

// int binary_search(vector<int> &nums, int target)        // Iterative Code
// {
//     int left = 0;
//     int right = nums.size() - 1;

//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;

//         if (nums[mid] == target)
//         {
//             return mid;
//         }
//         else if (nums[mid] < target)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }

//     return -1;
// }

int binary_search(vector<int> &nums, int target, int start, int end) // Recursive Code
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (target > nums[mid])
        {
            return binary_search(nums, target, mid + 1, end);
        }
        else if (target < nums[mid])
        {
            return binary_search(nums, target, start, mid - 1);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1, 0, 4, 5, 9, 12, 13, 19, 21};
    int target, start = 0, end = nums.size() - 1;
    cout << "Enter the target: ";
    cin >> target;
    cout << binary_search(nums, target, start, end) << endl;
    return 0;
}