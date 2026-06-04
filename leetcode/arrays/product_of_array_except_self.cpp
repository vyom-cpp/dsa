#include <iostream>
#include <vector>
using namespace std;

// 1. Brute Force Approach (Complexity -> O(n^2))
// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> ans(n, 1);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j)
//             {
//                 ans[i] *= nums[j];
//             }
//         }
//     }
//     return ans;
// }

// 2. Optimal Approach
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = productExceptSelf(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

// nums = [1, 2, 3, 4] --> ans = [24, 12, 8, 6]