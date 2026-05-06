#include <iostream>
using namespace std;

int main()
{
    // square pattern
    int n;
    int num;
    cout << "Enter number: ";
    cin >> n;
    cout << "Enter number: ";
    cin >> num;

    // numbers
    cout << "Numbers" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j;
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << num;
            // ++num; Both prints same thing
            num++;
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // stars
    cout << "Stars" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // characters
    cout << "Character" << endl;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A'; // Inside the loop because after printing in first row, for second row it must be reinitialized
        for (int j = 1; j <= n; j++)
        {
            cout << ch;
            ch = ch + 1;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}