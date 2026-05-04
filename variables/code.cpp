#include <iostream>
using namespace std;

int main()
{
    int age = 25;

    cout << "john is a good boy" << endl;

    cout << "john is a good boy" << " chloe is also a good girl" << endl;

    cout << "john is a good boy" << endl
         << "chloe is also a good girl" << endl;

    // cout << "john is a good boy" << "\n"; better and faster than endl because endl also flushes the output buffer which can be time-consuming in some cases.

    cout << "john is " << age << " years old" << endl;

    cout << "john is " << "age" << " years old" << endl;

    cout << sizeof(age) << endl;

    // Type casting
    char grade = 'A';

    int value = grade; // Implicit type casting

    double price = 19.99;
    int newPrice = (int)price; // Explicit type casting

    cout << value << endl;
    cout << newPrice << endl;

    // Learning to take input from the user
    string name;
    cout << "Enter your name: ";
    cin >> name; // Take input

    cout << "Hello, " << name << "!" << endl;

    int a, b;
    float ans;
    cin >> a >> b;

    ans = a / b;        // Result will be in int
    ans = (float)a / b; // Type casting to get a float result
    cout << "The division of " << a << " and " << b << " is: " << ans << endl;

    // Some bool
    cout << (3 > 5) << endl; // Output will be 0 (false)
    cout << (3 < 5) << endl; // Output will be 1 (true)

    return 0;
}