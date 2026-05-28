#include <iostream>
using namespace std;

int main()
{
    int marks[5];
    cout << "Enter marks: ";
    for (int i = 0; i <= 4; i++)
    {
        cin >> marks[i];
    }

    cout << endl
         << "Printing marks: ";
    for (int i = 0; i <= 4; i++)
    {
        cout << " " << marks[i];
    }
    cout << endl;
    return 0;
}