#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> &nums, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1]) // nums[j] < nums[j + 1]    =>    To sort in decreasing order
            {
                swap(nums[j], nums[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            return nums;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    vector<int> x = bubble_sort(nums, n);

    for (int j : x)
    {
        cout << j << " ";
    }

    cout << endl;
    return 0;
}