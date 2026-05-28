#include <iostream>
using namespace std;

int array_largest(int num[])
{
    int largest = num[0];
    for (int i = 0; i < 5; i++)
    {
        if (largest < num[i])
        {
            largest = num[i];
        }
    }
    return largest;
}

int array_smallest(int num[])
{
    int smallest = num[0];
    for (int i = 0; i < 5; i++)
    {
        if (num[i] < smallest)
        {
            smallest = num[i];
        }
    }
    return smallest;
}

int main()
{
    int nums[5];
    cout << "Enter numbers: ";
    for (int i = 0; i <= 4; i++)
    {
        cin >> nums[i];
    }

    cout << "Largest of array is " << array_largest(nums) << endl;
    cout << "Smallest of array is " << array_smallest(nums) << endl;
    return 0;
}