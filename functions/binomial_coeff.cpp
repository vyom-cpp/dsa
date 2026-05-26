#include <iostream>
using namespace std;

// bool isPrime(int n)
// {
//     if (n <= 1)
//         return false;

//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }

//     return true;
// }

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) // nCr = n!/(r! * (n-r)!)
{
    int ans;
    int numerator = factorial(n);
    int denominator = factorial(r) * factorial(n - r);
    ans = numerator / denominator;
    return ans;
}

int main()
{
    // if (isPrime(7))
    //     cout << "Prime";
    // else
    //     cout << "Not Prime";

    cout << nCr(10, 0) << endl;

    return 0;
}