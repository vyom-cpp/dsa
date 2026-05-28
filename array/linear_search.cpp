#include <iostream>
using namespace std;

void linear_search(int num[], int key)
{
    for (int i = 0; i < 5; i++)
    {
        if (num[i] == key)
        {
            cout << "Present at position " << i << endl;
            return;
        }
    }

    cout << "Not Found" << endl;
}

int main()
{
    int nums[5], key;

    cout << "Enter numbers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter key to search: ";
    cin >> key;

    linear_search(nums, key);

    return 0;
}