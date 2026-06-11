#include <iostream>
#include <vector>
using namespace std;

int isValid(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        { // new painter
            painters++;
            time = arr[i];
        }
    }

    return painters <= m ? true : false;
}

int painter_partition(vector<int> &arr, int n, int m)
{
    int sum = 0, maxValue = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxValue = max(maxValue, arr[i]);
    }

    int start = maxValue, end = sum; // start = 40, end = 100
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2; // mid = 40 + 30 = 70

        if (isValid(arr, n, m, mid))
        {   // left
            ans = mid;
            end = mid - 1;
        }
        else
        {   // right
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;

    cout << painter_partition(arr, n, m) << endl;
    return 0;
}