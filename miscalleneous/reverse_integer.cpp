#include <iostream>
using namespace std;

int reverse_integer(int num)
{
    int ans = 0, pow = 1, rem;
    while (num > 0)
    {
        rem = num % 10;
        num = num / 10;
        ans = ans * 10 + rem;
    }
    return ans;
}

int main()
{
    cout << reverse_integer(65) << endl;
    return 0;
}
// 56 -> 65
// 56 % 10 = 6
// 6 * 10 = 60
// 56 / 10 = 5
// 5 % 10 = 5
// 60 + 5 = 65