#include <iostream>
using namespace std;

void sum_in_array(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum+=arr[i];
    }
    cout << "Sum of array elements is " << sum << endl;
}

int main()
{
    int arr[5];
    cout << "Enter numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    sum_in_array(arr);
    return 0;
}