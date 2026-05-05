#include <iostream>
using namespace std;

int main()
{
    int i, count, sum, oddSum, evenSum;
    i = 1;
    sum = 0;
    oddSum = 0;
    evenSum = 0;

    cout << "Enter number ";
    cin >> count;

    // While loop
    while (i <= count)
    {
        cout << i << endl;
        i++;
    }

    cout << "For loop" << endl;

    // For loop
    for (i = 1; i <= count; i++)
    {
        cout << i << endl;
    }

    cout << "Sum of numbers" << endl;

    // Reset i before reuse
    i = 1;

    while (i <= count)
    {
        sum += i;
        i++;
    }

    cout << "Total sum = " << sum << endl;

    sum = 0;

    for (i = 1; i <= count; i++)
    {
        sum += i;
    }

    cout << "Total sum = " << sum << endl;

    // seperate odd and even sum

    for (i = 1; i <= count; i++)
    {
        if (i % 2 == 0)
        {
            evenSum += i;
        }
        else
        {
            oddSum += i;
        }
    }

    cout << "Even sum is " << evenSum << endl;
    cout << "Odd sum is " << oddSum << endl;

    return 0;
}