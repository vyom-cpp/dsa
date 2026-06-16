#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int> &nums, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < sz; j++)
        {
            if (nums[j] < nums[smallestIndex]) // nums[j] > nums[smallestIndex]    =>    decreasing oder
            {
                smallestIndex = j;
            }
        }
        swap(nums[i], nums[smallestIndex]);
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 4, 5, 2, 3};
    int sz = nums.size();
    vector<int> j = selection_sort(nums, sz);

    for (int x : j)
    {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}