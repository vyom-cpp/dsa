#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Numbers";
    cout << endl;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        int a = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << " " + i;
        }
        cout << endl;
    }

    cout << endl;


    cout << "Characters";
    cout << endl;

    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        ch = 'A' + i - 1;
        for (int j = i; j >= 1; j--)
        {
            cout << ch;
            ch--;
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}