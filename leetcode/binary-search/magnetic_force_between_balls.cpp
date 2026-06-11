#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &position, int maxAllowedDistance, int m)
{
    int balls = 1, lastBallPosition = position[0], actualBalls = m;
    int n = position.size();
    for (int i = 1; i < n; i++)
    {
        if (position[i] - lastBallPosition >= maxAllowedDistance)
        {
            balls++;
            lastBallPosition = position[i];
        }

        if (balls == actualBalls)
        {
            return true;
        }
    }
    return false;
}

int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());
    int n = position.size();
    int start = 1, end = position[n - 1] - position[0], ans = -1; // end = position[4] - position[0] = 7 - 1 = 6;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // mid = 1 + ((6 - 1) / 2) = 3; position[mid] = 4;

        if (isPossible(position, mid, m))
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
    vector<int> position = {5, 4, 3, 2, 1, 1000000000};
    int balls = 2;
    cout << maxDistance(position, balls) << endl;
    return 0;
}

// #1552 (Medium)
