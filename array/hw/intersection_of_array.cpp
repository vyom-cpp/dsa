#include <iostream>
using namespace std;

int main()
{
    int arr1[5], arr2[5];

    cout << "Enter numbers of first array: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter numbers of second array: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> arr2[i];
    }

    cout << "Unique intersection elements are: ";

    for (int i = 0; i < 5; i++)
    {
        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (arr1[i] == arr1[k])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
        {
            continue;
        }

        for (int j = 0; j < 5; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
        }
    }

    cout << endl;

    return 0;
}