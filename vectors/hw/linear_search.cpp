#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> &nums, int key)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int key = 10;
    vector<int> nums = {2, 11, 10, 5, 3};

    int index = linear_search(nums, key);

    if (index != -1)
    {
        cout << "Key found at index: " << index << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    return 0;
}