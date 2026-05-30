#include <iostream>
#include <vector>
using namespace std;

void reversee_array(int arr[])
{
    int i = 0, n = 4;
    while (i < n)
    {
        swap(arr[i], arr[n]);
        i++;
        n--;
    }
}


void reversee_vector(vector<int> &nums)
{
    int i = 0, size = nums.size() - 1;
    while (i < size)
    {
        swap(nums[i], nums[size]);
        i++;
        size--;
    }
}


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    vector<int> nums = {1, 2, 3, 4, 5}; 
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "Array Reversal: ";
    reversee_array(arr);
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }


    cout<< endl << "Vector Reversel: ";
    reversee_vector(nums); 
    for(int x : nums){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

// 1, 2, 3, 4, 5 (i = 0, n = 4)
// 5, 2, 3, 4, 1 (i = 1, n = 3)
// 5, 4, 3, 2, 1 (i = 2, n = 2) exit