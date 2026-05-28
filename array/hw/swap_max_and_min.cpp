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

void swap(int num[], int max, int min)
{
    int maxIndex, minIndex;

    for (int i = 0; i < 5; i++)
    {
        if (num[i] == max)
        {
            maxIndex = i;
        }

        if (num[i] == min)
        {
            minIndex = i;
        }
    }

    int temp = num[maxIndex];
    num[maxIndex] = num[minIndex];
    num[minIndex] = temp;

    cout << "Array after swap: ";

    for (int i = 0; i < 5; i++)
    {
        cout << num[i] << " ";
    }
}

int main()
{
    int nums[5];

    cout << "Enter numbers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }

    int max = array_largest(nums);
    int min = array_smallest(nums);

    swap(nums, max, min);

    return 0;
}