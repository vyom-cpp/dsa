#include <iostream>
#include <vector>
using namespace std;

// vector<int> twoSum(vector<int> &nums, int target)        It is a brute force approach -> Complexity is O(n^2) and works for sorted and unsorted array both
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }

//     return {};
// }

vector<int> twoSum(vector<int> &nums, int target) // works for sorted array -> Complexity is O(n)
{
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        int pair_sum = nums[i] + nums[j];

        if (pair_sum > target)
        {
            j--;
        }
        else if (pair_sum < target)
        {
            i++;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }

    return {};
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int num[4] = {1, 3, 4, 5};
    int target;
    cout << "Enter target sum: ";
    cin >> target;
    twoSum(nums, target);
    return 0;
}