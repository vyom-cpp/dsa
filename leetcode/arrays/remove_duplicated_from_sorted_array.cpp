#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int write = 1;

    for (int read = 1; read < nums.size(); read++)
    {
        if (nums[read] != nums[read - 1])
        {
            nums[write] = nums[read];
            write++;
        }
    }

    return write;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = removeDuplicates(nums);

    cout << "k = " << k << endl;

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

// Leetcode #26 (Easy)