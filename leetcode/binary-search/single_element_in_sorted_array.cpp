#include <iostream>
#include <vector>
using namespace std;

int singleNonDupElement(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1, n = nums.size();
    if (n == 1)
        return nums[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // done to prevent the overflow
        if (mid == 0 && nums[0] != nums[1])
            return nums[mid];
        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[mid];

        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            return nums[mid];

        if (mid % 2 == 0)
        {
            // even part
            if (nums[mid - 1] == nums[mid])
            {
                end = mid - 1;  // left
            }
            else
            {
                start = mid + 1;    // right
            }
        } else {
            // odd part
             if (nums[mid - 1] == nums[mid])
            {
                start = mid + 1;    // right
            }
            else
            {
                end = mid - 1;  // left
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDupElement(nums) << endl;
    return 0;
}

// start = 0, end = 8; mid = 4; nums[4] = 3; ans = 2;
// in this the array will always be of size odd => (2n + 1)
// to go left; if nums[mid] == nums[mid - 1] then left part will be of odd size, so search in left part else in right part (if the right and left part of mid has even number of elements)
// to go left; if nums[mid] == nums[mid + 1] then right part will have all duplicated, so seach in left else in right part (if the right and left part of mid has odd number of elements)
// mid index is even then left and right part of mid will always be even and if mid index is off then left and right part of mid will always be odd