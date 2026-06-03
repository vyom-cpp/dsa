#include <iostream>
#include <vector>
using namespace std;

// 1. Brute Force Approach (Complexity -> O(n^2))
// int maxArea(vector<int> &height)
// {
//     int n = height.size(), maxWater = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int width = j - i;
//             int ht = min(height[i], height[j]);
//             int volume = width * ht;
//             maxWater = max(maxWater, volume);
//         }
//     }
//     return maxWater;
// }


// 2. Two Pointer Approach (Complexity -> O(n))
int maxArea(vector<int> &height)
{
    int lp = 0, rp = height.size() - 1, maxWater = 0, ht, width, currentWater;
    while (lp < rp)
    {
        ht = min(height[lp], height[rp]);
        width = rp - lp;
        currentWater = ht * width;
        maxWater = max(maxWater, currentWater);
        height[lp] < height[rp] ? lp++ : rp--;
    }
    return maxWater;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}