#include <iostream>
using namespace std;

int decimal_to_binaryy(int n)
{
    int ans = 0, pow = 1, rem;
    while (n > 0)
    {
        rem = (n % 2);
        n = (n / 2);
        ans += (rem * pow);
        pow = (pow * 10);
    }
    return ans;
}

int binary_to_decimal(int n)
{
    int ans = 0, pow = 1, rem;
    while (n > 0)
    {
        rem = (n % 10);
        ans += (rem * pow);
        n = (n / 10);
        pow = (pow * 2);
    }
    return ans;
}

int main()
{
    cout << decimal_to_binaryy(7) << endl;
    cout << binary_to_decimal(111) << endl;
    return 0;
}