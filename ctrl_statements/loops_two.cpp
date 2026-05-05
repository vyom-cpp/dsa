#include <iostream>
using namespace std;

int main()
{
    int i, num;
    bool isPrime = true;
    cout << "Enter num: ";
    cin >> num;
    // for (i = 2; i <= num - 1; i++) // checks even repeated times, complexity is O(n) while optimizing it becomes O(root(n))
    for (i = 2; i * i <= num; i++) // Better
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    if (isPrime)
    {
        cout << "It is prime\n";
    }
    else
    {
        cout << "Not prime\n";
    }
    return 0;
}