#include <iostream>
using namespace std;

void multiplication_in_array(int arr[])
{
    int multiplication = 1;
    for (int i = 0; i < 5; i++)
    {
        multiplication*=arr[i];
    }
    cout << "Multiplication of array elements is " << multiplication << endl;
}

int main()
{
    int arr[5];
    cout << "Enter numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    multiplication_in_array(arr);
    return 0;
}