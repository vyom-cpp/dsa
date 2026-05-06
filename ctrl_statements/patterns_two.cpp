#include <iostream>
using namespace std;

int main()
{
    // triangle pattern
    int n;
    // int num;
    cout << "Enter number: ";
    cin >> n;
    // Numbers
    cout << "Numbers";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << i;
        }
        cout << endl;
    }

    // Stars
    cout << "Stars";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;

    // Characters
    cout << "Characters";
    cout << endl;
    // char ch='A';
    // for (int i = 1; i <= n; i++)
    // {
    //     // char ch = 'A';
    //     for (int j = 1; j <= i; j++)
    //     {
    //         char ch = 'A';
    //         cout << i;
    //         ch = ch + 1;
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;

        for (int j = 1; j <= i; j++)
        {
            cout << ch;
        }

        cout << endl;
    }
    return 0;
}