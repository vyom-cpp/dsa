#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{
    int student = 1, pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxAllowedPages)
            return false;

        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            student++;
            pages = arr[i];
        }
    }

    return student > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int start = 0, end = sum, ans = -1; // range of possible answers

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(arr, n, m, mid))
        { // left
            ans = mid;
            end = mid - 1;
        }
        else
        { // right
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2;
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}

// arr (pages in books) = [2, 1, 3, 4]; 4 books; sutdents (M) = 2
// 1. S1 = 2 and S2 = 8 (max = 8)
// 2. S1 = 3 and S2 = 7 (max = 7)
// 3. S1 = 6 and S2 = 4 (max = 6) // ans, as the maximum is minimum
// O(nlogn)
// rewatch this video