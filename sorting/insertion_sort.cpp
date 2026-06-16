#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> &nums, int sz)
{
    for (int i = 1; i < sz; i++)
    {
        int current = nums[i];
        int previous = i - 1;

        while (previous >= 0 && nums[previous] > current) // nums[previous] < current    =>    decreasing order
        {
            nums[previous + 1] = nums[previous];
            previous--;
        }
        nums[previous + 1] = current; // placing current element in its correct position
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 4, 5, 2, 3};
    int sz = nums.size();
    vector<int> j = insertion_sort(nums, sz);
    for (int x : j)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}