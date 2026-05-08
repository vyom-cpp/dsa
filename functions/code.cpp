#include <iostream>
using namespace std;

// returnType funName(type param1, type param2, type param3, ...){
//    do some work
// }

void helloPrint()
{
    cout << "hello\n";
}

int printHello()
{
    cout << "Hello \n";
    return 5;
}

int sumN(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int minimum(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int factorial(int n)
{
    int fact = 1;
    if (n < 0)
    {
        return false;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }
    }
    return fact;
}

int main()
{
    helloPrint();
    int val = printHello();
    cout << "Val is " << val << endl;
    cout << printHello() << endl;
    cout << "Sum is " << sumN(4) << endl;
    cout << "Minimum is " << minimum(3, 4) << endl;
    cout << "Factorial is " << factorial(-5) << endl;
    return 0;
}