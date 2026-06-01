#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Brute Force Approach -> Complexity => O(n^2)
// void majority_element(vector<int> &nums)
// {
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;

//         for (int j = 0; j < n; j++)
//         {
//             if (nums[i] == nums[j])
//                 count++;
//         }

//         if (count > n / 2)
//         {
//             cout << "Majority element is " << nums[i] << endl;
//             return;
//         }
//     }

//     cout << "No majority element found" << endl;
// }

// 2. Optimized way is first sort the array -> Complexity => O(nlogn + n) = O(nlogn)
// int majority_element(vector<int> &nums)
// {
//     int frequency = 1, n = nums.size(), ans = nums[0];
//     std::sort(nums.begin(), nums.end());

//     for (int i = 1; i < n; i++)
//     {
//         if (nums[i] == nums[i - 1])
//         {
//             frequency++;
//         }
//         else
//         {
//             frequency = 1;
//             ans = nums[i];
//         }
//         if (frequency > n / 2)
//         {
//             return ans;
//         }
//     }
//     return ans;
// }

// 3. Moore's Algorithms -> Best Approach
int majority_element(vector<int> &nums)
{
    int frequency = 0;
    int answer = 0;

    for (int num : nums)
    {
        if (frequency == 0)
        {
            answer = num;
            frequency = 1;
        }
        else if (num == answer)
        {
            frequency++;
        }
        else
        {
            frequency--;
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = {3, 3, 4};
    cout << majority_element(nums) << endl;
    return 0;
}