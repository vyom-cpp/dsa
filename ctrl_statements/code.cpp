#include <iostream>
using namespace std;
int main()
{
    // number is postive or not using if else also taking input
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num >= 0)
    {
        cout << num << " is a postive number." << endl;
    }
    else
    {
        cout << num << " is a negative number." << endl;
    }

    // number is even or odd
    // int num2;
    // cout << "Enter the number: ";
    // cin >> num2;
    if (num % 2 == 0)
    {
        cout << num << " is even" << endl;
    }
    else
    {
        cout << num << " is odd" << endl;
    }

    // ternary way to check even or odd
    cout << num << " is " << (num%2==0? "even" : "odd") << endl;
    return 0;
}