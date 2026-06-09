#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 1, end = arr.size() - 2;        // a cool optimization because out peak index will never be first or last value of the array
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] < arr[mid])       // mid is in left part and peak is in right part
        {
            start = mid + 1;
        }
        else        // mid is in right part and peak is in left part
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {0, 1, 0};
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}