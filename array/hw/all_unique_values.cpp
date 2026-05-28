#include <iostream>
using namespace std;

int main()
{
    int arr[5];

    cout << "Enter numbers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    cout << "Unique values are: ";

    for (int i = 0; i < 10; i++)
    {
        bool isDuplicate = false;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate)
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    return 0;
}