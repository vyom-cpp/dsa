#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nums[5] = {1, 2, 3, 4, 5};
    int size = 5;

    int max_sum = INT16_MIN;
    for (int start = 0; start < size; start++)
    {
        int current_sum = 0;
        for (int end = start; end < size; end++)
        {
            current_sum += nums[end];
            max_sum = max(max_sum, current_sum);
            // for (int i = start; i <= end; i++)
            // {
            //     cout << nums[i];
            // }
            // cout << " ";
        }
        // cout << endl;
    }
    cout << "Maximum sub array sum is: " << max_sum << endl;
    return 0;
}