#include <iostream>
using namespace std;

int digitSum(int num)
{
    int sum = 0, lastDigit;
    while (num > 0)
    {
        lastDigit = num % 10;
        num = num / 10;
        sum = sum + lastDigit;
    }
    return sum;
}
int main()
{
    cout << digitSum(12340) << endl;
    return 0;
}