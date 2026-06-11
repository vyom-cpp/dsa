#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &shops, int n, int c, int minAllowedDistance)
{
    int cows = 1, lastStallPosition = shops[0];
    for (int i = 1; i < n; i++)
    {
        if (shops[i] - lastStallPosition >= minAllowedDistance)
        {
            cows++;
            lastStallPosition = shops[i];
        }

        if (cows == c)
        {
            return true;
        }
    }

    return false;
}

int aggressive_cows(vector<int> &shops, int n, int c)
{
    sort(shops.begin(), shops.end());

    int start = 1, end = shops[n - 1] - shops[0], ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(shops, n, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> shops = {1, 2, 8, 4, 9};
    int n = 5, c = 3;
    cout << aggressive_cows(shops, n, c) << endl;
    return 0;
}