#include <iostream>
using namespace std;

// bool power_of_two(int n)
// {
//     if (n <= 0)
//     {
//         return false;
//     }

//     for (int i = 1; i <= n; i *= 2)
//     {
//         if (i == n)
//         {
//             return true;
//         }
//     }

//     return false;
// }

bool power_of_two(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main()
{
    cout << power_of_two(31) << endl;
    return 0;
}